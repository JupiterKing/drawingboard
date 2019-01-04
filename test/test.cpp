#include "test.h"
#include "QBoxLayout"

test::test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_widget = new BoardWidget(this);
	m_widget->newDocument(QSize(960, 720), Qt::white);

	QVBoxLayout *mainwinlayout = new QVBoxLayout(m_widget);
	mainwinlayout->setContentsMargins(0, 0, 0, 0);
	mainwinlayout->setSpacing(0);
	setCentralWidget(m_widget);

	setupActions();
}

QAction * test::makeAction(const char *name, const char *icon, const QString& text, const QString& tip /*= QString()*/, const QKeySequence& shortcut /*= QKeySequence()*/, bool checkable /*= false*/)
{
	QAction *act;
	QIcon qicon;
	//if (icon)
	//	qicon = icon::fromTheme(icon);
	act = new QAction(qicon, text, this);
	if (name)
		act->setObjectName(name);
	if (shortcut.isEmpty() == false)
		act->setShortcut(shortcut);

	act->setCheckable(checkable);

	act->setAutoRepeat(false);

	if (tip.isEmpty() == false)
		act->setStatusTip(tip);

	addAction(act);

	return act;
}

QAction * test::getAction(const QString &name)
{
	QAction *a = findChild<QAction*>(name, Qt::FindDirectChildrenOnly);
	if (!a)
		qFatal("%s: no such action", name.toLocal8Bit().constData());
	Q_ASSERT(a);
	return a;
}

