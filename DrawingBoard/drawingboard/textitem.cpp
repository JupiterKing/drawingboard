#include "textitem.h"
#include <QApplication>
#include <QPalette>
#include <QPainter>
#include <QTextDocument>
#include <QDebug>

namespace drawingboard
{

	TextItem::TextItem(int id,QGraphicsItem *parent /*= Q_NULLPTR*/)
		:QGraphicsTextItem(parent),m_id(id),m_valign(0),m_highlight(true),m_showborder(true)
	{

		setFlag(QGraphicsItem::ItemIsFocusable);	//��Ŀ���Ծ۽�
		setFlag(QGraphicsItem::ItemIsMovable);		//���ƶ�
		setFlag(QGraphicsItem::ItemIsSelectable, true); //��ѡ�У����������䣬����item�޷���ȡ������¼�
		QFont font;
		setTextItemFont(font, 16, 0, 0);			//Ĭ���ֺ�20
		setDefaultTextColor(QColor(0, 160, 230));	// Ĭ���ı�ɫ
	}

	TextItem::TextItem(int id,const QString &text, QGraphicsItem *parent /*= Q_NULLPTR*/)
		: QGraphicsTextItem(parent), m_id(id), m_valign(0), m_highlight(true), m_showborder(true)
	{
		setFlag(QGraphicsItem::ItemIsFocusable); //��Ŀ���Ծ۽�
		setFlag(QGraphicsItem::ItemIsMovable);
		setFlag(QGraphicsItem::ItemIsSelectable, true);
		QFont font;
		setTextItemFont(font, 16, 0, 0);
		setDefaultTextColor(QColor(0, 160, 230));  // �ı�ɫ

		setPlainText(text);
	}

	void TextItem::setGeometry(const QRect &rect)
	{
		prepareGeometryChange();
		m_rect = rect;
		setTextWidth(rect.width());
		setPos(rect.x(), rect.y()); //λ�ñ����������Ȼ����
	}

	void TextItem::setColor(const QColor &color)
	{
		m_color = color;
		update();
	}

	void TextItem::setTextToItem(const QString intoText /*= "�������ı�"*/)
	{
		//��������Ŀ���������
		this->setPlainText(intoText);
	}

	void TextItem::setTextItemFont(QFont font, int size /*= 20*/, int interval /*= 0*/, int rotate /*= 0*/)
	{
		font.setPixelSize(size);  //��������Ĵ�С
		font.setLetterSpacing(QFont::AbsoluteSpacing, interval);  //��������ļ��
		this->setFont(font);
		this->setRotation(rotate);  //������ת�ĽǶ�
	}

	void TextItem::setTextSize(int iSize)
	{
		QFont font;
		font.setPixelSize(iSize);  //��������Ĵ�С
		this->setFont(font);
	}

	void TextItem::setTextPosition(int x, int y)
	{
		this->setPos(x, y);
	}

	void TextItem::setValign(int valign)
	{
		m_valign = valign;
		update();
	}

	void TextItem::setHighlight(bool hl)
	{
		if (m_highlight != hl) {
			m_highlight = hl;
			update();
		}
	}

	void TextItem::setShowBorder(bool show)
	{
		if (m_showborder != show) {
			m_showborder = show;
			update();
		}
	}

	QRectF TextItem::boundingRect() const
	{
		return QGraphicsTextItem::boundingRect();
	}

	void TextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
	{
		Q_UNUSED(options);
		Q_UNUSED(widget);

		painter->save();
		painter->setClipRect(boundingRect().adjusted(-1, -1, 1, 1));
		painter->fillRect(m_rect, Qt::white);

		paintHiddenBorder(painter);//���Ʊ߿�

		if (m_highlight)  //��ǰѡ��������ý��㣬�ɱ༭
		{
			setFocus();
			setTextInteractionFlags(Qt::TextEditorInteraction);
		}
		else
		{
			clearFocus();
			setTextInteractionFlags(Qt::NoTextInteraction); //���ɱ༭
		}
	
		painter->restore();
		QGraphicsTextItem::paint(painter, options, widget);
	}

	void TextItem::paintHiddenBorder(QPainter *painter)
	{
		if (!m_showborder)
			return;

		const qreal devicePixelRatio = qApp->devicePixelRatio();
		QColor highlightColor = QApplication::palette().color(QPalette::Highlight);
		highlightColor.setAlpha(255);

		QPen bpen(m_highlight && m_showborder ? Qt::DashLine : Qt::DotLine);
		bpen.setWidth(devicePixelRatio);
		bpen.setCosmetic(true);
		bpen.setColor(highlightColor);
		painter->setPen(bpen);
		painter->drawRect(m_rect);
	}

}