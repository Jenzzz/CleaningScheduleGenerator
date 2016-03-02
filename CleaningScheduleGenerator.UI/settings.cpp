#include "settings.h"

#include <QMessageBox>

using namespace std;

settings::settings(QWidget * parent) : QWidget(parent)
{
	ui.setupUi(this);

	// Fill the items of the ComboBox
	//for (int i = 0; i < 10; i++)
	//{
	//	ui.comboBox->addItem("item " + QString::number(i));
	//}

	//// Connect button signal to appropriate slot
	//connect(ui.pushButton, SIGNAL(released()), this, SLOT(handleButton()));
}

void settings::handleButton()
{
	QMessageBox msgBox;
	msgBox.setWindowTitle("Hello");
	msgBox.setText("You Clicked " + ((QPushButton*)sender())->text());
	msgBox.exec();
}

settings::~settings() {
	
}
