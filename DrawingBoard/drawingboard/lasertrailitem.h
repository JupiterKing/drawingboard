#ifndef LASERTRAILITEM_H
#define LASERTRAILITEM_H

#include <QGraphicsItem>
#include <QPen>

namespace drawingboard {

class LaserTrailItem : public QGraphicsItem
{
public:
	LaserTrailItem(QGraphicsItem *parent=nullptr);

	void animationStep(float dt);

	void setPoints(const QVector<QPointF> &points);
	void setColor(const QColor &color);
	void setFadeVisible(bool visible);

	QRectF boundingRect() const;
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	bool m_blink;
	bool m_visible;
	QPen m_pen;
	QVector<QPointF> m_points;
	QRectF m_bounds;
};

}

#endif // LASERTRAILITEM_H
