#ifndef LASERTRAILMODEL_H
#define LASERTRAILMODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <QPointF>

namespace canvas {

struct LaserTrail {
	int ctxid;
	int internalId;
	QColor color;
	QVector<QPointF> points;
	bool open;
	bool visible;

	int persistence;
	qint64 expiration;
};

class LaserTrailModel : public QAbstractListModel
{
	Q_OBJECT
public:
	enum LaserRolesRoles {
		ColorRole = Qt::UserRole + 1,
		ContextRole,
		PointsRole,
		VisibleRole,
		InternalIdRole
	};

	explicit LaserTrailModel(QObject *parent=nullptr);

	int rowCount(const QModelIndex &parent=QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;

	QHash<int, QByteArray> roleNames() const;

public slots:
	void startTrail(int ctxId, const QColor &color, int persistence);
	void addPoint(int ctxId, const QPointF &point);
	void endTrail(int ctxId);

protected:
	void timerEvent(QTimerEvent *e);

private:
	bool isOpenTrail(int ctxId);
	QList<LaserTrail> m_lasers;
	int m_timerId;
	int m_lastId;
};

}

#endif // LASERTRAILMODEL_H
