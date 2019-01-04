#include "document.h"
#include "net/commands.h"
#include "canvas/canvasmodel.h"
#include "canvas/layerlist.h"
#include "canvas/loader.h"
#include "canvas/canvassaverrunnable.h"
#include "tools/toolcontroller.h"
#include "utils/settings.h"
#include "utils/images.h"

#include <QGuiApplication>
#include <QSettings>
#include <QTimer>
#include <QDir>
#include <QClipboard> //剪切板
#include <QThreadPool>

#include "../net/meta2.h"
#include "../net/undo.h"
#include "../net/layerMsg.h"
#include "../net/image.h"
#include "../net/annotationMsg.h"


Document::Document(QObject* parent /*= nullptr*/) :
	QObject(parent),
	m_canvas(nullptr),
	m_autoRecordOnConnect(false)
{
	m_toolctrl = new tools::ToolController(this);

}

Document::~Document()
{

}

QString Document::title() const
{
	return QString("aaa");
}

void Document::initCanvas()
{
	delete m_canvas;
	m_canvas = new canvas::CanvasModel(m_toolctrl->myId(), this);

	m_toolctrl->setModel(m_canvas);

	connect(m_toolctrl, &tools::ToolController::messageReceived, m_canvas, &canvas::CanvasModel::handleCommand);
	connect(m_toolctrl, &tools::ToolController::setDotline, m_canvas, &canvas::CanvasModel::setStateTrakerDotline); //设置是否为虚线
	//connect(m_canvas, &canvas::CanvasModel::canvasModified, this, &Document::markDirty);
	connect(m_canvas->layerlist(), &canvas::LayerListModel::layerCommand, m_toolctrl, &tools::ToolController::sendMessage);
	connect(qApp, SIGNAL(settingsChanged()), m_canvas, SLOT(updateLayerViewOptions()));

	connect(m_canvas->stateTracker(), &canvas::StateTracker::catchupProgress, this, &Document::catchupProgress);

	emit canvasChanged(m_canvas);

	setCurrentFilename(QString());
}

bool Document::loadCanvas(canvas::SessionLoader &loader)
{
	//初始化msg
	QList<protocol::MessagePtr> init = loader.loadInitCommands();

	if (init.isEmpty())
		return false;

	initCanvas();
	//m_client->sendResetMessages(init);
	if (m_toolctrl)
	{
		m_toolctrl->sendInitMessage(init); //初始化
	}
	setCurrentFilename(loader.filename());
	return true;
}

void Document::saveCanvas(const QString &filename)
{
	setCurrentFilename(filename);
	saveCanvas();
}

void Document::saveCanvas()
{
	auto *saver = new canvas::CanvasSaverRunnable(m_canvas, m_currentFilename);
	//	unmarkDirty();
	connect(saver, &canvas::CanvasSaverRunnable::saveComplete, this, &Document::onCanvasSaved);
	emit canvasSaveStarted();
	QThreadPool::globalInstance()->start(saver);
}

void Document::setCurrentFilename(const QString &filename)
{
	if (m_currentFilename != filename) {
		m_currentFilename = filename;
		emit currentFilenameChanged(filename);
	}
}

void Document::markDirty()
{
	/*bool wasDirty = m_dirty;
	m_dirty = true;
	if (m_autosave)
		autosave();

	if (!wasDirty)
		emit dirtyCanvas(m_dirty);*/
}

void Document::unmarkDirty()
{

}

void Document::autosaveNow()
{

}

void Document::copyFromLayer(int layer)
{
	if (!m_canvas) {
		qWarning("copyFromLayer: no canvas!");
		return;
	}

	QMimeData *data = new QMimeData;
	data->setImageData(m_canvas->selectionToImage(layer));

	// Store also original coordinates
	QPoint srcpos;
	if (m_canvas->selection()) {
		srcpos = m_canvas->selection()->boundingRect().center();

	}
	else {
		QSize s = m_canvas->layerStack()->size();
		srcpos = QPoint(s.width() / 2, s.height() / 2);
	}

	QByteArray srcbuf = QByteArray::number(srcpos.x()) + "," + QByteArray::number(srcpos.y());
	data->setData("x-drawpile/pastesrc", srcbuf);

	QGuiApplication::clipboard()->setMimeData(data);
}

