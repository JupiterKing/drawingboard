/************************************************************************/
/* 封装的画板widget                                                                     */
/************************************************************************/
#pragma once
#include <QWidget>
#include "tools/tool.h"
#include "drawingboard.h"

class Document;

namespace widgets
{
	class CanvasView;
}
namespace drawingboard
{
	class CanvasScene;
}
namespace canvas
{
	class CanvasModel;
	class SessionLoader;  //会画装载器，加载图片等
}
namespace tools
{
	class ToolController;  //工具总控
}

class DRAWINGBOARD_EXPORT BoardWidget :public DrawingBoard
{
	Q_OBJECT
public:
	BoardWidget(QWidget* parent = nullptr);
	~BoardWidget();
public slots:
	//自定义外部调用接口
	virtual void operation_open();		//打开图片（通过打开对话框）
	virtual void operation_load(const QImage& img);		//加载图片
	virtual void operation_undo();		//撤销
	virtual void operation_redo();		//重做
	virtual void operation_mouseCheck();//鼠标选择
	virtual void operation_pensize(int iSize);	//画笔选择
	virtual void operation_text(int iFontSize);		//注释
	virtual void operation_shape(ShapeType eType);		//图形
	virtual void operation_color(QColor color);		//颜色
	virtual void operation_eraser(int iSize);	//橡皮檫
	virtual void operation_decal();		//贴花
	virtual void operation_clearArea(); //清屏
	virtual void operation_fillArea(QColor color);	//填充
	virtual void operation_expand(ExpandDirection direction);  //画布拓展
	virtual void operation_rotation(RotationDirecton direction);	//旋转
	virtual void operation_zoom(qreal izoomrate);	//放大缩小
	virtual void operation_save(QImage& img);		//保存笔迹
	virtual void operation_screenshots();			//截图
	virtual void operation_quicktext(QString);
	virtual bool isCanvasChanged();
public:
	BoardWidget* loadDocument(canvas::SessionLoader &loader);
	void exit();
	void resizeEvent(QResizeEvent *event);
public slots:
	void showNew();  //创建新的绘图板
	void open();
	void open(const QUrl& url);
	void save(QString filename);
	void newDocument(const QSize &size, const QColor &background);
private slots:
	void updateTabletSupportMode();  //根据配置，是否支持压感
	void paste(); 
	void pasteImage(const QImage &image, const QPoint *point = nullptr);

	void clearOrDelete();
	void resizeCanvas();
	void toolChanged(tools::Tool::Type tool);

	void onCanvasChanged(canvas::CanvasModel *canvas);
	void onCanvasSaveStarted();
	void onCanvasSaved(const QString &errorMessage);
signals:
	void signal_open();
	void signal_undo();
	void signal_redo();
	void signal_toolChanged(tools::Tool::Type tool);
	void signal_mouse();
	void signal_brushChange(tools::Tool::Type tool);
	void signal_textsize(int iFontSize);
	void signal_color(QColor color);
	void signal_decal();
	void signal_expandup();
	void signal_expandright();
	void signal_expanddown();
	void signal_expandleft();
	void signal_zoom(qreal izoomrate);  //izoomrate = 80~150
	void signal_zoomin();
	void signal_zoomout();
	void signal_zoomorig(); //放大到原始大小 
	void signal_rotateorig(); //旋转到原始
	void signal_rotatecw();  //顺时针旋转90度clockwise
	void signal_rotateccw(); //逆时针旋转90度 counter clockwise
	void signal_rotate90();
	void signal_rotate180();
	void signal_rotate270();
	void signal_viewflip(bool bflip); //翻转
	void signal_viewmirror(bool bmirror); //镜像
	void signal_clearArea();
	void signal_fillArea(QColor color);
	void signal_showannotations(bool bshow);
	void signal_showuserlayers(bool bshow);
	void signal_showlasers(bool bshow);
	void signal_quicktext(QString strText);
protected:
	void closeEvent(QCloseEvent *event);
	bool event(QEvent *event);
private:
	void setDrawingToolsEnabled(bool enable);
private:
	widgets::CanvasView* m_view;
	drawingboard::CanvasScene *m_canvasscene;
	tools::Tool::Type m_lasttoolType;
	Document*	m_doc;
	QImage		m_image;
	QColor		m_color;
	int			m_iSize;
};