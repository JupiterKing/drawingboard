#include <QApplication>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QSettings>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QUrl>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QProgressDialog>
#include <QCloseEvent>
#include <QPushButton>
#include <QToolButton>
#include <QImageReader>
#include <QImageWriter>
#include <QSplitter>
#include <QClipboard>
#include <QFile>
#include <QWindow>
#include <QVBoxLayout>
#include <QTimer>

#ifndef NDEBUG
#include "paintcore/tile.h"
#endif

#include "document.h"
#include "boardwidget.h"

#include "paintcore/layerstack.h"
#include "canvas/loader.h"
#include "canvas/canvasmodel.h"
#include "drawingboard/canvasview.h"
#include "drawingboard/canvasscene.h"
#include "drawingboard/selectionitem.h"
#include "canvas/statetracker.h"
#include "utils/icon.h"
#include "utils/images.h"
#include "utils/settings.h"
#include "net/commands.h"
#include "canvas/layerlist.h"
#include "tools/toolcontroller.h"
#include "net/annotationMsg.h"
#include "net/undo.h"

namespace {

	QString getLastPath() {
		QFileInfo fi(QSettings().value("window/lastpath").toString());
		return fi.absoluteDir().absolutePath();
	}

	void setLastPath(const QString &lastpath) {
		QSettings cfg;
		cfg.setValue("window/lastpath", lastpath);
	}

}


