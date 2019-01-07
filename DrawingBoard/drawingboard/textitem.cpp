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

		setFlag(QGraphicsItem::ItemIsFocusable);	//项目可以聚焦
		setFlag(QGraphicsItem::ItemIsMovable);		//可移动
		setFlag(QGraphicsItem::ItemIsSelectable, true); //可选中，必须加上这句，否则item无法获取到鼠标事件
		QFont font;
		setTextItemFont(font, 16, 0, 0);			//默认字号20
		setDefaultTextColor(QColor(0, 160, 230));	// 默认文本色
	}

	TextItem::TextItem(int id,const QString &text, QGraphicsItem *parent /*= Q_NULLPTR*/)
		: QGraphicsTextItem(parent), m_id(id), m_valign(0), m_highlight(true), m_showborder(true)
	{
		setFlag(QGraphicsItem::ItemIsFocusable); //项目可以聚焦
		setFlag(QGraphicsItem::ItemIsMovable);
		setFlag(QGraphicsItem::ItemIsSelectable, true);
		QFont font;
		setTextItemFont(font, 16, 0, 0);
		setDefaultTextColor(QColor(0, 160, 230));  // 文本色

		setPlainText(text);
	}

	void TextItem::setGeometry(const QRect &rect)
	{
		prepareGeometryChange();
		m_rect = rect;
		setTextWidth(rect.width());
		setPos(rect.x(), rect.y()); //位置必须跟进，不然出错
	}

	void TextItem::setColor(const QColor &color)
	{
		m_color = color;
		update();
	}

	void TextItem::setTextToItem(const QString intoText /*= "请输入文本"*/)
	{
		//向字体项目中添加文字
		this->setPlainText(intoText);
	}

	void TextItem::setTextItemFont(QFont font, int size /*= 20*/, int interval /*= 0*/, int rotate /*= 0*/)
	{
		font.setPixelSize(size);  //设置字体的大小
		font.setLetterSpacing(QFont::AbsoluteSpacing, interval);  //设置字体的间距
		this->setFont(font);
		this->setRotation(rotate);  //设置旋转的角度
	}

	void TextItem::setTextSize(int iSize)
	{
		QFont font;
		font.setPixelSize(iSize);  //设置字体的大小
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

		paintHiddenBorder(painter);//绘制边框

		if (m_highlight)  //当前选中项，则设置焦点，可编辑
		{
			setFocus();
			setTextInteractionFlags(Qt::TextEditorInteraction);
		}
		else
		{
			clearFocus();
			setTextInteractionFlags(Qt::NoTextInteraction); //不可编辑
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