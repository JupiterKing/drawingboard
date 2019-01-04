#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test.h"
#include "boardwidget.h"

#ifdef Q_OS_OSX
#define CTRL_KEY "Meta"
#include "widgets/macmenu.h"
#else
#define CTRL_KEY "Ctrl"
#endif

class test : public QMainWindow
{
	Q_OBJECT

public:
	test(QWidget *parent = Q_NULLPTR);

public:
	QAction *makeAction(const char *name, const char *icon, const QString& text, const QString& tip = QString(), const QKeySequence& shortcut = QKeySequence(), bool checkable = false);
	QAction *getAction(const QString &name);
	void setupActions();
public slots:
	void selectTool(QAction *tool);
private:
	Ui::testClass ui;
	BoardWidget* m_widget;

	//
	QActionGroup *m_docadmintools; // current document related operator actions
	QActionGroup *m_drawingtools; // drawing tool selection
	QActionGroup *m_brushSlots; // tool slot shortcuts
	//
};
