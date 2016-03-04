#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#include <QWidget>
#include "ui_settings.h"
#include "room.h"

class settings : public QWidget 
{
	Q_OBJECT

public:
	settings(QWidget * parent = Q_NULLPTR);
	settings(vector<Room*>);
	~settings();

private slots:
	void handleUpdateButton();
private:
	Ui::settings ui;
};

#endif // !SETTINGS_H