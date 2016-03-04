#include "settings.h"

#include <QMessageBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QLabel>

using namespace std;

settings::settings(QWidget * parent) : QWidget(parent)
{
	ui.setupUi(this);

	//// Connect button signal to appropriate slot
	connect(ui.updateButton, SIGNAL(released()), this, SLOT(handleUpdateButton()));
	connect(ui.cancelButton, SIGNAL(released()), this, SLOT(close()));
}

settings::settings(vector<Room*> rooms)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::SubWindow);
	this->setWindowFlags(Qt::WindowStaysOnTopHint);
	this->activateWindow();

	connect(ui.updateButton, SIGNAL(released()), this, SLOT(handleUpdateButton()));
	connect(ui.cancelButton, SIGNAL(released()), this, SLOT(close()));

	QLabel* roomNumberText = new QLabel("Kamernummer");
	QLabel* habitansText = new QLabel("Huisgenoten");
	QLabel* nestorText = new QLabel("Huisoudste?");

	ui.gridLayout->addWidget(roomNumberText, 0, 0, Qt::AlignTop);
	ui.gridLayout->addWidget(habitansText, 0, 1, Qt::AlignTop);
	ui.gridLayout->addWidget(nestorText, 0, 2, Qt::AlignTop);

	unsigned int rowIndex = 1;

	for each (Room* room in rooms)
	{
		char buffer[10] = { 0 };
		itoa(room->RoomNumber, buffer, 10);
		QLabel* roomNumberLabel = new QLabel(buffer);
		
		QLineEdit* habitantNameEdit = new QLineEdit(room->Habitant->Name.c_str());
		QRadioButton* nestorCheckBox = new QRadioButton();
		
		nestorCheckBox->setChecked(room->Habitant->IsNestor);

		ui.gridLayout->addWidget(roomNumberLabel, rowIndex, 0, Qt::AlignTop);
		ui.gridLayout->addWidget(habitantNameEdit, rowIndex, 1, Qt::AlignTop);
		ui.gridLayout->addWidget(nestorCheckBox, rowIndex, 2, Qt::AlignTop);

		rowIndex++;
	}
}

void settings::handleUpdateButton()
{



	QMessageBox msgBox;
	msgBox.setWindowTitle("Hello");
	msgBox.setText("You Clicked " + ((QPushButton*)sender())->text());
	msgBox.exec();

	close();
}

settings::~settings() {
	
}
