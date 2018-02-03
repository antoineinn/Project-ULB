/********************************************************************************
** Form generated from reading UI file 'createaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNT_H
#define UI_CREATEACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateAccount
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *Username;
    QLineEdit *Password;
    QPushButton *CreateButton;
    QPushButton *QuitButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *CreateAccount)
    {
        if (CreateAccount->objectName().isEmpty())
            CreateAccount->setObjectName(QStringLiteral("CreateAccount"));
        CreateAccount->resize(600, 400);
        groupBox = new QGroupBox(CreateAccount);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(150, 130, 271, 171));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Username = new QLineEdit(groupBox);
        Username->setObjectName(QStringLiteral("Username"));

        verticalLayout_2->addWidget(Username);

        Password = new QLineEdit(groupBox);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(Password);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        CreateButton = new QPushButton(groupBox);
        CreateButton->setObjectName(QStringLiteral("CreateButton"));

        gridLayout->addWidget(CreateButton, 1, 1, 1, 1);

        QuitButton = new QPushButton(groupBox);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        gridLayout->addWidget(QuitButton, 2, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        label_3 = new QLabel(CreateAccount);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 600, 400));
        label_3->setPixmap(QPixmap(QString::fromUtf8("image.png")));
        label_3->raise();
        groupBox->raise();

        retranslateUi(CreateAccount);

        QMetaObject::connectSlotsByName(CreateAccount);
    } // setupUi

    void retranslateUi(QDialog *CreateAccount)
    {
        CreateAccount->setWindowTitle(QApplication::translate("CreateAccount", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("CreateAccount", "Create Account", 0));
        CreateButton->setText(QApplication::translate("CreateAccount", "Create Account", 0));
        CreateButton->setShortcut(QApplication::translate("CreateAccount", "Ctrl+C", 0));
        QuitButton->setText(QApplication::translate("CreateAccount", "Quit", 0));
        QuitButton->setShortcut(QApplication::translate("CreateAccount", "Ctrl+Q", 0));
        label->setText(QApplication::translate("CreateAccount", "Username:", 0));
        label_2->setText(QApplication::translate("CreateAccount", "Password:", 0));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateAccount: public Ui_CreateAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNT_H
