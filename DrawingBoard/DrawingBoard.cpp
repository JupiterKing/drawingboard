#include "DrawingBoard.h"
#include "boardwidget.h"

DrawingBoard::DrawingBoard(QWidget * parent)
{

}

DrawingBoard* DrawingBoard::create(QWidget * parent /*= nullptr*/) noexcept
{
	return (new (std::nothrow) BoardWidget(parent));
}
