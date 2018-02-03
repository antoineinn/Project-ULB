/********************************************************************************
** Form generated from reading UI file 'showinfogame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWINFOGAME_H
#define UI_SHOWINFOGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowInfoGame
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *IngameInfo;
    QLabel *label_2;

    void setupUi(QDialog *ShowInfoGame)
    {
        if (ShowInfoGame->objectName().isEmpty())
            ShowInfoGame->setObjectName(QStringLiteral("ShowInfoGame"));
        ShowInfoGame->resize(434, 434);
        gridLayout = new QGridLayout(ShowInfoGame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ShowInfoGame);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("PlayerInfo.png")));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        IngameInfo = new QLineEdit(ShowInfoGame);
        IngameInfo->setObjectName(QStringLiteral("IngameInfo"));
        IngameInfo->setReadOnly(true);

        verticalLayout->addWidget(IngameInfo);

        label_2 = new QLabel(ShowInfoGame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("down.png")));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ShowInfoGame);

        QMetaObject::connectSlotsByName(ShowInfoGame);
    } // setupUi

    void retranslateUi(QDialog *ShowInfoGame)
    {
        ShowInfoGame->setWindowTitle(QApplication::translate("ShowInfoGame", "Dialog", 0));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShowInfoGame: public Ui_ShowInfoGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWINFOGAME_H
