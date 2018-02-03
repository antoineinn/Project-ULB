/********************************************************************************
** Form generated from reading UI file 'loginmenuoption.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINMENUOPTION_H
#define UI_LOGINMENUOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginMenuOption
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *LoginButton;
    QPushButton *CreateButton;
    QPushButton *QuitButton;
    QLabel *label;

    void setupUi(QDialog *LoginMenuOption)
    {
        if (LoginMenuOption->objectName().isEmpty())
            LoginMenuOption->setObjectName(QStringLiteral("LoginMenuOption"));
        LoginMenuOption->resize(600, 400);
        layoutWidget = new QWidget(LoginMenuOption);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 140, 201, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LoginButton = new QPushButton(layoutWidget);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));

        verticalLayout->addWidget(LoginButton);

        CreateButton = new QPushButton(layoutWidget);
        CreateButton->setObjectName(QStringLiteral("CreateButton"));

        verticalLayout->addWidget(CreateButton);

        QuitButton = new QPushButton(layoutWidget);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        verticalLayout->addWidget(QuitButton);

        label = new QLabel(LoginMenuOption);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 600, 400));
        label->setPixmap(QPixmap(QString::fromUtf8("image.png")));
        label->raise();
        layoutWidget->raise();

        retranslateUi(LoginMenuOption);

        QMetaObject::connectSlotsByName(LoginMenuOption);
    } // setupUi

    void retranslateUi(QDialog *LoginMenuOption)
    {
        LoginMenuOption->setWindowTitle(QApplication::translate("LoginMenuOption", "Login & Create Account Menu ", 0));
        LoginButton->setText(QApplication::translate("LoginMenuOption", "Login", 0));
        LoginButton->setShortcut(QApplication::translate("LoginMenuOption", "Ctrl+L", 0));
        CreateButton->setText(QApplication::translate("LoginMenuOption", "Create account", 0));
        CreateButton->setShortcut(QApplication::translate("LoginMenuOption", "Ctrl+C", 0));
        QuitButton->setText(QApplication::translate("LoginMenuOption", "Quit", 0));
        QuitButton->setShortcut(QApplication::translate("LoginMenuOption", "Ctrl+Q", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginMenuOption: public Ui_LoginMenuOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINMENUOPTION_H
