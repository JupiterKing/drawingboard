/************************************************************************/
/* text可编辑的文本项              自定义实现                                      */
/************************************************************************/
#pragma once
#include <QGraphicsTextItem>

namespace drawingboard {

	class TextItem :public QGraphicsTextItem
	{
		Q_OBJECT
	public:
		enum { Type = UserType + 12 };
		static const int HANDLE = 10;

		explicit TextItem(int id,QGraphicsItem *parent = Q_NULLPTR);
		explicit TextItem(int id,const QString &text, QGraphicsItem *parent = Q_NULLPTR);
	public:
		void setGeometry(const QRect &rect);
		void setColor(const QColor &color);
		void setTextToItem(const QString intoText = "请输入文本");
		void setTextItemFont(QFont font, int size = 20, int interval = 0, int rotate = 0);
		void setTextSize(int iSize);
		void setTextPosition(int x, int y);
		void setValign(int valign);		//对齐方式
		void setHighlight(bool h);  //高亮，是否选中
		void setShowBorder(bool show);
		QRectF boundingRect() const;
		//! reimplementation
		int  id() const { return m_id; }
		int type() const { return Type; }

	protected:
		virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *);
	private:
		void paintHiddenBorder(QPainter *painter); //绘制边框
	private:
		int m_id;
		int m_valign;
		QRectF m_rect;
		QColor m_color;
		bool m_highlight;
		bool m_showborder;
	};
}