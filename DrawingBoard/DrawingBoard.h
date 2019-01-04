#pragma once


#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DRAWINGBOARD_LIB)
#  define DRAWINGBOARD_EXPORT Q_DECL_EXPORT
# else
#  define DRAWINGBOARD_EXPORT Q_DECL_IMPORT
# endif
#else
# define DRAWINGBOARD_EXPORT
#endif


#include <QWidget>

class DRAWINGBOARD_EXPORT DrawingBoard
	:public QWidget
{
	Q_OBJECT
public:
	enum ShapeType{ LINE = 0,DOTLINE,ARROW,RECTANGLE,ELLIPSE};
	enum ExpandDirection { UP = 0,RIGHT,DOWN,LEFT};
	enum RotationDirecton{ CLOCKWISE = 0,ANTICLOCKWISE}; //˳ʱ�룬 ��ʱ��

 	DrawingBoard(QWidget * parent);
	virtual ~DrawingBoard() = default;

	static DrawingBoard* create(QWidget * parent = nullptr) noexcept;

public slots: //�Զ����ⲿ���ýӿ�
	virtual void operation_open() = 0;				//ͨ�����򿪶Ի��򡱴�ͼƬ
	virtual void operation_load(const QImage& img)=0;		//����ͼƬ
	virtual void operation_undo() = 0;				//����
	virtual void operation_redo() = 0;				//����
	virtual void operation_mouseCheck() = 0;		//���ѡ��
	virtual void operation_pensize(int iSize) = 0;	//ѡ�л��ʲ����ô�С�����ص�λ
	virtual void operation_text(int iFontSize) = 0; //ѡ�����ֲ����ô�С,iFontSize ���ֺ�
	virtual void operation_shape(ShapeType eType) = 0;	//ѡ��ͼ��
	virtual void operation_color(QColor color) = 0;		//ѡ����ɫ
	virtual void operation_eraser(int iSize) = 0;		//ѡ����Ƥ�������ô�С�����ص�λ ��ֱ��
	virtual void operation_expand(ExpandDirection direction) = 0;		//������չ
	virtual void operation_rotation(RotationDirecton direction) = 0;		//��ת��ÿ����ת90��
	virtual void operation_zoom(qreal izoomrate) = 0;					//�Ŵ���С ��Χ: 80-150
	virtual void operation_save(QImage& img) = 0;						//����ʼ�

	virtual void operation_decal() = 0;							//����
	virtual void operation_clearArea() = 0;						//���	
	virtual void operation_fillArea(QColor color) = 0;						//���
	virtual void operation_screenshots()=0;						//��ͼ
	
};
