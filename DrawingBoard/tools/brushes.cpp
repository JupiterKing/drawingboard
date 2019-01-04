/*
   Drawpile - a collaborative drawing program.

   Copyright (C) 2006-2017 Calle Laakkonen

   Drawpile is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Drawpile is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Drawpile.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "paintcore/brush.h"
#include "net/commands.h"

#include "tools/toolcontroller.h"
#include "tools/brushes.h"

#include "../net/undo.h"
#include "../net/pen.h"

#include <QPixmap>

namespace tools {

Freehand::Freehand(ToolController &owner, bool isEraser)
	: Tool(owner, isEraser ? ERASER : FREEHAND, Qt::CrossCursor)
{
}

void Freehand::begin(const paintcore::Point& point, bool right, float zoom)
{
	Q_UNUSED(zoom);
	Q_UNUSED(right);

	QList<protocol::MessagePtr> msgs;
	msgs << protocol::MessagePtr(new protocol::UndoPoint(owner.myId()));

	msgs << net::command::brushToToolChange(owner.myId(), owner.activeLayer(), owner.activeBrush());
	protocol::PenPointVector v(1);
	v[0] = net::command::pointToProtocol(point);
	msgs << protocol::MessagePtr(new protocol::PenMove(owner.myId(), v));
	owner.sendMessages(msgs);
}

void Freehand::motion(const paintcore::Point& point, bool constrain, bool center)
{
	Q_UNUSED(constrain);
	Q_UNUSED(center);

	protocol::PenPointVector v(1);
	v[0] = net::command::pointToProtocol(point);
	owner.sendMessage(protocol::MessagePtr(new protocol::PenMove(owner.myId(), v)));
}

void Freehand::end()
{
	owner.sendMessage(protocol::MessagePtr(new protocol::PenUp(owner.myId())));
}

}