void test::setupActions()
{
	m_drawingtools = new QActionGroup(this);
	connect(m_drawingtools, SIGNAL(triggered(QAction*)), this, SLOT(selectTool(QAction*)));

	QAction *open = makeAction("open", "edit-open", tr("&Open"), QString(), QKeySequence::Open);
	QAction *undo = makeAction("undo", "edit-undo", tr("&Undo"), QString(), QKeySequence::Undo);
	QAction *redo = makeAction("redo", "edit-redo", tr("&Redo"), QString(), QKeySequence::Redo);
	QAction *resize = makeAction("resizecanvas", 0, tr("Resi&ze Canvas..."));

	QAction *expandup = makeAction("expandup", 0, tr("Expand &Up"), "", QKeySequence(CTRL_KEY "+J"));
	QAction *expanddown = makeAction("expanddown", 0, tr("Expand &Down"), "", QKeySequence(CTRL_KEY "+K"));
	QAction *expandleft = makeAction("expandleft", 0, tr("Expand &Left"), "", QKeySequence(CTRL_KEY "+H"));
	QAction *expandright = makeAction("expandright", 0, tr("Expand &Right"), "", QKeySequence(CTRL_KEY "+L"));

	QAction *cleararea = makeAction("cleararea", 0, tr("Delete"), QString(), QKeySequence("Delete"));
	QAction *fillfgarea = makeAction("fillfgarea", 0, tr("Fill Selection"), QString(), QKeySequence(CTRL_KEY "+,"));
	QAction *recolorarea = makeAction("recolorarea", 0, tr("Recolor Selection"), QString(), QKeySequence(CTRL_KEY "+Shift+,"));
	QAction *colorerasearea = makeAction("colorerasearea", 0, tr("Color Erase Selection"), QString(), QKeySequence("Shift+Delete"));

	//m_docadmintools->addAction(resize);
	//m_docadmintools->addAction(expandup);
	//m_docadmintools->addAction(expanddown);
	//m_docadmintools->addAction(expandleft);
	//m_docadmintools->addAction(expandright);

	connect(open, &QAction::triggered, m_widget, &BoardWidget::operation_open);
	connect(undo, &QAction::triggered, m_widget, &BoardWidget::operation_undo);
	connect(redo, &QAction::triggered, m_widget, &BoardWidget::operation_redo);
	//connect(expandup, &QAction::triggered, m_widget, &BoardWidget::signal_expandup);
	connect(expandup, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_expand(BoardWidget::UP);
		}
	});
	connect(expanddown, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_expand(BoardWidget::DOWN);
		}
	});
	connect(expandleft, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_expand(BoardWidget::LEFT);
		}
	});
	connect(expandright, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_expand(BoardWidget::RIGHT);
		}
	});
	//connect(expanddown, &QAction::triggered, m_widget, &BoardWidget::signal_expanddown);
	//connect(expandleft, &QAction::triggered, m_widget, &BoardWidget::signal_expandleft);
	//connect(expandright, &QAction::triggered, m_widget, &BoardWidget::signal_expandright);

	connect(cleararea, &QAction::triggered, m_widget, &BoardWidget::operation_clearArea);
	connect(fillfgarea, &QAction::triggered, m_widget, &BoardWidget::operation_fillArea);
	//connect(recolorarea, &QAction::triggered, m_widget, &BoardWidget::operation_undo);
	//connect(colorerasearea, &QAction::triggered, m_widget, &BoardWidget::operation_fillArea);
	//connect(resize, SIGNAL(triggered()), m_widget, &BoardWidget::operation_undo);
	
	QToolBar *edittools = new QToolBar(tr("Edit Tools"));
	edittools->setObjectName("edittoolsbar");
	edittools->addAction(open);
	edittools->addAction(undo);
	edittools->addAction(redo);
	edittools->addAction(expandup);
	edittools->addAction(expanddown);
	edittools->addAction(expandleft);
	edittools->addAction(expandright);
	addToolBar(Qt::TopToolBarArea, edittools);

	QAction *zoomin = makeAction("zoomin", "zoom-in", tr("Zoom &In"), QString(), QKeySequence::ZoomIn);
	QAction *zoomout = makeAction("zoomout", "zoom-out", tr("Zoom &Out"), QString(), QKeySequence::ZoomOut);
	QAction *zoomorig = makeAction("zoomone", "zoom-original", tr("&Normal Size"), QString(), QKeySequence(Qt::CTRL + Qt::Key_0));
	QAction *rotateorig = makeAction("rotatezero", "transform-rotate", tr("&Reset Rotation"), QString(), QKeySequence(Qt::CTRL + Qt::Key_R));
	QAction *rotatecw = makeAction("rotatecw", 0, tr("Rotate Clockwise"), QString(), QKeySequence(Qt::SHIFT + Qt::Key_Period));
	QAction *rotateccw = makeAction("rotateccw", 0, tr("Rotate Counterclockwise¡ã"), QString(), QKeySequence(Qt::SHIFT + Qt::Key_Comma));

	QAction *rotate90 = makeAction("rotate90", 0, tr("Rotate to 90¡ã"));
	QAction *rotate180 = makeAction("rotate180", 0, tr("Rotate to 180¡ã"));
	QAction *rotate270 = makeAction("rotate270", 0, tr("Rotate to 270¡ã"));

	QAction *viewmirror = makeAction("viewmirror", "object-flip-horizontal", tr("Mirror"), QString(), QKeySequence("V"), true);
	QAction *viewflip = makeAction("viewflip", "object-flip-vertical", tr("Flip"), QString(), QKeySequence("C"), true);

	QAction *showannotations = makeAction("showannotations", 0, tr("Show &Annotations"), QString(), QKeySequence(), true);
	QAction *showusermarkers = makeAction("showusermarkers", 0, tr("Show User &Pointers"), QString(), QKeySequence(), true);
	QAction *showuserlayers = makeAction("showuserlayers", 0, tr("Show User &Layers"), QString(), QKeySequence(), true);
	QAction *showlasers = makeAction("showlasers", 0, tr("Show La&ser Trails"), QString(), QKeySequence(), true);
	QAction *showgrid = makeAction("showgrid", 0, tr("Show Pixel &Grid"), QString(), QKeySequence(), true);

	connect(zoomin, &QAction::triggered, m_widget, &BoardWidget::signal_zoomin);
	connect(zoomout, &QAction::triggered, m_widget, &BoardWidget::signal_zoomout);
	connect(zoomorig, &QAction::triggered, m_widget, &BoardWidget::signal_zoomorig);
	connect(rotateorig, &QAction::triggered, m_widget, &BoardWidget::signal_rotateorig);
	connect(rotatecw, &QAction::triggered, m_widget, &BoardWidget::signal_rotatecw);
	connect(rotateccw, &QAction::triggered, m_widget, &BoardWidget::signal_rotateccw);
	connect(rotate90, &QAction::triggered, m_widget, &BoardWidget::signal_rotate90);
	connect(rotate180, &QAction::triggered, m_widget, &BoardWidget::signal_rotate180);
	connect(rotate270, &QAction::triggered, m_widget, &BoardWidget::signal_rotate270);
	connect(viewflip, &QAction::triggered, m_widget, &BoardWidget::signal_viewflip);
	connect(viewmirror, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);

	connect(showannotations, &QAction::triggered, m_widget, &BoardWidget::signal_showannotations);
	connect(showuserlayers, &QAction::triggered, m_widget, &BoardWidget::signal_showuserlayers);
	connect(showlasers, &QAction::triggered, m_widget, &BoardWidget::signal_showlasers);

	QToolBar *zoomtools = new QToolBar(tr("zoom Tools"));
	zoomtools->setObjectName("zoomtoolsbar");
	zoomtools->addAction(zoomin);
	zoomtools->addAction(zoomout);
	zoomtools->addAction(zoomorig);
	zoomtools->addAction(rotateorig);
	zoomtools->addAction(rotatecw);
	zoomtools->addAction(rotateccw);
	zoomtools->addAction(rotate90);
	zoomtools->addAction(rotate180);
	zoomtools->addAction(rotate270);
	zoomtools->addAction(viewflip);
	zoomtools->addAction(viewmirror);
	addToolBar(Qt::TopToolBarArea, zoomtools);
	//////////////////////////////////////////////////////////////////////////

	QAction *freehandtool = makeAction("toolbrush", "draw-brush", tr("Freehand"), tr("Freehand brush tool"), QKeySequence("B"), true);
	QAction *erasertool = makeAction("tooleraser", "draw-eraser", tr("Eraser"), tr("Freehand eraser brush"), QKeySequence("E"), true);
	QAction *linetool = makeAction("toolline", "draw-line", tr("&Line"), tr("Draw straight lines"), QKeySequence("U"), true);
	QAction *recttool = makeAction("toolrect", "draw-rectangle", tr("&Rectangle"), tr("Draw unfilled squares and rectangles"), QKeySequence("R"), true);
	QAction *ellipsetool = makeAction("toolellipse", "draw-ellipse", tr("&Ellipse"), tr("Draw unfilled circles and ellipses"), QKeySequence("O"), true);
	QAction *beziertool = makeAction("toolbezier", "draw-bezier-curves", tr("Bezier Curve"), tr("Draw bezier curves"), QKeySequence("Ctrl+B"), true);
	QAction *filltool = makeAction("toolfill", "fill-color", tr("&Flood Fill"), tr("Fill areas"), QKeySequence("F"), true);
	QAction *annotationtool = makeAction("tooltext", "draw-text", tr("&Annotation"), tr("Add text to the picture"), QKeySequence("A"), true);

	QAction *pickertool = makeAction("toolpicker", "color-picker", tr("&Color Picker"), tr("Pick colors from the image"), QKeySequence("I"), true);
	QAction *lasertool = makeAction("toollaser", "cursor-arrow", tr("&Laser Pointer"), tr("Point out things on the canvas"), QKeySequence("L"), true);
	QAction *selectiontool = makeAction("toolselectrect", "select-rectangular", tr("&Select (Rectangular)"), tr("Select area for copying"), QKeySequence("S"), true);
	QAction *lassotool = makeAction("toolselectpolygon", "edit-select-lasso", tr("&Select (Free-Form)"), tr("Select a free-form area for copying"), QKeySequence("D"), true);

	/*connect(freehandtool, &QAction::triggered, m_widget, &BoardWidget::operation_pensize);
	connect(erasertool, &QAction::triggered, m_widget, &BoardWidget::operation_eraser);
	connect(linetool, &QAction::triggered, m_widget, &BoardWidget::operation_shape);
	connect(recttool, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);
	connect(ellipsetool, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);*/

	connect(freehandtool, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_pensize(10);
		}
	});
	connect(erasertool, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_eraser(20);
		}
	});
	connect(linetool, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_shape(DrawingBoard::LINE);
		}
	});
	connect(beziertool, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_shape(DrawingBoard::DOTLINE);
		}
	});
	connect(filltool, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_shape(DrawingBoard::ARROW);
		}
	});
	connect(recttool, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_shape(DrawingBoard::RECTANGLE);
		}
	});
	connect(ellipsetool, &QAction::triggered, this, [&]()
	{
		if (m_widget)
		{
			m_widget->operation_shape(DrawingBoard::ELLIPSE);
		}
	});
	connect(beziertool, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);
	connect(filltool, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);
	connect(annotationtool, &QAction::triggered, m_widget, &BoardWidget::operation_text);
	connect(pickertool, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);
	connect(lasertool, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);
	connect(selectiontool, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);
	connect(lassotool, &QAction::triggered, m_widget, &BoardWidget::signal_viewmirror);

	//
	QToolBar *drawtools = new QToolBar(tr("Drawing tools"));
	drawtools->setObjectName("drawtoolsbar");

	drawtools->addAction(freehandtool);
	drawtools->addAction(erasertool);
	drawtools->addAction(linetool);
	drawtools->addAction(recttool);
	drawtools->addAction(ellipsetool);
	drawtools->addAction(beziertool);
	drawtools->addAction(filltool);
	drawtools->addAction(annotationtool);
	drawtools->addAction(pickertool);
	drawtools->addAction(lasertool);
	drawtools->addAction(selectiontool);
	drawtools->addAction(lassotool);

	addToolBar(Qt::TopToolBarArea, drawtools);
}

void test::selectTool(QAction *tool)
{
	int idx = m_drawingtools->actions().indexOf(tool);
	Q_ASSERT(idx >= 0);
	if (idx < 0)
		return;

	/*if (m_widget )
	{
		if (idx == 0)
			m_widget->operation_pensize();
		else if (idx == 1)
			m_widget->operation_eraser();
		else if (idx == 2)
			m_widget->operation_shape();
	}*/

	
}
