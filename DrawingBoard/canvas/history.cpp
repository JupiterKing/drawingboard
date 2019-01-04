#include "history.h"
#include "net/undo.h"

namespace canvas {

using namespace protocol;

History::History()
	: m_offset(0), m_bytes(0)
{
}

void History::append(MessagePtr msg)
{
	m_messages.append(msg);
	m_bytes += msg->length();
}

void History::cleanup(int indexlimit)
{
	Q_ASSERT(indexlimit <= end());

	// First, find the index of the last protected undo point
	int undo_point = m_offset;
	int undo_points = 0;
	for(int i=end()-1;i>=offset() && undo_points<UNDO_DEPTH_LIMIT;--i) {
		if(at(i)->type() == MSG_UNDOPOINT) {
			undo_point = i;
			++undo_points;
		}
	}

	if(undo_point < indexlimit)
		indexlimit = undo_point;

	// Remove oldest messages
	while(m_offset < indexlimit) {
		m_bytes -= m_messages.takeFirst()->length();
		++m_offset;
	}
}

void History::resetTo(int newoffset)
{
	Q_ASSERT(newoffset >= 0);
	m_offset = newoffset;
	m_messages.clear();
	m_bytes = 0;
}

}
