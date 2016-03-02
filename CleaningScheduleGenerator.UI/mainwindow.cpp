#include "mainwindow.h"

#include <iostream>
#include <sstream>
#include <ctime>
#include <time.h>
#include <string>
#include <QMessageBox>

#include "FilenameHelper.h"
#include "CleaningSchedule.h"
#include "WritePdf.h"
#include "dateHelper.h"
#include "settings.h"

using namespace std;

vector<tm> dateTimes;

MainWindow::MainWindow(QMainWindow  *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	DataBind();

	connect(ui.pushButton, SIGNAL(released()), this, SLOT(handleButton()));
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.actionPreferences, SIGNAL(triggered()), this, SLOT(handleSettings()));
}

void MainWindow::handleSettings()
{
	
}

void MainWindow::DataBind()
{
	unsigned int weekAmount = 8;

	time_t t = time(0);   // get time now
	tm startDate;
	localtime_s(&startDate, &t);
	startDate.tm_year;
	
	dateTimes = GetMondaysFrom(startDate, 8);

	for (unsigned int i = 0; i < weekAmount; i++)
	{
		char buffer[60] = { 0 };
		strftime(buffer, sizeof(buffer), "%A %d %B %Y", &dateTimes[i]);

		ui.comboBox->addItem(buffer, QString::number(i));
	}
}

void MainWindow::handleButton()
{
	int index =	ui.comboBox->currentIndex();

	tm dateTime = dateTimes[index];
	
	// generate schedule
	CleaningSchedule* cleaningSchedule = new CleaningSchedule();
	vector<WeekSchedule> cleaningScheduleMap = cleaningSchedule->Generate(dateTime);

	string fileName = ConstructFilename(dateTime);

	WritePdf* writePdf = new WritePdf();
	writePdf->WriteToFile(cleaningScheduleMap, fileName);

	QMessageBox msgBox;
	msgBox.setWindowTitle("Hello");
	msgBox.setText("You Clicked " + ((QPushButton*)sender())->text());
	msgBox.exec();
}

MainWindow::~MainWindow()
{
}
