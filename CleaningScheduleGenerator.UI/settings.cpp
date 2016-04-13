#include "settings.h"

#include <QMessageBox>
#include <QLineEdit>

#include <QLabel>
#include <iostream>

using namespace std;

settings::settings(QWidget * parent) : QWidget(parent)
{
	ui.setupUi(this);

	// Connect button signal to appropriate slot
	connect(ui.updateButton, SIGNAL(released()), this, SLOT(handleUpdateButton()));
	connect(ui.cancelButton, SIGNAL(released()), this, SLOT(close()));
}

settings::settings(vector<Room*> rooms)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::SubWindow);
	this->setWindowFlags(Qt::WindowStaysOnTopHint);
	this->activateWindow();

	connect(ui.updateButton, SIGNAL(released()), this, SLOT(handleUpdateButton12()));
	connect(ui.cancelButton, SIGNAL(released()), this, SLOT(close()));

	QLabel* roomNumberText = new QLabel("Kamernummer");
	roomNumberText->setObjectName("Kamernummer");
	QLabel* habitansText = new QLabel("Huisgenoten");
	habitansText->setObjectName("Huisgenoten");
	QLabel* nestorText = new QLabel("Huisoudste?");
	nestorText->setObjectName("Huisoudste?");

	if (!ui.gridLayout->findChild<QLabel*>("Kamernummer"))
	{
		ui.gridLayout->addWidget(roomNumberText, 0, 0, Qt::AlignTop);
		ui.gridLayout->addWidget(habitansText, 0, 1, Qt::AlignTop);
		ui.gridLayout->addWidget(nestorText, 0, 2, Qt::AlignTop);
	}

	unsigned int rowIndex = 1;

	for each (Room* room in rooms)
	{
		char buffer[10] = { 0 };
		itoa(room->RoomNumber, buffer, 10);
		QLabel* roomNumberLabel = new QLabel(buffer);
		
		QLineEdit* habitantNameEdit = new QLineEdit(room->Habitant->Name.c_str());
		habitantNameEdit->setPlaceholderText("Person");
		habitantNameEdit->setObjectName(QString::fromStdString(string(buffer) + "_" + string("habitant")));
		QRadioButton* nestorCheckBox = new QRadioButton();
		nestorCheckBox->setChecked(room->Habitant->IsNestor);

		ui.gridLayout->addWidget(roomNumberLabel, rowIndex, 0, Qt::AlignTop);
		ui.gridLayout->addWidget(habitantNameEdit, rowIndex, 1, Qt::AlignTop);
		ui.gridLayout->addWidget(nestorCheckBox, rowIndex, 2, Qt::AlignTop);

		// Connect button signal to appropriate slot
		connect(habitantNameEdit, SIGNAL(textChanged(const QString &)), this, SLOT(handleUpdateButton()));
		connect(nestorCheckBox, SIGNAL(clicked()), this, SLOT(handleUpdateRadioButton()));

		rowIndex++;
	}
}

void settings::handleUpdateButton12()
{
	QObject *object = QObject::sender();
	QPushButton* qPushButton = qobject_cast<QPushButton*>(object);

	if (qPushButton != NULL)
	{
		QMessageBox::information(this, "Title", qPushButton->text());
	}
}

void settings::handleUpdateButton()
{
	QObject *object = QObject::sender();
	QLineEdit* qLineEdit = qobject_cast<QLineEdit*>(object);

	if (qLineEdit != NULL)
	{
		QMessageBox::information(this, "Title                                ", qLineEdit->objectName());
		QMessageBox::information(this, "Title                                ", qLineEdit->text());

		RoomRepository* rr = new RoomRepository();

		vector <string> fields;

		string::size_type pos = qLineEdit->objectName().toStdString().find_first_of("_");

		string roomId = qLineEdit->objectName().toStdString().substr(0, pos);

		/*while (pos != string::npos) {
			cout << "Found space or dot at: " << pos << endl;
			pos = qLineEdit->objectName().toStdString().find_first_of(" .", pos + 1);
		}*/

		Person* p = new Person();
		//p->
		

		Room* r = new Room(stoi(roomId), *p);
		


		rr->UpdateRoom(r);

		//RoomRepository rr;
		//for each (Room* r in rooms)
		//{
		//	//qLineEdit->objectName.text();

		//	/*if (qLineEdit->objectName.text.compare(r->Habitant->Name))
		//	{
		//	r->Habitant->Name = qLineEdit->text().toStdString();

		//	rr.UpdateRoom(r);
		//	}*/
		//}

		/*QMessageBox msgBox;
		msgBox.setWindowTitle("Hello");
		msgBox.setText("You Clicked " + ((QPushButton*)sender())->text());
		msgBox.exec();*/
	}

	//close();
}

void settings::handleUpdateRadioButton()
{
	QObject *object = sender();
	QRadioButton* qRadioButton = qobject_cast<QRadioButton*>(object);

	if (qRadioButton != NULL)
	{
		QMessageBox::information(this, "Title", qRadioButton->text());
		//string s = pbtn->objectName;
	}

	//QCheckBox *q = qobject_cast<QCheckBox*>(ui->myWidget->children().at(i));
	
	close();
}

settings::~settings() {
	
}
