#ifndef CANVASMODEL_H
#define CANVASMODEL_H

#include "net/message.h"

// note: we must include these so the datatypes get registered properly for use in QML
#include "usercursormodel.h"
#include "lasertrailmodel.h"
#include "canvasSelection.h"
#include "paintcore/layerstack.h"
#include "statetracker.h"

#include <QObject>
#include <QPointer>

namespace protocol {
	class LaserTrail;
	class MovePointer;
	class DefaultLayer;
}

namespace canvas {

class StateTracker;
class LayerListModel;

class CanvasModel : public QObject
{
	Q_PROPERTY(paintcore::LayerStack* layerStack READ layerStack CONSTANT)
	Q_PROPERTY(UserCursorModel* userCursors READ userCursors CONSTANT)
	Q_PROPERTY(LaserTrailModel* laserTrails READ laserTrails CONSTANT)
	Q_PROPERTY(StateTracker* stateTracker READ stateTracker CONSTANT)
	Q_PROPERTY(canvasSelection* selection READ selection WRITE setSelection NOTIFY selectionChanged)

	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(QString pinnedMessage READ pinnedMessage NOTIFY pinnedMessageChanged)

	Q_OBJECT

public:
	explicit CanvasModel(int localUserId, QObject *parent = 0);

	paintcore::LayerStack *layerStack() const { return m_layerstack; }
	StateTracker *stateTracker() const { return m_statetracker; }
	UserCursorModel *userCursors() const { return m_usercursors; }
	LaserTrailModel *laserTrails() const { return m_lasers; }

	QString title() const { return m_title; }
	void setTitle(const QString &title) { if(m_title!=title) { m_title = title; emit titleChanged(title); } }

	QString pinnedMessage() const { return m_pinnedMessage; }

	canvasSelection *selection() const { return m_selection; }
	void setSelection(canvasSelection *selection);

	bool needsOpenRaster() const;
	QImage toImage() const;

	QList<protocol::MessagePtr> generateSnapshot(bool forceNew) const;  //截图

	int localUserId() const;

	int getAvailableAnnotationId() const;

	QImage selectionToImage(int layerId) const;
	void pasteFromImage(const QImage &image, const QPoint &defaultPoint, bool forceDefault);

	LayerListModel *layerlist() const { return m_layerlist; }

	/**
	 * @brief Is the canvas in "online mode"?
	 *
	 * This mainly affects how certain access controls are checked.
	 */
	bool isOnline() const { return m_mode == Mode::Online; }

	/**
	 * @brief Set the Writer to use for recording
	 */

public slots:
	//! Handle a meta/command message received from the server （处理一下设置，创建等问题）
	void handleCommand(protocol::MessagePtr cmd);

	//! Handle a local drawing command (will be put in the local fork)
	void handleLocalCommand(protocol::MessagePtr cmd);
	void setStateTrakerDotline(bool bDotline);
	void resetCanvas();

	void pickLayer(int x, int y);
	void pickColor(int x, int y, int layer, int diameter=0);

	void setLayerViewMode(int mode);
	void updateLayerViewOptions();

signals:
	void layerAutoselectRequest(int id);
	void canvasModified();
	void selectionChanged(canvasSelection *selection);
	void selectionRemoved();

	void titleChanged(QString title);
	void pinnedMessageChanged(QString message);
	void imageSizeChanged();

	void colorPicked(const QColor &color);

//	void canvasLocked(bool locked);

private slots:
	void onCanvasResize(int xoffset, int yoffset, const QSize &oldsize);

private:
	void metaLaserTrail(const protocol::LaserTrail &msg);
	void metaMovePointer(const protocol::MovePointer &msg);
	void metaDefaultLayer(const protocol::DefaultLayer &msg);

private:
	LayerListModel *m_layerlist;  //画板层列表，最少size=2，

	paintcore::LayerStack *m_layerstack;
	StateTracker *m_statetracker;  //所有操作的最终控制
	UserCursorModel *m_usercursors;
	LaserTrailModel *m_lasers;
	canvasSelection *m_selection;

	QString m_title;
	QString m_pinnedMessage; //固定的消息
	 
	enum class Mode { Offline, Online, Playback } m_mode;
};

}

#endif // CANVASSTATE_H
