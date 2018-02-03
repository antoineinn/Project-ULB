/********************************************************************************
** Form generated from reading UI file 'deletefriend.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEFRIEND_H
#define UI_DELETEFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DeleteFriend
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *friendDelete;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deleteFriend;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DeleteFriend)
    {
        if (DeleteFriend->objectName().isEmpty())
            DeleteFriend->setObjectName(QStringLiteral("DeleteFriend"));
        DeleteFriend->setWindowModality(Qt::NonModal);
        DeleteFriend->resize(600, 250);
        DeleteFriend->setMinimumSize(QSize(600, 250));
        DeleteFriend->setMaximumSize(QSize(600, 250));
        DeleteFriend->setModal(true);
        gridLayout = new QGridLayout(DeleteFriend);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(DeleteFriend);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        friendDelete = new QLineEdit(DeleteFriend);
        friendDelete->setObjectName(QStringLiteral("friendDelete"));

        horizontalLayout_2->addWidget(friendDelete);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        deleteFriend = new QPushButton(DeleteFriend);
        deleteFriend->setObjectName(QStringLiteral("deleteFriend"));

        horizontalLayout->addWidget(deleteFriend);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quitButton = new QPushButton(DeleteFriend);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        horizontalLayout->addWidget(quitButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(DeleteFriend);

        QMetaObject::connectSlotsByName(DeleteFriend);
    } // setupUi

    void retranslateUi(QDialog *DeleteFriend)
    {
        DeleteFriend->setWindowTitle(QApplication::translate("DeleteFriend", "Dialog", 0));
        label->setText(QApplication::translate("DeleteFriend", "Friend name to delete", 0));
        deleteFriend->setText(QApplication::translate("DeleteFriend", "Delete", 0));
        deleteFriend->setShortcut(QApplication::translate("DeleteFriend", "Ctrl+D", 0));
        quitButton->setText(QApplication::translate("DeleteFriend", "Quit", 0));
        quitButton->setShortcut(QApplication::translate("DeleteFriend", "Ctrl+Q", 0));
    } // retranslateUi

};

namespace Ui {
    class DeleteFriend: public Ui_DeleteFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEFRIEND_H
