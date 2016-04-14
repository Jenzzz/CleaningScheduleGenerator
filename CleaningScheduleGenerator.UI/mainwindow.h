#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qmainwindow.h>
#include <vector>
#include "ui_mainwindow.h"
#include "room.h"
#include "settings.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QMainWindow *parent = 0);
	~MainWindow();
	vector<Room*> rooms;
	settings* set;
private slots:
	void handleButton();
	void handleSettings();
private:
	Ui::MainWindow ui;
	void DataBind();
	
};

#endif // MAINWINDOW_H
