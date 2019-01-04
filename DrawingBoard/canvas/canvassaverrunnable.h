#ifndef CANVASSAVERRUNNABLE_H
#define CANVASSAVERRUNNABLE_H

#include <QObject>
#include <QRunnable>

namespace paintcore {
    class LayerStack;
}

namespace canvas {

class CanvasModel;


/**
 * @brief A runnable for saving a canvas in a background thread
 *  在后台线程中保存画布的可运行程序
 * When constructed, a copy of the layerstack is made.
 */
class CanvasSaverRunnable : public QObject, public QRunnable
{
	Q_OBJECT
public:
	CanvasSaverRunnable(const CanvasModel *canvas, const QString &filename, QObject *parent = nullptr);

	void run() override;

signals:
	/**
	 * @brief Emitted once the file has been saved
	 * @param error the error message (blank string if no error occurred)
	 */
	void saveComplete(const QString &error);

private:
	paintcore::LayerStack *m_layerstack;
	QString m_filename;
};

}

#endif
