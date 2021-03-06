/*
   Drawpile - a collaborative drawing program.

   Copyright (C) 2006-2018 Calle Laakkonen

   Drawpile is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Drawpile is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Drawpile.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "canvas/canvasmodel.h"
#include "paintcore/layer.h"

#include "tools/selection.h"
#include "tools/toolcontroller.h"
#include "tools/utils.h"

#include <QPixmap>
#include <QtMath>
#include <QPolygonF>
#include <QTransform>
#include <QPainter>
#include "canvas/statetracker.h"
#include "canvas/canvasSelection.h"

namespace tools {

void SelectionTool::begin(const paintcore::Point &point, bool right, float zoom)
{
	Q_UNUSED(right);

	canvas::canvasSelection *sel = owner.model()->selection();
	if(sel)
		m_handle = sel->handleAt(point, zoom);
	else
		m_handle = canvas::canvasSelection::OUTSIDE;

	m_start = point;
	m_p1 = point;

	if(m_handle == canvas::canvasSelection::OUTSIDE) {
		if(sel) {
			owner.sendMessages(sel->pasteOrMoveToCanvas(owner.myId(), owner.activeLayer()));
			sel->detachMove();
		}

		sel = new canvas::canvasSelection;
		initSelection(sel);
		owner.model()->setSelection(sel);
	} else {
		sel->beginAdjustment(m_handle);
	}
}

void SelectionTool::motion(const paintcore::Point &point, bool constrain, bool center)
{
	canvas::canvasSelection *sel = owner.model()->selection();
	if(!sel)
		return;

	if(m_handle==canvas::canvasSelection::OUTSIDE) {
		newSelectionMotion(point, constrain, center);

	} else {
		const QPointF p = point - m_start;

		if(sel->pasteImage().isNull() && !owner.model()->stateTracker()->isLayerLocked(owner.activeLayer())) {
			startMove();
		}

		if(m_handle == canvas::canvasSelection::TRANSLATE && center) {
			// We use the center constraint during translation to rotate the selection
			const QPointF center = sel->boundingRect().center();

			if(constrain) {
				// center+constrain mode: shear
				sel->adjustShear(p.x() / 100.0, p.y() / 100.0);

			} else {
				// just the center: rotate
				double a0 = qAtan2(m_start.y() - center.y(), m_start.x() - center.x());
				double a1 = qAtan2(point.y() - center.y(), point.x() - center.x());

				sel->adjustRotation(a1-a0);
			}

		} else {
			sel->adjustGeometry(p.toPoint(), constrain);
		}
	}
}

void SelectionTool::end()
{
	canvas::canvasSelection *sel = owner.model()->selection();
	if(!sel)
		return;

	// Remove tiny selections
	QRectF selrect = sel->boundingRect();
	if(selrect.width() * selrect.height() <= 2) {
		owner.model()->setSelection(nullptr);
	} else {
		// Remove selections completely outside the canvas
		const QSize cs = owner.model()->layerStack()->size();
		if(selrect.right() <= 0 || selrect.left() >= cs.width() ||
				selrect.bottom() <= 0 || selrect.top() >= cs.height()) {
			owner.model()->setSelection(nullptr);
		}
	}
}

void SelectionTool::finishMultipart()
{
	canvas::canvasSelection *sel = owner.model()->selection();
	if(sel && !sel->pasteImage().isNull()) {
		owner.sendMessages(sel->pasteOrMoveToCanvas(owner.myId(), owner.activeLayer()));
		owner.model()->setSelection(nullptr);

	}
}

void SelectionTool::cancelMultipart()
{
	owner.model()->setSelection(nullptr);
}


void SelectionTool::undoMultipart()
{
	canvas::canvasSelection *sel = owner.model()->selection();
	if(sel) {
		if(sel->isTransformed())
			sel->reset();
		else
			cancelMultipart();
	}
}

bool SelectionTool::isMultipart() const
{
	return owner.model()->selection() != nullptr;
}

void SelectionTool::startMove()
{
	canvas::canvasSelection *sel = owner.model()->selection();
	paintcore::Layer *layer = owner.model()->layerStack()->getLayer(owner.activeLayer());
	if(sel && layer) {
		// Get the selection shape mask (needs to be done before the shape is overwritten by setMoveImage)
		QRect maskBounds;
		QImage eraseMask = sel->shapeMask(Qt::white, &maskBounds);

		// Copy layer content into move preview buffer.
		QImage img = owner.model()->selectionToImage(owner.activeLayer());
		sel->setMoveImage(img, owner.model()->layerStack()->size());

		// The actual canvas pixels aren't touch yet, so we create a temporary sublayer
		// to erase the selected region.
		layer->removeSublayer(-1);
		paintcore::Layer *tmplayer = layer->getSubLayer(-1, paintcore::BlendMode::MODE_ERASE, 255);
		tmplayer->putImage(maskBounds.left(), maskBounds.top(), eraseMask, paintcore::BlendMode::MODE_REPLACE);
	}
}

RectangleSelection::RectangleSelection(ToolController &owner)
	: SelectionTool(owner, SELECTION, QCursor(QPixmap(":cursors/select-rectangle.png"), 2, 2))
{
}

void RectangleSelection::initSelection(canvas::canvasSelection *selection)
{
	QPoint p = m_start.toPoint();
	selection->setShapeRect(QRect(p, p));
}

void RectangleSelection::newSelectionMotion(const paintcore::Point& point, bool constrain, bool center)
{
	QPointF p;
	if(constrain)
		p = constraints::square(m_start, point);
	else
		p = point;

	if(center)
		m_p1 = m_start - (p.toPoint() - m_start);
	else
		m_p1 = m_start;

	owner.model()->selection()->setShapeRect(QRectF(m_p1, p).normalized().toRect());
}

PolygonSelection::PolygonSelection(ToolController &owner)
	: SelectionTool(owner, POLYGONSELECTION, QCursor(QPixmap(":cursors/select-lasso.png"), 2, 29))
{
}

void PolygonSelection::initSelection(canvas::canvasSelection *selection)
{
	selection->setShape(QPolygonF({ m_start }));
}

void PolygonSelection::newSelectionMotion(const paintcore::Point &point, bool constrain, bool center)
{
	Q_UNUSED(constrain);
	Q_UNUSED(center);

	Q_ASSERT(owner.model()->selection());
	owner.model()->selection()->addPointToShape(point);
}

void PolygonSelection::end()
{
	if(owner.model()->selection())
		owner.model()->selection()->closeShape();

	SelectionTool::end();
}

QImage SelectionTool::transformSelectionImage(const QImage &source, const QPolygon &target, QPoint *offset)
{
	Q_ASSERT(!source.isNull());
	Q_ASSERT(target.size() == 4);

	const QRect bounds = target.boundingRect();
	const QPolygonF srcPolygon({
		QPointF(0, 0),
		QPointF(source.width(), 0),
		QPointF(source.width(), source.height()),
		QPointF(0, source.height())
	});

	const QPolygon xTarget = target.translated(-bounds.topLeft());
	QTransform transform;
	if(!QTransform::quadToQuad(srcPolygon, xTarget, transform)) {
		qWarning("Couldn't transform selection image!");
		return QImage();
	}

	if(offset)
		*offset = bounds.topLeft();

	QImage out(bounds.size(), QImage::Format_ARGB32);
	out.fill(0);
	QPainter painter(&out);
	painter.setRenderHint(QPainter::SmoothPixmapTransform);
	painter.setTransform(transform);
	painter.drawImage(0, 0, source);

	return out;
}

QImage SelectionTool::shapeMask(const QColor &color, const QPolygonF &selection, QRect *maskBounds, bool mono)
{
	const QRectF bf = selection.boundingRect();
	const QRect b = bf.toRect();
	const QPolygonF p = selection.translated(-bf.topLeft());

	QImage mask(b.size(), mono ? QImage::Format_Mono : QImage::Format_ARGB32);
	memset(mask.bits(), 0, mask.byteCount()); // note: apparently image.fill() does not set every byte for monochrome images
	QPainter painter(&mask);
	painter.setPen(Qt::NoPen);
	painter.setBrush(color);
	painter.drawPolygon(p);

	if(maskBounds)
		*maskBounds = b;

	return mask;
}

}