BoardWidget::BoardWidget(QWidget* parent /*= nullptr*/):
	DrawingBoard(parent),
	m_canvasscene(nullptr),
	m_view(nullptr),
	m_iSize(2),
	m_color(Qt::red)
{
	m_doc = new Document(this);
	connect(this, SIGNAL(signal_open()), this, SLOT(open()));
	connect(this, &BoardWidget::signal_undo, m_doc, &Document::undo);
	connect(this, &BoardWidget::signal_redo, m_doc, &Document::redo);

	connect(this, &BoardWidget::signal_expandup, this, [this] { m_doc->sendResizeCanvas(64, 0, 0, 0); });
	connect(this, &BoardWidget::signal_expandright, this, [this] { m_doc->sendResizeCanvas(0, 64, 0, 0); });
	connect(this, &BoardWidget::signal_expanddown, this, [this] { m_doc->sendResizeCanvas(0, 0, 64, 0); });
	connect(this, &BoardWidget::signal_expandleft, this, [this] { m_doc->sendResizeCanvas(0, 0, 0, 64); });
	connect(this, &BoardWidget::signal_clearArea, this, &BoardWidget::clearOrDelete);
	connect(this, &BoardWidget::signal_fillArea, this, [this](QColor color)
	{ 
		m_doc->fillArea(color, paintcore::BlendMode::MODE_NORMAL);
	});

	connect(this, &BoardWidget::signal_toolChanged, this, &BoardWidget::toolChanged);

	connect(m_doc, &Document::canvasChanged, this, &BoardWidget::onCanvasChanged);
	connect(m_doc, &Document::canvasSaveStarted, this, &BoardWidget::onCanvasSaveStarted);
	connect(m_doc, &Document::canvasSaved, this, &BoardWidget::onCanvasSaved);
	connect(m_doc, &Document::dirtyCanvas, this, &BoardWidget::setWindowModified);
	connect(m_doc, &Document::autoResetTooLarge, this, [this](int maxSize) 
	{
		auto *msgbox = new QMessageBox(
			QMessageBox::Warning,
			tr("Server out of space"),
			tr("Server is running out of history space and session has grown too large to automatically reset! (Limit is %1 MB)\nSimplify the canvas and reset manually before space runs out.")
			.arg(maxSize / double(1024 * 1024), 0, 'f', 2),
			QMessageBox::Ok,
			this
		);
		msgbox->show();
	});

	// Create canvas view
	m_view = new widgets::CanvasView(this);

	KisCubicCurve defaultPressureCurve;  //默认的压感曲线
	defaultPressureCurve.fromString("0,0;0.0349794,0.0717822;0.105848,0.0907353;0.205837,0.109142;0.329745,0.321319;0.437506,0.61487;0.610961,0.855278;1,1;");
	PressureMapping m_pressuremapping;
	m_pressuremapping.curve = defaultPressureCurve;
	m_pressuremapping.mode = PressureMapping::STYLUS;
	m_view->setPressureMapping(m_pressuremapping);
	
	// Create canvas scene
	m_canvasscene = new drawingboard::CanvasScene(this);
	m_canvasscene->setBackgroundBrush(
		palette().brush(QPalette::Active, QPalette::Window));
	m_view->setCanvas(m_canvasscene);
	m_view->setOutlineSize(10);

	connect(m_view, &widgets::CanvasView::pointerMoved, m_doc, &Document::sendPointerMove);
	connect(this, SIGNAL(signal_zoomin()),  m_view, SLOT(zoomin()));
	connect(this, SIGNAL(signal_zoomout()),  m_view, SLOT(zoomout()));
	connect(this, &BoardWidget::signal_zoom, this, [&](qreal izoomrate) { m_view->setZoom(izoomrate); });
	connect(this, &BoardWidget::signal_zoomorig, this, [&]() { m_view->setZoom(100.0); });
	connect(this, &BoardWidget::signal_rotateorig, this, [&]() { m_view->setRotation(0); });
	connect(this, &BoardWidget::signal_rotatecw, this, [&]() { m_view->setRotation(m_view->rotation() + 90); });
	connect(this, &BoardWidget::signal_rotateccw, this, [&]() { m_view->setRotation(m_view->rotation() - 90); });
	connect(this, &BoardWidget::signal_rotate90, this, [&]() { m_view->setRotation(90); });
	connect(this, &BoardWidget::signal_rotate180, this, [&]() { m_view->setRotation(180); });
	connect(this, &BoardWidget::signal_rotate270, this, [&]() { m_view->setRotation(270); });
	connect(this, SIGNAL(signal_viewflip(bool)), m_view, SLOT(setViewFlip(bool)));
	connect(this, SIGNAL(signal_viewmirror(bool)), m_view, SLOT(setViewMirror(bool)));
	connect(this, SIGNAL(signal_brushsize(int)), m_view, SLOT(setOutlineSize(int)));
	connect(this, &BoardWidget::signal_brushsize, this, [&](int iSize)
	{
		paintcore::Brush brush = m_doc->toolCtrl()->activeBrush();
		brush.setSize(m_iSize);
		brush.setColor(m_color);
		m_doc->toolCtrl()->setActiveBrush(brush);
	});
	connect(this, SIGNAL(signal_textsize(int)), m_view, SLOT(setOutlineSize(int)));

	//connect(this, SIGNAL(signal_showannotations(bool)), this, SLOT(setShowAnnotations(bool)));
	connect(this, SIGNAL(signal_showuserlayers(bool)), m_canvasscene, SLOT(showUserLayers(bool)));
	//connect(this, SIGNAL(signal_showlasers(bool)), this, SLOT(setShowLaserTrails(bool)));

	// Tool controller <-> UI connections
	connect(m_doc->toolCtrl(), &tools::ToolController::activeAnnotationChanged, m_canvasscene, &drawingboard::CanvasScene::activeAnnotationChanged);
	m_doc->toolCtrl()->setSmoothing(6);
	connect(m_doc->toolCtrl(), &tools::ToolController::toolCursorChanged, m_view, &widgets::CanvasView::setToolCursor);
	m_view->setToolCursor(m_doc->toolCtrl()->activeToolCursor());

	connect(m_view, &widgets::CanvasView::penDown, m_doc->toolCtrl(), &tools::ToolController::startDrawing);
	connect(m_view, &widgets::CanvasView::penMove, m_doc->toolCtrl(), &tools::ToolController::continueDrawing);
	connect(m_view, &widgets::CanvasView::penHover, m_doc->toolCtrl(), &tools::ToolController::hoverDrawing);
	connect(m_view, &widgets::CanvasView::penUp, m_doc->toolCtrl(), &tools::ToolController::endDrawing);
	

	updateTabletSupportMode();


	setDrawingToolsEnabled(false);

	//show();
}

BoardWidget::~BoardWidget()
{

}

//////////////////////////////////////////////////////////////////////////
void BoardWidget::operation_open()
{
	//m_image.load("C:\\Users\\Public\\Pictures\\Sample Pictures\\111.jpg");
	//operation_load(m_image);
	emit signal_open();
}

void BoardWidget::operation_load(const QImage& img)
{
	//加载QImage图片作为画布背景
	canvas::QImageCanvasLoader icl(img);
	loadDocument(icl);
}

void BoardWidget::operation_undo()
{
	emit signal_undo();
}

void BoardWidget::operation_redo()
{
	emit signal_redo();
}

void BoardWidget::operation_mouseCheck()
{
	//选择鼠标，修改一下光标
	QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
	emit signal_toolChanged(tools::Tool::MOUSETOOL); //什么工具也不选择
}

void BoardWidget::operation_pensize(int iSize)
{
	emit signal_toolChanged(tools::Tool::FREEHAND);
	m_iSize = iSize;
	emit signal_brushsize(iSize);
}

void BoardWidget::operation_text(int iFontSize)
{
	emit signal_toolChanged(tools::Tool::ANNOTATION);
	emit signal_textsize(iFontSize);
}

