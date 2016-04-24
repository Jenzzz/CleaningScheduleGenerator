/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionPreferences;
    QAction *actionAbout;
    QAction *actionAbout_Cleaning_schedule_generator;
    QAction *actionGenerate;
    QAction *actionRemove_Room;
    QAction *actionAdd_Room;
    QAction *actionPrint;
    QAction *actionSave_as_pdf;
    QAction *actionNew_Schedule;
    QAction *actionOpen_Schedule;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QMenu *menuSchedule;
    QMenu *menuRoom;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(460, 350);
        MainWindow->setMinimumSize(QSize(460, 350));
        MainWindow->setMaximumSize(QSize(460, 350));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/icon32.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout->setShortcutContext(Qt::WindowShortcut);
        actionAbout_Cleaning_schedule_generator = new QAction(MainWindow);
        actionAbout_Cleaning_schedule_generator->setObjectName(QStringLiteral("actionAbout_Cleaning_schedule_generator"));
        actionGenerate = new QAction(MainWindow);
        actionGenerate->setObjectName(QStringLiteral("actionGenerate"));
        actionRemove_Room = new QAction(MainWindow);
        actionRemove_Room->setObjectName(QStringLiteral("actionRemove_Room"));
        actionAdd_Room = new QAction(MainWindow);
        actionAdd_Room->setObjectName(QStringLiteral("actionAdd_Room"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionSave_as_pdf = new QAction(MainWindow);
        actionSave_as_pdf->setObjectName(QStringLiteral("actionSave_as_pdf"));
        actionNew_Schedule = new QAction(MainWindow);
        actionNew_Schedule->setObjectName(QStringLiteral("actionNew_Schedule"));
        actionOpen_Schedule = new QAction(MainWindow);
        actionOpen_Schedule->setObjectName(QStringLiteral("actionOpen_Schedule"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 40, 331, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 460, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuSchedule = new QMenu(menubar);
        menuSchedule->setObjectName(QStringLiteral("menuSchedule"));
        menuRoom = new QMenu(menuSchedule);
        menuRoom->setObjectName(QStringLiteral("menuRoom"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSchedule->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Schedule);
        menuFile->addAction(actionOpen_Schedule);
        menuFile->addAction(actionSave_as_pdf);
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuSettings->addAction(actionPreferences);
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_Cleaning_schedule_generator);
        menuSchedule->addAction(actionGenerate);
        menuSchedule->addSeparator();
        menuSchedule->addAction(menuRoom->menuAction());
        menuRoom->addAction(actionAdd_Room);
        menuRoom->addAction(actionRemove_Room);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Cleaning Schedule Generator", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "Help", 0));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionAbout_Cleaning_schedule_generator->setText(QApplication::translate("MainWindow", "About CSG", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout_Cleaning_schedule_generator->setToolTip(QApplication::translate("MainWindow", "About Cleaning Schedule Generator", 0));
#endif // QT_NO_TOOLTIP
        actionGenerate->setText(QApplication::translate("MainWindow", "Generate", 0));
        actionRemove_Room->setText(QApplication::translate("MainWindow", "Remove Room", 0));
        actionAdd_Room->setText(QApplication::translate("MainWindow", "Add Room", 0));
        actionPrint->setText(QApplication::translate("MainWindow", "Print...", 0));
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionSave_as_pdf->setText(QApplication::translate("MainWindow", "Save as .pdf", 0));
        actionNew_Schedule->setText(QApplication::translate("MainWindow", "New Schedule", 0));
        actionOpen_Schedule->setText(QApplication::translate("MainWindow", "Open Schedule", 0));
        label->setText(QApplication::translate("MainWindow", "Select starting week", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Generate schedule", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuSchedule->setTitle(QApplication::translate("MainWindow", "Schedule", 0));
        menuRoom->setTitle(QApplication::translate("MainWindow", "Rooms", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
