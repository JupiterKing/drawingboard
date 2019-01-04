#ifndef DP_NET_LAYERLIST_H
#define DP_NET_LAYERLIST_H

#include "paintcore/blendmodes.h"

#include <QAbstractListModel>
#include <QMimeData>
#include <QVector>

#include <functional>
#include "net/message.h"

namespace protocol {
	class MessagePtr;

}
namespace paintcore {
	class Layer;
}

namespace canvas {

struct LayerListItem {
	LayerListItem() : id(0), title(QString()), opacity(1.0), blend(paintcore::BlendMode::MODE_NORMAL), hidden(false), locked(false) {}
	LayerListItem(int id_, const QString &title_, float opacity_=1.0, paintcore::BlendMode::Mode blend_=paintcore::BlendMode::MODE_NORMAL, bool hidden_=false, bool locked_=false, const QList<uint8_t> &exclusive_=QList<uint8_t>())
		: id(id_), title(title_), opacity(opacity_), blend(blend_), hidden(hidden_), locked(locked_), exclusive(exclusive_)
		{}

	//! Layer ID
	int id;
	
	//! Layer title
	QString title;
	
	//! Layer opacity
	float opacity;
	
	//! Blending mode
	paintcore::BlendMode::Mode blend;

	//! Layer hidden flag (local only)
	bool hidden;

	//! General layer lock
	bool locked;

	//! Exclusive access to these users
	QList<uint8_t> exclusive;

	bool isLockedFor(int userid) const { return locked || !(exclusive.isEmpty() || exclusive.contains(userid)); }
};

}

Q_DECLARE_TYPEINFO(canvas::LayerListItem, Q_MOVABLE_TYPE);

namespace canvas {

typedef std::function<const paintcore::Layer*(int id)> GetLayerFunction;

class LayerListModel : public QAbstractListModel {
	Q_OBJECT
public:
	enum LayerListRoles {
		IdRole = Qt::UserRole + 1,
		TitleRole,
		IsDefaultRole,
	};

	LayerListModel(QObject *parent=0);
	
	int rowCount(const QModelIndex &parent=QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex& index) const;
	Qt::DropActions supportedDropActions() const;
	QStringList mimeTypes() const;
	QMimeData *mimeData(const QModelIndexList& indexes) const;
	bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);

	QModelIndex layerIndex(int id);
	
	void clear();
	void createLayer(int id, int index, const QString &title);
	void deleteLayer(int id);
	void changeLayer(int id, float opacity, paintcore::BlendMode::Mode blend);
	void retitleLayer(int id, const QString &title);
	void setLayerHidden(int id, bool hidden);
	void reorderLayers(QList<uint16_t> neworder);
	void unlockAll();

	bool isLayerLockedFor(int layerId, int contextId) const;
	
	QVector<LayerListItem> getLayers() const { return m_items; }
	void setLayers(const QVector<LayerListItem> &items);

	void previewOpacityChange(int id, float opacity);

	void setLayerGetter(GetLayerFunction fn) { m_getlayerfn = fn; }
	const paintcore::Layer *getLayerData(int id) const;

	int myId() const { return m_myId; }
	void setMyId(int id) { m_myId = id; }

	/**
	 * @brief Get the default layer to select when logging in
	 * Zero means no default.
	 */
	int defaultLayer() const { return m_defaultLayer; }
	void setDefaultLayer(int id);

	/**
	 * @brief Find a free layer ID
	 * @return layer ID or 0 if all are taken
	 */
	int getAvailableLayerId() const;

	/**
	 * @brief Find a unique name for a layer
	 * @param basename
	 * @return unique name
	 */
	QString getAvailableLayerName(QString basename) const;

public slots:
	void updateLayerAcl(int id, bool locked, QList<uint8_t> exclusive);

signals:
	void layersReordered();

	//! Emitted when layers are manually reordered
	void layerCommand(protocol::MessagePtr msg);

	//! Request local change of layer opacity for preview purpose
	void layerOpacityPreview(int id, float opacity);

private:
	void handleMoveLayer(int idx, int afterIdx);

	int indexOf(int id) const;

	// Terrible hack: the layers are created and edited in the state tracker (which can run concurrently)
	// but the ACL changes are updated immediately. So, we must save the ACLs for missing layers in case
	// they're created afterwards
	// TODO separate the AclFilter better and update the UI as changes are really applied, then get rid of this.
	struct LayerAcl {
		bool locked;
		QList<uint8_t> exclusive;
	};
	QHash<uint16_t, LayerAcl> m_pendingAclChange;
	
	QVector<LayerListItem> m_items;
	GetLayerFunction m_getlayerfn;
	int m_defaultLayer;
	int m_myId;
};

/**
 * A specialization of QMimeData for passing layers around inside
 * the application.
 */
class LayerMimeData : public QMimeData
{
Q_OBJECT
public:
	LayerMimeData(const LayerListModel *source, int id) : QMimeData(), _source(source), _id(id) {}

	const LayerListModel *source() const { return _source; }

	int layerId() const { return _id; }

	QStringList formats() const;

protected:
	QVariant retrieveData(const QString& mimeType, QVariant::Type type) const;

private:
	const LayerListModel *_source;
	int _id;
};

}

Q_DECLARE_METATYPE(canvas::LayerListItem)

#endif

