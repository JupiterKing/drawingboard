#ifndef DP_SESSION_LOADER_H
#define DP_SESSION_LOADER_H

#include <QSize>
#include <QColor>
#include <QString>
#include <QImage>

#include "net/message.h"
#include "layerlist.h"

namespace paintcore {
	class LayerStack;
}

namespace canvas {

class CanvasModel;

/**
 * \brief Base class for session initializers.
 * ³õÊ¼»¯Æ÷
 * Note. The initializers make two assumptions: they are running in
 * loopback mode and that the session has not already been initialized.
 * 
 * These assumptions allow the initializers to pick the initial layer/annotation
 * IDs.
 */
class SessionLoader {
public:
	virtual ~SessionLoader() {}
	
	/**
	 * @brief Get the commands needed to initialize the session.
	 *
	 * The commands should be sent to the server in response to a snapshot request,
	 * or when initializing the session in local mode.
	 *
	 * @param client
	 * @return empty list if an error occurred
	 */
	virtual QList<protocol::MessagePtr> loadInitCommands() = 0;

	/**
	 * @brief Get the error message
	 *
	 * The error message is available if loadInitCommands() returns false.
	 * @return error message
	 */
	virtual QString errorMessage() const = 0;

	/**
	 * @brief Get the warning message (if any)
	 */
	virtual QString warningMessage() const { return QString(); }

	/**
	 * @brief get the name of the file
	 *
	 * This if for image loaders. If there is no file (that can be saved again),
	 * this function should return an empty string.
	 * @return filename or empty string
	 */
	virtual QString filename() const = 0;
};

//////////////////////////////////////////////////////////////////////////
//¿Õ°×»­²¼
//////////////////////////////////////////////////////////////////////////
class BlankCanvasLoader : public SessionLoader {
public:
	BlankCanvasLoader(const QSize &size, const QColor &color) : _size(size), _color(color)
	{}
	
	QList<protocol::MessagePtr> loadInitCommands();
	QString filename() const { return QString(); }
	QString errorMessage() const { return QString(); /* cannot fail */ }

private:
	QSize _size;
	QColor _color;
};

//Í¼Æ¬ÎÄ¼þ¼ÓÔØÆ÷
class ImageCanvasLoader : public SessionLoader {
public:
	ImageCanvasLoader(const QString &filename) : m_filename(filename) {}
	
	QList<protocol::MessagePtr> loadInitCommands();
	QString filename() const { return m_filename; }
	QString errorMessage() const { return m_error; }
	QString warningMessage() const { return m_error; }

private:
	QString m_filename;
	QString m_error;
	QString m_warning;
};

//QImageÍ¼Æ¬¼ÓÔØÆ÷
class QImageCanvasLoader : public SessionLoader {
public:
	QImageCanvasLoader(const QImage &image) : _image(image) {}

	QList<protocol::MessagePtr> loadInitCommands();
	QString filename() const { return QString(); }
	QString errorMessage() const { return QString(); }

private:
	QImage _image;
};

/**
 * @brief A session loader that takes an existing layer stack and generates a new snapshot from it
 *  ½ØÍ¼ ¼ÓÔØÆ÷
 * If the optional canvas is given, extra data will be included.
 */
class SnapshotLoader : public SessionLoader {
public:
	/**
	 * Construct a snapshot from an existing session.
	 *
	 * @param context ID resetting user ID
	 * @param layers the layer stack (required)
	 * @param layerlist layer list info model. Used for layer ACLs. (optional)
	 * @param session the current canvas. Used for general session ACLs and such. (optional)
	 */
	SnapshotLoader(uint8_t contextId, const paintcore::LayerStack *layers, const QVector<LayerListItem> &layerlist, const canvas::CanvasModel *session)
		: m_layers(layers), m_layerlist(layerlist), m_session(session), m_contextId(contextId) {}

	QList<protocol::MessagePtr> loadInitCommands();
	QString filename() const { return QString(); }
	QString errorMessage() const { return QString(); }

private:
	const paintcore::LayerStack *m_layers;
	const QVector<LayerListItem> m_layerlist;
	const CanvasModel *m_session;
	uint8_t m_contextId;
};

}

#endif
