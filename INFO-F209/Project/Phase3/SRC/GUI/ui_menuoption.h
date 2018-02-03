/********************************************************************************
** Form generated from reading UI file 'menuoption.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUOPTION_H
#define UI_MENUOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuOption
{
public:
    QWidget *verticalLayoutWidget;
    QGridLayout *gridLayout_6;
    QGroupBox *support;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *supportButton;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *profil;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *showProfilButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *ranking;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *showRankingButton;
    QGroupBox *friendMenu;
    QGridLayout *gridLayout_4;
    QPushButton *showFriendButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *deconnexion;
    QGridLayout *gridLayout_5;
    QPushButton *leaveButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *play;
    QGridLayout *gridLayout_7;
    QPushButton *playButton;
    QRadioButton *timeButton;
    QRadioButton *vsButton;
    QRadioButton *teamButton;
    QLabel *label;
    QLabel *gifLabel;
    QLabel *titleLabel;

    void setupUi(QDialog *MenuOption)
    {
        if (MenuOption->objectName().isEmpty())
            MenuOption->setObjectName(QStringLiteral("MenuOption"));
        MenuOption->resize(880, 950);
        verticalLayoutWidget = new QWidget(MenuOption);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(310, 80, 261, 661));
        gridLayout_6 = new QGridLayout(verticalLayoutWidget);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        support = new QGroupBox(verticalLayoutWidget);
        support->setObjectName(QStringLiteral("support"));
        gridLayout = new QGridLayout(support);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        supportButton = new QPushButton(support);
        supportButton->setObjectName(QStringLiteral("supportButton"));

        gridLayout->addWidget(supportButton, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 0, 1, 1);


        gridLayout_6->addWidget(support, 1, 0, 1, 1);

        profil = new QGroupBox(verticalLayoutWidget);
        profil->setObjectName(QStringLiteral("profil"));
        gridLayout_2 = new QGridLayout(profil);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        showProfilButton = new QPushButton(profil);
        showProfilButton->setObjectName(QStringLiteral("showProfilButton"));

        gridLayout_2->addWidget(showProfilButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_6->addWidget(profil, 2, 0, 1, 1);

        ranking = new QGroupBox(verticalLayoutWidget);
        ranking->setObjectName(QStringLiteral("ranking"));
        gridLayout_3 = new QGridLayout(ranking);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 37, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        showRankingButton = new QPushButton(ranking);
        showRankingButton->setObjectName(QStringLiteral("showRankingButton"));

        gridLayout_3->addWidget(showRankingButton, 1, 2, 1, 1);


        gridLayout_6->addWidget(ranking, 3, 0, 1, 1);

        friendMenu = new QGroupBox(verticalLayoutWidget);
        friendMenu->setObjectName(QStringLiteral("friendMenu"));
        gridLayout_4 = new QGridLayout(friendMenu);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        showFriendButton = new QPushButton(friendMenu);
        showFriendButton->setObjectName(QStringLiteral("showFriendButton"));

        gridLayout_4->addWidget(showFriendButton, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(41, 37, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 1, 3, 1, 1);


        gridLayout_6->addWidget(friendMenu, 4, 0, 1, 1);

        deconnexion = new QGroupBox(verticalLayoutWidget);
        deconnexion->setObjectName(QStringLiteral("deconnexion"));
        gridLayout_5 = new QGridLayout(deconnexion);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        leaveButton = new QPushButton(deconnexion);
        leaveButton->setObjectName(QStringLiteral("leaveButton"));

        gridLayout_5->addWidget(leaveButton, 1, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(41, 37, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 1, 3, 1, 1);


        gridLayout_6->addWidget(deconnexion, 5, 0, 1, 1);

        play = new QGroupBox(verticalLayoutWidget);
        play->setObjectName(QStringLiteral("play"));
        gridLayout_7 = new QGridLayout(play);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        playButton = new QPushButton(play);
        playButton->setObjectName(QStringLiteral("playButton"));

        gridLayout_7->addWidget(playButton, 4, 0, 1, 1);

        timeButton = new QRadioButton(play);
        timeButton->setObjectName(QStringLiteral("timeButton"));

        gridLayout_7->addWidget(timeButton, 1, 0, 1, 1);

        vsButton = new QRadioButton(play);
        vsButton->setObjectName(QStringLiteral("vsButton"));

        gridLayout_7->addWidget(vsButton, 3, 0, 1, 1);

        teamButton = new QRadioButton(play);
        teamButton->setObjectName(QStringLiteral("teamButton"));

        gridLayout_7->addWidget(teamButton, 2, 0, 1, 1);


        gridLayout_6->addWidget(play, 0, 0, 1, 1);

        label = new QLabel(MenuOption);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 880, 960));
        label->setPixmap(QPixmap(QString::fromUtf8("main.png")));
        gifLabel = new QLabel(MenuOption);
        gifLabel->setObjectName(QStringLiteral("gifLabel"));
        gifLabel->setGeometry(QRect(0, 490, 301, 201));
        gifLabel->setPixmap(QPixmap(QString::fromUtf8("test.gif")));
        titleLabel = new QLabel(MenuOption);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(280, 20, 301, 43));
        titleLabel->setPixmap(QPixmap(QString::fromUtf8("title2.gif")));
        label->raise();
        verticalLayoutWidget->raise();
        gifLabel->raise();
        titleLabel->raise();

        retranslateUi(MenuOption);

        QMetaObject::connectSlotsByName(MenuOption);
    } // setupUi

    void retranslateUi(QDialog *MenuOption)
    {
        MenuOption->setWindowTitle(QApplication::translate("MenuOption", " User Option Menu", 0));
        support->setTitle(QApplication::translate("MenuOption", "2) Support", 0));
        supportButton->setText(QApplication::translate("MenuOption", "Support", 0));
        supportButton->setShortcut(QApplication::translate("MenuOption", "Ctrl+S", 0));
        profil->setTitle(QApplication::translate("MenuOption", "3) View profil", 0));
        showProfilButton->setText(QApplication::translate("MenuOption", "Show", 0));
        showProfilButton->setShortcut(QApplication::translate("MenuOption", "Ctrl+Shift+P", 0));
        ranking->setTitle(QApplication::translate("MenuOption", "4) Consult ranking", 0));
        showRankingButton->setText(QApplication::translate("MenuOption", "Show", 0));
        showRankingButton->setShortcut(QApplication::translate("MenuOption", "Ctrl+R", 0));
        friendMenu->setTitle(QApplication::translate("MenuOption", "5) Consult friend", 0));
        showFriendButton->setText(QApplication::translate("MenuOption", "Show", 0));
        showFriendButton->setShortcut(QApplication::translate("MenuOption", "Ctrl+F", 0));
        deconnexion->setTitle(QApplication::translate("MenuOption", "6) Deconnexion", 0));
        leaveButton->setText(QApplication::translate("MenuOption", "Leave Account", 0));
        leaveButton->setShortcut(QApplication::translate("MenuOption", "Ctrl+D", 0));
        play->setTitle(QApplication::translate("MenuOption", "1) Play a party", 0));
        playButton->setText(QApplication::translate("MenuOption", "Play", 0));
        playButton->setShortcut(QApplication::translate("MenuOption", "Ctrl+P", 0));
        timeButton->setText(QApplication::translate("MenuOption", "Time Trial Mode", 0));
        vsButton->setText(QApplication::translate("MenuOption", "Vs Mode", 0));
        teamButton->setText(QApplication::translate("MenuOption", "Team Mode", 0));
        label->setText(QString());
        gifLabel->setText(QString());
        titleLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuOption: public Ui_MenuOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUOPTION_H
