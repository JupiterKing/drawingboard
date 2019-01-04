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
	enum RotationDirecton{ CLOCKWISE = 0,ANTICLOCKWISE}; //顺时针， 逆时针

 	DrawingBoard(QWidget * parent);
	virtual ~DrawingBoard() = default;

	static DrawingBoard* create(QWidget * parent = nullptr) noexcept;

public slots: //自定义外部调用接口
	virtual void operation_open() = 0;				//通过“打开对话框”打开图片
	virtual void operation_load(const QImage& img)=0;		//加载图片
	virtual void operation_undo() = 0;				//撤销
	virtual void operation_redo() = 0;				//重做
	virtual void operation_mouseCheck() = 0;		//鼠标选择
	virtual void operation_pensize(int iSize) = 0;	//选中画笔并设置大小，像素单位
	virtual void operation_text(int iFontSize) = 0; //选中文字并设置大小,iFontSize 是字号
	virtual void operation_shape(ShapeType eType) = 0;	//选择图形
	virtual void operation_color(QColor color) = 0;		//选择颜色
	virtual void operation_eraser(int iSize) = 0;		//选择橡皮擦并设置大小，像素单位 ，直径
	virtual void operation_expand(ExpandDirection direction) = 0;		//画布拓展
	virtual void operation_rotation(RotationDirecton direction) = 0;		//旋转，每次旋转90度
	virtual void operation_zoom(qreal izoomrate) = 0;					//放大缩小 范围: 80-150
	virtual void operation_save(QImage& img) = 0;						//保存笔迹

	virtual void operation_decal() = 0;							//贴花
	virtual void operation_clearArea() = 0;						//清空	
	virtual void operation_fillArea(QColor color) = 0;						//填充
	virtual void operation_screenshots()=0;						//截图
	
};
