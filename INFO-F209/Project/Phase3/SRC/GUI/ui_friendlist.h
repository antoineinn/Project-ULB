/********************************************************************************
** Form generated from reading UI file 'friendlist.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_H
#define UI_FRIENDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendList
{
public:
    QLabel *friendList;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *QuitButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *FriendList)
    {
        if (FriendList->objectName().isEmpty())
            FriendList->setObjectName(QStringLiteral("FriendList"));
        FriendList->resize(400, 440);
        FriendList->setMinimumSize(QSize(400, 440));
        FriendList->setMaximumSize(QSize(400, 440));
        FriendList->setModal(true);
        friendList = new QLabel(FriendList);
        friendList->setObjectName(QStringLiteral("friendList"));
        friendList->setGeometry(QRect(6, 10, 381, 381));
        friendList->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(FriendList);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 400, 183, 27));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        QuitButton = new QPushButton(horizontalLayoutWidget);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        horizontalLayout->addWidget(QuitButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(FriendList);

        QMetaObject::connectSlotsByName(FriendList);
    } // setupUi

    void retranslateUi(QDialog *FriendList)
    {
        FriendList->setWindowTitle(QApplication::translate("FriendList", "FriendList", 0));
        friendList->setText(QApplication::translate("FriendList", "TextLabel", 0));
        QuitButton->setText(QApplication::translate("FriendList", "Quit", 0));
        QuitButton->setShortcut(QApplication::translate("FriendList", "Ctrl+Q", 0));
    } // retranslateUi

};

namespace Ui {
    class FriendList: public Ui_FriendList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_H
