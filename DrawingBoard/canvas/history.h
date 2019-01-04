#ifndef CANVAS_HISTORY_H
#define CANVAS_HISTORY_H

#include <QList>

#include "net/message.h"

namespace canvas {

/**
 * @brief Sequence of messages to reproduce the canvas state
 *
 * The whole session history might not be in memory, but it
 * should always contain enough messages to reach
 * end of the Undo history.
 */
class History {
public:
	History();

	/**
	 * @brief Get the current stream offset
	 *
	 * The indexes of the messages in the stream should not change
	 * even if older parts of it are discarded to save memory.
	 *
	 * @return index of first stored message
	 */
	int offset() const { return m_offset; }

	/**
	 * @brief Get the end index of the stream
	 * @return
	 */
	int end() const { return m_offset + m_messages.size(); }

	/**
	 * @brief Check if a message at the given index is in memory
	 * @param i
	 * @return true if message can be got with at(i)
	 */
	bool isValidIndex(int i) const { return i >= offset() && i < end(); }

	/**
	 * @brief at Get the message at the given index
	 */
	protocol::MessagePtr at(int pos) const { return m_messages.at(pos-m_offset); }

	/**
	 * @brief Add a new command to the stream
	 * @param msg command to add
	 */
	void append(protocol::MessagePtr msg);

	/**
	 * @brief Delete old messages
	 *
	 * Delete old messages until the tail of undo history or the given
	 * limit is reached.
	 * @param indexlimit index of first protected message
	 * @pre indexlimit <= end()
	 */
	void cleanup(int indexlimit);

	/**
	 * @brief Remove all messages and change the offset
	 *
	 * @param newoffset
	 */
	void resetTo(int newoffset);

	/**
	 * @brief Get the length of the stored message stream in bytes.
	 *
	 * This returns the length of the serialized messages, not the in-memory
	 * representation.
	 * @return (serialized) length in bytes
	 */
	uint lengthInBytes() const { return m_bytes; }

	/**
	 * @brief return the whole stream as a list
	 * @return list of messages
	 */
	QList<protocol::MessagePtr> toList() const { return m_messages; }

private:
	QList<protocol::MessagePtr> m_messages;
	int m_offset;
	uint m_bytes;
};

}

#endif

