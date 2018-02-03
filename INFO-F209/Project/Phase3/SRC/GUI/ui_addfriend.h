/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

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

class Ui_AddFriend
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *friendAdd;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addFriend;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *AddFriend)
    {
        if (AddFriend->objectName().isEmpty())
            AddFriend->setObjectName(QStringLiteral("AddFriend"));
        AddFriend->setWindowModality(Qt::NonModal);
        AddFriend->resize(600, 250);
        AddFriend->setMinimumSize(QSize(600, 250));
        AddFriend->setMaximumSize(QSize(600, 250));
        AddFriend->setModal(true);
        gridLayout = new QGridLayout(AddFriend);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(AddFriend);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        friendAdd = new QLineEdit(AddFriend);
        friendAdd->setObjectName(QStringLiteral("friendAdd"));

        horizontalLayout_2->addWidget(friendAdd);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        addFriend = new QPushButton(AddFriend);
        addFriend->setObjectName(QStringLiteral("addFriend"));

        horizontalLayout->addWidget(addFriend);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quitButton = new QPushButton(AddFriend);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        horizontalLayout->addWidget(quitButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(AddFriend);

        QMetaObject::connectSlotsByName(AddFriend);
    } // setupUi

    void retranslateUi(QDialog *AddFriend)
    {
        AddFriend->setWindowTitle(QApplication::translate("AddFriend", "Dialog", 0));
        label->setText(QApplication::translate("AddFriend", "Friend name to add:", 0));
        addFriend->setText(QApplication::translate("AddFriend", "Add", 0));
        addFriend->setShortcut(QApplication::translate("AddFriend", "Ctrl+A", 0));
        quitButton->setText(QApplication::translate("AddFriend", "Quit", 0));
        quitButton->setShortcut(QApplication::translate("AddFriend", "Ctrl+Q", 0));
    } // retranslateUi

};

namespace Ui {
    class AddFriend: public Ui_AddFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
