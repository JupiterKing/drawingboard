#include "canvasmodel.h"
#include "usercursormodel.h"
#include "lasertrailmodel.h"
#include "statetracker.h"
#include "layerlist.h""
#include "loader.h"

#include "paintcore/layerstack.h"
#include "paintcore/annotationmodel.h"
#include "paintcore/layer.h"
#include "net/meta2.h"
#include "canvasSelection.h"

#include <QSettings>
#include <QDebug>
#include <QPainter>

namespace canvas {

CanvasModel::CanvasModel(int localUserId, QObject *parent)
	: QObject(parent), m_selection(nullptr), m_mode(Mode::Offline)
{
	m_layerlist = new LayerListModel(this);
	m_layerstack = new paintcore::LayerStack(this);
	m_statetracker = new StateTracker(m_layerstack, m_layerlist, localUserId, this);
	m_usercursors = new UserCursorModel(this);
	m_lasers = new LaserTrailModel(this);  //光标

	m_layerlist->setMyId(localUserId);
	m_layerlist->setLayerGetter([this](int id)->paintcore::Layer* {
		return m_layerstack->getLayer(id);
	});

	connect(m_statetracker, &StateTracker::layerAutoselectRequest, this, &CanvasModel::layerAutoselectRequest); //连接后这是toolcontroler的setactivelayer

	connect(m_statetracker, &StateTracker::userMarkerAttribs, m_usercursors, &UserCursorModel::setCursorAttributes);
	connect(m_statetracker, &StateTracker::userMarkerMove, m_usercursors, &UserCursorModel::setCursorPosition);
	connect(m_statetracker, &StateTracker::userMarkerHide, m_usercursors, &UserCursorModel::hideCursor);

	connect(m_layerstack, &paintcore::LayerStack::resized, this, &CanvasModel::onCanvasResize); //画板大小变化
}

int CanvasModel::localUserId() const
{
	return m_statetracker->localId();
}

void CanvasModel::handleCommand(protocol::MessagePtr cmd)
{
	using namespace protocol;

	if(cmd->type() == protocol::MSG_INTERNAL) {  
		//如果是交互消息
		m_statetracker->receiveQueuedCommand(cmd);
		return;
	}

	//如果是元信息，只处理这三个
	if(cmd->isMeta()) 
	{
		switch(cmd->type())
		{
			case MSG_LASERTRAIL:
				metaLaserTrail(cmd.cast<protocol::LaserTrail>());
				break;
			case MSG_MOVEPOINTER:
				metaMovePointer(cmd.cast<MovePointer>());
				break;
			case MSG_LAYER_DEFAULT:
				metaDefaultLayer(cmd.cast<DefaultLayer>());
				break;
			default:
				qWarning("Unhandled meta message %s", qPrintable(cmd->messageName()));
		}

	} 
	else if(cmd->isCommand()) //主要的画笔，橡皮擦等的消息
	{
		// The state tracker handles all drawing commands
		m_statetracker->receiveQueuedCommand(cmd);
		emit canvasModified();

	} else {
		qWarning("CanvasModel::handleDrawingCommand: command %d is neither Meta nor Command type!", cmd->type());
	}
}

void CanvasModel::handleLocalCommand(protocol::MessagePtr cmd)
{
	m_statetracker->localCommand(cmd);
	emit canvasModified();
}

void CanvasModel::setStateTrakerDotline(bool bDotline)
{
	m_statetracker->setDotline(bDotline);
}

QImage CanvasModel::toImage() const
{
	// TODO include annotations or not?
	return m_layerstack->toFlatImage(false);
}

bool CanvasModel::needsOpenRaster() const
{
	return m_layerstack->layerCount() > 1 || !m_layerstack->annotations()->isEmpty();
}

QList<protocol::MessagePtr> CanvasModel::generateSnapshot(bool forceNew) const
{
	QList<protocol::MessagePtr> snapshot;

	if(!m_statetracker->hasFullHistory() || forceNew) {
		// Generate snapshot
		snapshot = SnapshotLoader(m_statetracker->localId(), m_layerstack, m_layerlist->getLayers(), this).loadInitCommands();

	} else {
		// Message stream contains (starts with) a snapshot: use it
		snapshot = m_statetracker->getHistory().toList();

		// Add default layer selection
		if(m_layerlist->defaultLayer() > 0)
			snapshot.prepend(protocol::MessagePtr(new protocol::DefaultLayer(m_statetracker->localId(), m_layerlist->defaultLayer())));
	}

	return snapshot;
}

void CanvasModel::pickLayer(int x, int y)
{
	const paintcore::Layer *l = m_layerstack->layerAt(x, y);
	if(l) {
		emit layerAutoselectRequest(l->id());
	}
}

void CanvasModel::pickColor(int x, int y, int layer, int diameter)
{
	QColor color;
	if(layer>0) {
		const paintcore::Layer *l = m_layerstack->getLayer(layer);
		if(layer)
			color = l->colorAt(x, y, diameter);
	} else {
		color = m_layerstack->colorAt(x, y, diameter);
	}

	if(color.isValid() && color.alpha()>0) {
		color.setAlpha(255);
		emit colorPicked(color);
	}
}

void CanvasModel::setLayerViewMode(int mode)
{
	m_layerstack->setViewMode(paintcore::LayerStack::ViewMode(mode));
	updateLayerViewOptions();
}

void CanvasModel::setSelection(canvasSelection *selection)
{
	if(m_selection != selection) {
		m_layerstack->removePreviews();

		const bool hadSelection = m_selection != nullptr;

		if(hadSelection && m_selection->parent() == this)
			m_selection->deleteLater();

		if(selection && !selection->parent())
			selection->setParent(this);

		m_selection = selection;

		emit selectionChanged(selection);
		if(hadSelection && !selection)
			emit selectionRemoved();
	}
}

void CanvasModel::updateLayerViewOptions()
{
	QSettings cfg;
	cfg.beginGroup("settings/animation");
	m_layerstack->setOnionskinMode(
		cfg.value("onionskinsbelow", 4).toInt(),
		cfg.value("onionskinsabove", 4).toInt(),
		cfg.value("onionskintint", true).toBool()
	);
//	m_layerstack->setViewBackgroundLayer(cfg.value("backgroundlayer", true).toBool());
    m_layerstack->setViewBackgroundLayer(false);

}

/**
 * @brief Find an unused annotation ID
 *
 * Find an annotation ID (for this user) that is currently not in use.
 * @return available ID or 0 if none found
 */
int CanvasModel::getAvailableAnnotationId() const
{
	const int prefix = m_statetracker->localId() << 8;
	QList<int> takenIds;
	for(const paintcore::Annotation &a : m_layerstack->annotations()->getAnnotations()) {
		if((a.id & 0xff00) == prefix)
				takenIds << a.id;
	}

	for(int i=0;i<256;++i) {
		int id = prefix | i;
		if(!takenIds.contains(id))
			return id;
	}

	return 0;
}

QImage CanvasModel::selectionToImage(int layerId) const
{
	QImage img;

	paintcore::Layer *layer = m_layerstack->getLayer(layerId);
	if(layer)
		img = layer->toImage();
	else
		img = toImage();


	if(m_selection) {
		img = img.copy(m_selection->boundingRect().intersected(QRect(0, 0, img.width(), img.height())));

		if(!m_selection->isAxisAlignedRectangle()) {
			// Mask out pixels outside the selection
			QPainter mp(&img);
			mp.setCompositionMode(QPainter::CompositionMode_DestinationIn);

			QRect maskBounds;
			const QImage mask = m_selection->shapeMask(Qt::white, &maskBounds);

			mp.drawImage(qMin(0, maskBounds.left()), qMin(0, maskBounds.top()), mask);
		}
	}

	return img;
}

void CanvasModel::pasteFromImage(const QImage &image, const QPoint &defaultPoint, bool forceDefault)
{
	QPoint center;
	if(m_selection && !forceDefault)
		center = m_selection->boundingRect().center();
	else
		center = defaultPoint;

	canvasSelection *paste = new canvasSelection;
	paste->setShapeRect(QRect(center.x() - image.width()/2, center.y() - image.height()/2, image.width(), image.height()));
	paste->setPasteImage(image);

	setSelection(paste);
}

void CanvasModel::onCanvasResize(int xoffset, int yoffset, const QSize &oldsize)
{
	Q_UNUSED(oldsize);

	// Adjust selection when new space was added to the left or top side
	// so it remains visually in the same place
	if(m_selection) {
		if(xoffset || yoffset) {
			QPoint offset(xoffset, yoffset);
			m_selection->translate(offset);
		}
	}
}

void CanvasModel::resetCanvas()
{
	setTitle(QString());
	m_layerlist->unlockAll();
	m_layerstack->reset();
	m_statetracker->reset();
}

void CanvasModel::metaLaserTrail(const protocol::LaserTrail &msg)
{
	m_lasers->startTrail(msg.contextId(), QColor::fromRgb(msg.color()), msg.persistence());
}

void CanvasModel::metaMovePointer(const protocol::MovePointer &msg)
{
	QPointF p(msg.x() / 4.0, msg.y() / 4.0);
	m_usercursors->setCursorPosition(msg.contextId(), p);
	m_lasers->addPoint(msg.contextId(), p);
}

void CanvasModel::metaDefaultLayer(const protocol::DefaultLayer &msg)
{
	m_layerlist->setDefaultLayer(msg.id());
	if(!m_statetracker->hasParticipated())
		emit layerAutoselectRequest(msg.id());
}


}
