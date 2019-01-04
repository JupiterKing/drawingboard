#include "test.h"
#include <QtWidgets/QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test w;
	w.show();

	/*QGraphicsScene scene;
	scene.addLine(0, 0, 150, 150);

	QGraphicsView view(&scene);
	view.setWindowTitle("Graphics View");
	view.resize(500, 500);
	view.show();*/

	/*BoardWidget* m_widget = new BoardWidget();
	m_widget->newDocument(QSize(980, 800), Qt::white);
	m_widget->resize(980, 800);
	m_widget->show();*/

	return a.exec();
}
