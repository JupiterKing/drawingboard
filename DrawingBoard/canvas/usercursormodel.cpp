#include "usercursormodel.h"
#include <QDateTime>
#include <QTimerEvent>
#include <QDebug>

namespace canvas {

UserCursorModel::UserCursorModel(QObject *parent)
	: QAbstractListModel(parent)
{
	m_timerId = startTimer(1000, Qt::VeryCoarseTimer);
}

int UserCursorModel::rowCount(const QModelIndex &parent) const
{
	if(parent.isValid())
		return 0;
	return m_cursors.size();
}

QModelIndex UserCursorModel::indexForId(int id) const
{
	for(int i=0;i<m_cursors.size();++i)
		if(m_cursors.at(i).id == id)
			return index(i);
	return QModelIndex();
}

QVariant UserCursorModel::data(const QModelIndex &index, int role) const
{
	if(index.isValid() && index.row() >= 0 && index.row() < m_cursors.size()) {
		const UserCursor &uc = m_cursors.at(index.row());
	switch(role) {
		case Qt::DisplayRole: return uc.name;
		case IdRole: return uc.id;
		case PositionRole: return uc.pos;
		case LayerRole: return uc.layer;
		case ColorRole: return uc.color;
		case VisibleRole: return uc.visible;
		default: break;
		}
	}
	return QVariant();
}

QHash<int, QByteArray> UserCursorModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[Qt::DisplayRole] = "display";
	roles[IdRole] = "id";
	roles[PositionRole] = "pos";
	roles[LayerRole] = "layer";
	roles[ColorRole] = "color";
	roles[VisibleRole] = "visible";
	return roles;
}


void UserCursorModel::setCursorName(int id, const QString &name)
{
	QModelIndex index;
	UserCursor *uc = getOrCreate(id, index);

	uc->name = name;

	emit dataChanged(index, index, QVector<int>() << Qt::DisplayRole);
}

void UserCursorModel::setCursorAttributes(int id, const QColor &color, const QString &layer)
{
	QModelIndex index;
	UserCursor *uc = getOrCreate(id, index);

	uc->color = color;
	uc->layer = layer;

	emit dataChanged(index, index, QVector<int>() << LayerRole << ColorRole);
}

void UserCursorModel::setCursorPosition(int id, const QPointF &pos)
{
	QModelIndex index;
	UserCursor *uc = getOrCreate(id, index);

	QVector<int> roles;

	uc->pos = pos; roles << PositionRole;
	uc->lastMoved = QDateTime::currentMSecsSinceEpoch();
	if(!uc->visible) {
		uc->visible = true;
		roles << VisibleRole;
	}

	emit dataChanged(index, index, roles);
}

void UserCursorModel::hideCursor(int id)
{
	for(int i=0;i<m_cursors.size();++i) {
		if(m_cursors.at(i).id == id) {
			m_cursors[i].visible = false;
			QModelIndex idx = index(i);
			emit dataChanged(idx, idx, QVector<int>() << VisibleRole);
			return;
		}
	}
}

void UserCursorModel::clear()
{
	beginResetModel();
	m_cursors.clear();
	endResetModel();
}

UserCursor *UserCursorModel::getOrCreate(int id, QModelIndex &idx)
{
	for(int i=0;i<m_cursors.size();++i) {
		if(m_cursors.at(i).id == id) {
			idx = index(i);
			return &m_cursors[i];
		}
	}

	beginInsertRows(QModelIndex(), m_cursors.size(), m_cursors.size());
	m_cursors.append(UserCursor { id, false, QDateTime::currentMSecsSinceEpoch(), QPointF(), QStringLiteral("#%1").arg(id), QString(), QColor(Qt::black)});
	endInsertRows();

	idx = index(m_cursors.size()-1);
	return &m_cursors[m_cursors.size()-1];
}

void UserCursorModel::timerEvent(QTimerEvent *e)
{
	if(e->timerId() != m_timerId) {
		QAbstractListModel::timerEvent(e);
		return;
	}

	const qint64 now = QDateTime::currentMSecsSinceEpoch();
	const qint64 hideTreshold = now - 3000;

	for(int i=0;i<m_cursors.size();++i) {
		UserCursor &uc = m_cursors[i];

		if(uc.visible && uc.lastMoved < hideTreshold) {
			uc.visible = false;
			QModelIndex idx = index(i);
			emit dataChanged(idx, idx, QVector<int>() << VisibleRole);
		}
	}
}

}
