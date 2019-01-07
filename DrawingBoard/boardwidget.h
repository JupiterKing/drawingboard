/************************************************************************/
/* ��װ�Ļ���widget                                                                     */
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
	class SessionLoader;  //�ửװ����������ͼƬ��
}
namespace tools
{
	class ToolController;  //�����ܿ�
}

class DRAWINGBOARD_EXPORT BoardWidget :public DrawingBoard
{
	Q_OBJECT
public:
	BoardWidget(QWidget* parent = nullptr);
	~BoardWidget();
public slots:
	//�Զ����ⲿ���ýӿ�
	virtual void operation_open();		//��ͼƬ��ͨ���򿪶Ի���
	virtual void operation_load(const QImage& img);		//����ͼƬ
	virtual void operation_undo();		//����
	virtual void operation_redo();		//����
	virtual void operation_mouseCheck();//���ѡ��
	virtual void operation_pensize(int iSize);	//����ѡ��
	virtual void operation_text(int iFontSize);		//ע��
	virtual void operation_shape(ShapeType eType);		//ͼ��
	virtual void operation_color(QColor color);		//��ɫ
	virtual void operation_eraser(int iSize);	//��Ƥ��
	virtual void operation_decal();		//����
	virtual void operation_clearArea(); //����
	virtual void operation_fillArea(QColor color);	//���
	virtual void operation_expand(ExpandDirection direction);  //������չ
	virtual void operation_rotation(RotationDirecton direction);	//��ת
	virtual void operation_zoom(qreal izoomrate);	//�Ŵ���С
	virtual void operation_save(QImage& img);		//����ʼ�
	virtual void operation_screenshots();			//��ͼ
	virtual void operation_quicktext(QString);
	virtual bool isCanvasChanged();
public:
	BoardWidget* loadDocument(canvas::SessionLoader &loader);
	void exit();
	void resizeEvent(QResizeEvent *event);
public slots:
	void showNew();  //�����µĻ�ͼ��
	void open();
	void open(const QUrl& url);
	void save(QString filename);
	void newDocument(const QSize &size, const QColor &background);
private slots:
	void updateTabletSupportMode();  //�������ã��Ƿ�֧��ѹ��
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
	void signal_zoomorig(); //�Ŵ�ԭʼ��С 
	void signal_rotateorig(); //��ת��ԭʼ
	void signal_rotatecw();  //˳ʱ����ת90��clockwise
	void signal_rotateccw(); //��ʱ����ת90�� counter clockwise
	void signal_rotate90();
	void signal_rotate180();
	void signal_rotate270();
	void signal_viewflip(bool bflip); //��ת
	void signal_viewmirror(bool bmirror); //����
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