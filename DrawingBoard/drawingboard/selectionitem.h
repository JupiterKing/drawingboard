#ifndef SELECTIONITEM_H
#define SELECTIONITEM_H

#include "canvas/canvasSelection.h"

#include <QGraphicsObject>

namespace drawingboard {

class SelectionItem : public QGraphicsObject
{
public:
	enum { Type= UserType + 11 };

	SelectionItem(canvas::canvasSelection *selection, QGraphicsItem *parent=0);

	QRectF boundingRect() const;
	int type() const { return Type; }

	void marchingAnts();

private slots:
	void onShapeChanged();

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *);

private:
	QPolygonF m_shape;
	canvas::canvasSelection *m_selection;
	qreal m_marchingants;
};

}

#endif // SELECTIONITEM_H