void BoardWidget::operation_shape(ShapeType eType)
{
	switch (eType)
	{
		case LINE:
		{
			emit signal_toolChanged(tools::Tool::LINE);
		}
		break;
		case DOTLINE:
		{
			emit signal_toolChanged(tools::Tool::DOTLINE);
		}
		break;
		case ARROW:
		{
			emit signal_toolChanged(tools::Tool::ARROW);
		}
		break;
		case RECTANGLE:
		{
			emit signal_toolChanged(tools::Tool::RECTANGLE);
		}
		break;
		case ELLIPSE:
		{
			emit signal_toolChanged(tools::Tool::ELLIPSE);
		}
		break;
	}
	
}

void BoardWidget::operation_color(QColor color)
{
	m_color = color;
	emit signal_brushsize(m_iSize);
}

void BoardWidget::operation_eraser(int iSize)
{
	emit signal_toolChanged(tools::Tool::ERASER);
	m_iSize = iSize;
	m_color = Qt::white;
	emit signal_brushsize(iSize);
}

void BoardWidget::operation_decal()
{
	emit signal_toolChanged(tools::Tool::PICKER);
}

void BoardWidget::operation_clearArea()
{
	emit signal_clearArea();
}

void BoardWidget::operation_fillArea(QColor color)
{
	emit signal_toolChanged(tools::Tool::FLOODFILL);
	emit signal_fillArea(color);
}

void BoardWidget::operation_expand(ExpandDirection direction)
{
	qreal rotate = m_view->rotation();
	int count = rotate / 90;
	count = count % 4;
	int iType;
	if (count > 0)
	{
		iType =(((int)direction + 4) - count) % 4;
	}
	else if (count < 0)
	{
		iType = ((int)direction - count) % 4;
	}
	else {
		iType = direction;
	}
	switch (iType)
	{
	case UP: { emit signal_expandup(); }break;
	case RIGHT: { emit signal_expandright(); }break;
	case DOWN: { emit signal_expanddown(); }break;
	case LEFT: { emit signal_expandleft(); }break;
	}
}

void BoardWidget::operation_rotation(RotationDirecton direction)
{
	switch (direction)
	{
	case CLOCKWISE:
		emit signal_rotatecw(); //顺时针
		break;
	case ANTICLOCKWISE:
		emit signal_rotateccw(); //逆时针
		break;
	}
}

void BoardWidget::operation_zoom(qreal izoomrate)
{
	if (izoomrate >= 80.0 && izoomrate <= 150.0)
	{
		emit signal_zoom(izoomrate);
	}
}

void BoardWidget::operation_save(QImage& img)
{
	QString filename = QString("C:\\aaa.png");
	save(filename);
	img.load(filename);
}

void BoardWidget::operation_screenshots()
{

}

//////////////////////////////////////////////////////////////////////////
BoardWidget* BoardWidget::loadDocument(canvas::SessionLoader &loader)
{
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

	if (!m_doc->loadCanvas(loader)) {
		QApplication::restoreOverrideCursor();
		QMessageBox::warning(0, QApplication::tr("loadDocument--error"), loader.warningMessage());
		return nullptr;
	}

	if (!loader.warningMessage().isEmpty()) {
		QMessageBox::warning(0, QApplication::tr("Warning"), loader.warningMessage());
	}

	QApplication::restoreOverrideCursor();
	setDrawingToolsEnabled(true);
	return this;
}

void BoardWidget::exit()
{
	//writeSettings();
	deleteLater();
}

void BoardWidget::resizeEvent(QResizeEvent *event)
{
	if (m_view != nullptr)
	{
		m_view->resize(event->size());
	}
}

void BoardWidget::showNew()
{

}

void BoardWidget::open()
{
	// Get a list of supported formats
	QString dpimages = "*.ora ";
	QString dprecs = "*.dptxt *.dprec *.dprecz *.dprec.gz *.dptxtz *.dptxt.gz ";
	QString formats;
	for(QByteArray format : QImageReader::supportedImageFormats()) {
		formats += "*." + format + " ";
	}
	const QString filter =
			tr("All Supported Files (%1)").arg(dpimages + dprecs + formats) + ";;" +
			tr("Images (%1)").arg(dpimages + formats) + ";;" +
			tr("Recordings (%1)").arg(dprecs) + ";;" +
			QApplication::tr("All Files (*)");
	
	// Get the file name to open
	const QUrl file = QUrl::fromLocalFile(QFileDialog::getOpenFileName(this,
			tr("Open Image"), getLastPath(), filter));
	
	// Open the file if it was selected
	if(file.isValid()) {
		setLastPath(file.toString()); //设置最后打开的路径
		open(file);
	}
}

void BoardWidget::open(const QUrl& url)
{
	if (url.isLocalFile()) 
	{
		//通过文件图片加载器加载
		QString file = url.toLocalFile();
		canvas::ImageCanvasLoader icl(file);
		loadDocument(icl);			
	}
}

