/********************************************************************************
** Form generated from reading UI file 'friendmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDMENU_H
#define UI_FRIENDMENU_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *addFriend;
    QGridLayout *gridLayout_5;
    QPushButton *AddButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *deleteFriend;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *DeleteButton;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *acceptFriend;
    QGridLayout *gridLayout_2;
    QPushButton *showRequestButton;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QGroupBox *friendList;
    QGridLayout *gridLayout_3;
    QPushButton *showFriendButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *quit;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *QuitButton;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;

    void setupUi(QDialog *FriendMenu)
    {
        if (FriendMenu->objectName().isEmpty())
            FriendMenu->setObjectName(QStringLiteral("FriendMenu"));
        FriendMenu->resize(820, 680);
        verticalLayoutWidget = new QWidget(FriendMenu);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(290, 230, 225, 397));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        addFriend = new QGroupBox(verticalLayoutWidget);
        addFriend->setObjectName(QStringLiteral("addFriend"));
        gridLayout_5 = new QGridLayout(addFriend);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        AddButton = new QPushButton(addFriend);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        gridLayout_5->addWidget(AddButton, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 0, 2, 1, 1);


        verticalLayout_2->addWidget(addFriend);

        deleteFriend = new QGroupBox(verticalLayoutWidget);
        deleteFriend->setObjectName(QStringLiteral("deleteFriend"));
        gridLayout = new QGridLayout(deleteFriend);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        DeleteButton = new QPushButton(deleteFriend);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));

        gridLayout->addWidget(DeleteButton, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        verticalLayout_2->addWidget(deleteFriend);

        acceptFriend = new QGroupBox(verticalLayoutWidget);
        acceptFriend->setObjectName(QStringLiteral("acceptFriend"));
        gridLayout_2 = new QGridLayout(acceptFriend);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        showRequestButton = new QPushButton(acceptFriend);
        showRequestButton->setObjectName(QStringLiteral("showRequestButton"));

        gridLayout_2->addWidget(showRequestButton, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 0, 2, 1, 1);


        verticalLayout_2->addWidget(acceptFriend);

        friendList = new QGroupBox(verticalLayoutWidget);
        friendList->setObjectName(QStringLiteral("friendList"));
        gridLayout_3 = new QGridLayout(friendList);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        showFriendButton = new QPushButton(friendList);
        showFriendButton->setObjectName(QStringLiteral("showFriendButton"));

        gridLayout_3->addWidget(showFriendButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);


        verticalLayout_2->addWidget(friendList);

        quit = new QGroupBox(verticalLayoutWidget);
        quit->setObjectName(QStringLiteral("quit"));
        gridLayout_4 = new QGridLayout(quit);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        QuitButton = new QPushButton(quit);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        gridLayout_4->addWidget(QuitButton, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 2, 1, 1);


        verticalLayout_2->addWidget(quit);

        label = new QLabel(FriendMenu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 820, 680));
        label->setPixmap(QPixmap(QString::fromUtf8("image3.png")));
        label->raise();
        verticalLayoutWidget->raise();

        retranslateUi(FriendMenu);

        QMetaObject::connectSlotsByName(FriendMenu);
    } // setupUi

    void retranslateUi(QDialog *FriendMenu)
    {
        FriendMenu->setWindowTitle(QApplication::translate("FriendMenu", "Friend View", 0));
        addFriend->setTitle(QApplication::translate("FriendMenu", "1) Add a Friend", 0));
        AddButton->setText(QApplication::translate("FriendMenu", "Add", 0));
        AddButton->setShortcut(QApplication::translate("FriendMenu", "Ctrl+A", 0));
        deleteFriend->setTitle(QApplication::translate("FriendMenu", "1) Delete a Friend", 0));
        DeleteButton->setText(QApplication::translate("FriendMenu", "Delete", 0));
        DeleteButton->setShortcut(QApplication::translate("FriendMenu", "Ctrl+D", 0));
        acceptFriend->setTitle(QApplication::translate("FriendMenu", "3) Accept request of a friend", 0));
        showRequestButton->setText(QApplication::translate("FriendMenu", "Show Request", 0));
        showRequestButton->setShortcut(QApplication::translate("FriendMenu", "Ctrl+R", 0));
        friendList->setTitle(QApplication::translate("FriendMenu", "4) Show friend list", 0));
        showFriendButton->setText(QApplication::translate("FriendMenu", "Show", 0));
        showFriendButton->setShortcut(QApplication::translate("FriendMenu", "Ctrl+L", 0));
        quit->setTitle(QApplication::translate("FriendMenu", "5) Quit", 0));
        QuitButton->setText(QApplication::translate("FriendMenu", "Quit", 0));
        QuitButton->setShortcut(QApplication::translate("FriendMenu", "Ctrl+Q", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendMenu: public Ui_FriendMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDMENU_H
