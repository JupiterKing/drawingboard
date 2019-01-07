/************************************************************************/
/* text�ɱ༭���ı���              �Զ���ʵ��                                      */
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
		void setTextToItem(const QString intoText = "�������ı�");
		void setTextItemFont(QFont font, int size = 20, int interval = 0, int rotate = 0);
		void setTextSize(int iSize);
		void setTextPosition(int x, int y);
		void setValign(int valign);		//���뷽ʽ
		void setHighlight(bool h);  //�������Ƿ�ѡ��
		void setShowBorder(bool show);
		QRectF boundingRect() const;
		//! reimplementation
		int  id() const { return m_id; }
		int type() const { return Type; }

	protected:
		virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *);
	private:
		void paintHiddenBorder(QPainter *painter); //���Ʊ߿�
	private:
		int m_id;
		int m_valign;
		QRectF m_rect;
		QColor m_color;
		bool m_highlight;
		bool m_showborder;
	};
}