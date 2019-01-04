/************************************************************************/
/*  这是一个与UI无关的类，应该可以从基于小部件的应用程序或纯QML应用程序中使用。*/
/************************************************************************/
#pragma once
#include "paintcore/blendmodes.h"
#include <QObject>
#include <QStringListModel>
#include "drawingboard_global.h"

class QString;
class QTimer;
class QJsonValue;

namespace canvas {
	class CanvasModel;
	class SessionLoader;
	class StateSavepoint;
}

namespace net {
	class BanlistModel;
	class AnnouncementListModel;
}
namespace tools {
	class ToolController;
}

class DRAWINGBOARD_EXPORT Document :public QObject
{
	Q_PROPERTY(canvas::CanvasModel* canvas READ canvas() NOTIFY canvasChanged)
		Q_PROPERTY(QString currentFilename READ currentFilename() NOTIFY currentFilenameChanged)

		Q_OBJECT
public:
	explicit Document(QObject* parent = nullptr);
	~Document();

	QString title()const;
	canvas::CanvasModel* canvas()const { return m_canvas; }
	tools::ToolController* toolCtrl()const { return m_toolctrl; }

	void initCanvas();
	bool loadCanvas(canvas::SessionLoader &loader);
	void saveCanvas(const QString &filename);
	QString sessionTitle()const;
	QString currentFilename()const { return m_currentFilename; }

	QString roomcode()const { return m_roomcode; }

signals:
	void canvasChanged(canvas::CanvasModel *canvas);
	void dirtyCanvas(bool isDiaty); //修改画布
	void autosaveChanged(bool autosave);
	void cnaAutosaveChanged(bool canAutosave);
	void currentFilenameChanged(const QString &filename);
	void autoResetTooLarge(int maxSize);
	void catchupProgress(int perent);
	void canvasSaveStarted();
	void canvasSaved(const QString &errorMessage);

public slots:
	void sendPointerMove(const QPointF &point);
	void sendResizeCanvas(int top, int right, int bottom, int left);
	//工具相关
	void undo(); //撤销
	void redo(); //重做
	void selectAll();
	void selectNone();
	void cancelSelection(); //

	void copyVisible();
	void copyLayer();
	void cutLayer();
	void pasteImage(const QImage &image, const QPoint &point, bool forcePoint);
	void stamp();

	void removeEmptyAnnotations();
	void fillArea(const QColor &color, paintcore::BlendMode::Mode mode);

private slots:
	void snapshotNeeded();
	void markDirty();
	void unmarkDirty();

	void autosaveNow();
	void onCanvasSaved(const QString &errorMessage);

private:
	void saveCanvas();
	void setCurrentFilename(const QString &filename);
	void copyFromLayer(int layer);
private:
	QString		m_currentFilename;
	canvas::CanvasModel* m_canvas;
	tools::ToolController* m_toolctrl;
	bool		m_autoRecordOnConnect;
	QString		m_roomcode;
};