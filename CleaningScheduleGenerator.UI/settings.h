#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "ui_settings.h"

class settings : public QWidget 
{
	Q_OBJECT

public:
	settings(QWidget * parent = Q_NULLPTR);
	~settings();

private slots:
	void handleButton();
private:
	Ui::settings ui;
};

#endif // !SETTINGS_H