void BoardWidget::save(QString filename)
{
	//QString filename = m_doc->currentFilename();

	if (filename.isEmpty()) {
		filename = QString("C:\\aaa.png");
	}

	// Overwrite current file
	m_doc->saveCanvas(filename);
}

void BoardWidget::newDocument(const QSize &size, const QColor &background)
{
	//初始化器，用BlankCanvasLoader（空白画布装载机）初始化
	canvas::BlankCanvasLoader bcl(size, background);
	loadDocument(bcl);
}

void BoardWidget::updateTabletSupportMode()
{
	//QSettings cfg;
	//cfg.beginGroup("settings/input");

	//const bool enable = cfg.value("tabletevents", true).toBool();
	//const bool eraser = cfg.value("tableteraser", true).toBool();

	//m_view->setTabletMode(enable
	//	? widgets::CanvasView::ENABLE_TABLET
	//	: widgets::CanvasView::DISABLE_TABLET
	//);
	//
	//// not really tablet related, but close enough
	//m_view->setTouchGestures(
	//	cfg.value("touchscroll", true).toBool(),
	//	cfg.value("touchpinch", true).toBool(),
	//	cfg.value("touchtwist", true).toBool()
	//);
	//cfg.endGroup();
	//m_view->setBrushCursorStyle(cfg.value("settings/brushcursor").toInt());
	m_view->setTabletMode(widgets::CanvasView::ENABLE_TABLET);//使能压感
}

void BoardWidget::paste()
{

}

void BoardWidget::pasteImage(const QImage &image, const QPoint *point /*= nullptr*/)
{

}

void BoardWidget::clearOrDelete()
{

}

void BoardWidget::resizeCanvas()
{
	
}

void BoardWidget::toolChanged(tools::Tool::Type tool)
{
	// When using the annotation tool, highlight all text boxes
	m_canvasscene->showAnnotationBorders(tool == tools::Tool::ANNOTATION);

	// Send pointer updates when using the laser pointer (TODO checkbox)
	m_view->setPointerTracking(tool == tools::Tool::LASERPOINTER);

	// Remove selection when not using selection tool
	if (tool != tools::Tool::SELECTION && tool != tools::Tool::POLYGONSELECTION)
		m_doc->selectNone();

	// Deselect annotation when tool changed
	if (tool != tools::Tool::ANNOTATION)
		m_doc->toolCtrl()->setActiveAnnotation(0);

	m_doc->toolCtrl()->setActiveTool(tool);
}

void BoardWidget::onCanvasChanged(canvas::CanvasModel *canvas)
{
	m_canvasscene->initCanvas(canvas);
	connect(canvas, &canvas::CanvasModel::layerAutoselectRequest, this, [&](uint16_t id)
	{
		if (m_doc != nullptr)
			m_doc->toolCtrl()->setActiveLayer(id);  //设置当前活动层ID,不然绘制不了
	});
	//connect(canvas, &canvas::CanvasModel::colorPicked, _dock_toolsettings, &docks::ToolSettings::setForegroundColor);
	//connect(canvas, &canvas::CanvasModel::colorPicked, static_cast<tools::ColorPickerSettings*>(_dock_toolsettings->getToolSettingsPage(tools::Tool::PICKER)), &tools::ColorPickerSettings::addColor);

	//connect(canvas, &canvas::CanvasModel::selectionRemoved, this, &MainWindow::selectionRemoved);
	//connect(_dock_layers, &docks::LayerList::layerViewModeSelected, canvas, &canvas::CanvasModel::setLayerViewMode);

	//_dock_layers->setCanvas(canvas);

	//_currentdoctools->setEnabled(true);
}

void BoardWidget::onCanvasSaveStarted()
{
	
}

void BoardWidget::onCanvasSaved(const QString &errorMessage)
{

}

void BoardWidget::closeEvent(QCloseEvent *event)
{
	exit();
}
bool BoardWidget::event(QEvent *event)
{
	//快捷键
	if (event->type() == QEvent::StatusTip) {
		return true;
	}
	else {
		if (event->type() == QEvent::KeyRelease) {
			const QKeyEvent *e = static_cast<const QKeyEvent*>(event);
			if (!e->isAutoRepeat()) {

			}
		}
		else if (event->type() == QEvent::ShortcutOverride) {
			const QKeyEvent *e = static_cast<QKeyEvent*>(event);
			if (e->key() == Qt::Key_Return) {
				QWidget *focus = QApplication::focusWidget();
				if (focus && focus->inherits("QLineEdit")) {
					event->accept();
					return true;
				}
			}
		}

		return QWidget::event(event);
	}
}
void BoardWidget::setDrawingToolsEnabled(bool enable)
{
	//控制外部工具按钮是否可用
}
