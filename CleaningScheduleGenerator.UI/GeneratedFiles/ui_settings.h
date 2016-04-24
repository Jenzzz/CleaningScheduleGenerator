/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *updateButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QStringLiteral("settings"));
        settings->setWindowModality(Qt::NonModal);
        settings->setEnabled(true);
        settings->resize(400, 700);
        settings->setMinimumSize(QSize(400, 700));
        settings->setMaximumSize(QSize(400, 700));
        settings->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/icon32.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings->setWindowIcon(icon);
        verticalLayoutWidget = new QWidget(settings);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 10, 321, 681));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout_2->addLayout(gridLayout);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 20, -1, -1);
        updateButton = new QPushButton(verticalLayoutWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout_2->addWidget(updateButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(settings);

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QWidget *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "settings", 0));
        updateButton->setText(QApplication::translate("settings", "Update", 0));
        cancelButton->setText(QApplication::translate("settings", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