QString Document::sessionTitle() const
{
	if (m_canvas)
		return m_canvas->title();
	else
		return QString();
}

void Document::sendPointerMove(const QPointF &point)
{
	m_toolctrl->sendMessage(protocol::MessagePtr(new protocol::MovePointer(m_toolctrl->myId(), point.x() * 4, point.y() * 4)));

}

void Document::sendResizeCanvas(int top, int right, int bottom, int left)
{
	QList<protocol::MessagePtr> msgs;
	msgs << protocol::MessagePtr(new protocol::UndoPoint(m_toolctrl->myId()));
	msgs << protocol::MessagePtr(new protocol::CanvasResize(m_toolctrl->myId(), top, right, bottom, left));
	m_toolctrl->sendMessages(msgs);
}

void Document::undo()
{
	if (!m_canvas)
		return;

	if (!m_toolctrl->undoMultipartDrawing())
		m_toolctrl->sendMessage(protocol::MessagePtr(new protocol::Undo(m_toolctrl->myId(), 0, false)));
}

void Document::redo()
{
	if (!m_canvas)
		return;

	if (!m_toolctrl->undoMultipartDrawing())
		m_toolctrl->sendMessage(protocol::MessagePtr(new protocol::Undo(m_toolctrl->myId(), 0, true)));  //true 为redo
}

void Document::selectAll()
{
	if (!m_canvas)
		return;

	canvas::canvasSelection *selection = new canvas::canvasSelection;
	selection->setShapeRect(QRect(QPoint(), m_canvas->layerStack()->size()));
	m_canvas->setSelection(selection);
}

void Document::selectNone()
{
	if (m_canvas && m_canvas->selection()) {
		m_toolctrl->sendMessages(m_canvas->selection()->pasteOrMoveToCanvas(m_toolctrl->myId(), m_toolctrl->activeLayer()));
		cancelSelection();
	}
}

void Document::cancelSelection()
{
	if (m_canvas)
		m_canvas->setSelection(nullptr);
}

void Document::copyVisible()
{
	copyFromLayer(0);
}

void Document::copyLayer()
{
	copyFromLayer(m_toolctrl->activeLayer());
}

void Document::cutLayer()
{
	if (m_canvas) {
		copyFromLayer(m_toolctrl->activeLayer());
		fillArea(Qt::white, paintcore::BlendMode::MODE_ERASE);
		m_canvas->setSelection(nullptr);
	}
}

void Document::pasteImage(const QImage &image, const QPoint &point, bool forcePoint)
{
	if (!m_canvas) {
		canvas::QImageCanvasLoader loader(image);
		loadCanvas(loader);

	}
	else {
		m_canvas->pasteFromImage(image, point, forcePoint);
	}
}

void Document::stamp()
{
	canvas::canvasSelection *sel = m_canvas ? m_canvas->selection() : nullptr;
	if (sel && !sel->pasteImage().isNull()) {
		m_toolctrl->sendMessages(sel->pasteOrMoveToCanvas(m_toolctrl->myId(), m_toolctrl->activeLayer()));
		sel->detachMove();
	}
}

void Document::removeEmptyAnnotations()
{
	if (!m_canvas) {
		qWarning("removeEmptyAnnotations(): no canvas");
		return;
	}

	QList<int> ids = m_canvas->layerStack()->annotations()->getEmptyIds();
	if (!ids.isEmpty()) {
		QList<protocol::MessagePtr> msgs;
		msgs << protocol::MessagePtr(new protocol::UndoPoint(m_toolctrl->myId()));
		for (int id : ids)
			msgs << protocol::MessagePtr(new protocol::AnnotationDelete(m_toolctrl->myId(), id));
		m_toolctrl->sendMessages(msgs);
	}
}

void Document::fillArea(const QColor &color, paintcore::BlendMode::Mode mode)
{
	if (!m_canvas) {
		qWarning("fillArea: no canvas!");
		return;
	}
	if (m_canvas->selection() && !m_canvas->stateTracker()->isLayerLocked(m_toolctrl->activeLayer())) {
		m_toolctrl->sendMessages(m_canvas->selection()->fillCanvas(m_toolctrl->myId(), color, mode, m_toolctrl->activeLayer()));
	}
}

void Document::snapshotNeeded()
{

}

void Document::onCanvasSaved(const QString &errorMessage)
{
	emit canvasSaved(errorMessage);
}
