/********************************************************************************
** Form generated from reading UI file 'towerpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOWERPANEL_H
#define UI_TOWERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TowerPanel
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *TowerPanel)
    {
        if (TowerPanel->objectName().isEmpty())
            TowerPanel->setObjectName(QStringLiteral("TowerPanel"));
        TowerPanel->resize(197, 292);
        gridLayout = new QGridLayout(TowerPanel);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(TowerPanel);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QIcon icon;
        icon.addFile(QStringLiteral("basic.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(60, 60));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(TowerPanel);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("bomb.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(60, 60));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton = new QPushButton(TowerPanel);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("heavy.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(60, 60));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);


        retranslateUi(TowerPanel);

        QMetaObject::connectSlotsByName(TowerPanel);
    } // setupUi

    void retranslateUi(QDialog *TowerPanel)
    {
        TowerPanel->setWindowTitle(QApplication::translate("TowerPanel", "Dialog", 0));
        pushButton_2->setText(QApplication::translate("TowerPanel", "Basic Tower", 0));
        pushButton_3->setText(QApplication::translate("TowerPanel", "Bomb Tower", 0));
        pushButton->setText(QApplication::translate("TowerPanel", "Heavy Tower", 0));
    } // retranslateUi

};

namespace Ui {
    class TowerPanel: public Ui_TowerPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOWERPANEL_H
