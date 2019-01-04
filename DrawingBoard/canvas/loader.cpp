#include "loader.h"
#include "net/commands.h"
#include "canvas/canvasmodel.h"
#include "canvas/layerlist.h"
#include "paintcore/layerstack.h"
#include "paintcore/layer.h"

#include "net/layerMsg.h"
#include "net/annotationMsg.h"
#include "net/meta2.h"
#include "net/image.h"

#include <QDebug>
#include <QGuiApplication>
#include <QImage>
#include <QImageReader>

namespace canvas {

using protocol::MessagePtr;

QList<MessagePtr> BlankCanvasLoader::loadInitCommands()
{
	QList<MessagePtr> msgs;

	msgs.append(MessagePtr(new protocol::CanvasResize(1, 0, _size.width(), _size.height(), 0)));
    msgs.append(MessagePtr(new protocol::LayerCreate(1, 0x0101, 0, _color.rgba(), 0, QGuiApplication::tr("Background"))));   //id:257
    msgs.append(MessagePtr(new protocol::LayerCreate(1, 0x0102, 0, 0, 0, QGuiApplication::tr("Foreground"))));   //id:258
	return msgs;
}

QList<MessagePtr> ImageCanvasLoader::loadInitCommands()
{
	// Load an image using Qt's image loader.
	// If the image is animated, each frame is loaded as a layer
	QList<MessagePtr> msgs;
	QImageReader ir(m_filename);
	int layerId = 1;

	while(true) {
		QImage image = ir.read();

		if(image.isNull()) {
			if(layerId>1)
				break;
			m_error = ir.errorString();
			return QList<MessagePtr>();
		}

		if(layerId==1) {
			msgs << MessagePtr(new protocol::CanvasResize(1, 0, image.size().width(), image.size().height(), 0));
		}

		image = image.convertToFormat(QImage::Format_ARGB32);
		msgs << MessagePtr(new protocol::LayerCreate(1, layerId, 0, 0, 0, QStringLiteral("Layer %1").arg(layerId)));
		msgs << net::command::putQImage(1, layerId, 0, 0, image, paintcore::BlendMode::MODE_REPLACE);
		++layerId;
	}

	return msgs;
}

QList<MessagePtr> QImageCanvasLoader::loadInitCommands()
{
	QList<MessagePtr> msgs;

	QImage image = _image.convertToFormat(QImage::Format_ARGB32);

	msgs.append(MessagePtr(new protocol::CanvasResize(1, 0, image.size().width(), image.size().height(), 0)));
	msgs.append(MessagePtr(new protocol::LayerCreate(1, 1, 0, 0, 0, "Background")));
	msgs.append(net::command::putQImage(1, 1, 0, 0, image, paintcore::BlendMode::MODE_REPLACE));

	return msgs;
}

QList<MessagePtr> SnapshotLoader::loadInitCommands()
{
	QList<MessagePtr> msgs;

	// Most important bit first: canvas initialization
	const QSize imgsize = m_layers->size();
	msgs.append(MessagePtr(new protocol::CanvasResize(m_contextId, 0, imgsize.width(), imgsize.height(), 0)));

	// Preset default layer
	if(m_session && m_session->layerlist()->defaultLayer()>0)
		msgs.append(MessagePtr(new protocol::DefaultLayer(m_contextId, m_session->layerlist()->defaultLayer())));

	// Add pinned message (if any)
//	if(m_session && !m_session->pinnedMessage().isEmpty()) {
//		msgs.append(protocol::Chat::pin(m_contextId, m_session->pinnedMessage()));
//	}

	// Create layers
	for(int i=0;i<m_layers->layerCount();++i) {
		const paintcore::Layer *layer = m_layers->getLayerByIndex(i);

		const QColor fill = layer->isSolidColor();

		msgs.append(MessagePtr(new protocol::LayerCreate(m_contextId, layer->id(), 0, fill.isValid() ? fill.rgba() : 0, 0, layer->title())));
		msgs.append(MessagePtr(new protocol::LayerAttributes(m_contextId, layer->id(), layer->opacity(), 1)));

		if(!fill.isValid())
			msgs.append(net::command::putQImage(m_contextId, layer->id(), 0, 0, layer->toImage(), paintcore::BlendMode::MODE_REPLACE));

		// Set extra layer info (if present)
//		for(int j=0;j<m_layerlist.size();++j) {
//			if(m_layerlist[j].id == layer->id()) {
//				const LayerListItem &info = m_layerlist[j];
//				if(info.locked || !info.exclusive.isEmpty())
//					msgs.append(MessagePtr(new protocol::LayerACL(m_contextId, layer->id(), info.locked, info.exclusive)));
//			}
//		}
	}

	// Create annotations
	for(const paintcore::Annotation &a : m_layers->annotations()->getAnnotations()) {
		const QRect g = a.rect;
		msgs.append(MessagePtr(new protocol::AnnotationCreate(m_contextId, a.id, g.x(), g.y(), g.width(), g.height())));
		msgs.append((MessagePtr(new protocol::AnnotationEdit(m_contextId, a.id, a.background.rgba(), a.flags(), 0, a.text))));
	}

	return msgs;
}

}

