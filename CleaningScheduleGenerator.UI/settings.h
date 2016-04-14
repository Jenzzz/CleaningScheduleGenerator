#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#include <QWidget>
#include "ui_settings.h"
#include "room.h"
#include "RoomRepository.h"
#include "person.h"
#include <QRadioButton>

class settings : public QWidget 
{
	Q_OBJECT

public:
	settings(QWidget * parent = Q_NULLPTR);
	settings(vector<Room*>);
	~settings();

private slots:
	void handleUpdateButton();
	void handleUpdateRadioButton();
	void handleUpdateButton12();
private:
	Ui::settings ui;
	vector<int> fieldsToUpdate;
	vector<Room*> rooms;
};

#endif // !SETTINGS_H