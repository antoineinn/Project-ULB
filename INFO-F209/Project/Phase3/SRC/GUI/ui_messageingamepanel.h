/********************************************************************************
** Form generated from reading UI file 'messageingamepanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEINGAMEPANEL_H
#define UI_MESSAGEINGAMEPANEL_H

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

QT_BEGIN_NAMESPACE

class Ui_MessageInGamePanel
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ByeButton;
    QPushButton *HelloButton;
    QPushButton *GodDamnButton;
    QPushButton *LooserButton;
    QPushButton *NoobButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *MessageInGamePanel)
    {
        if (MessageInGamePanel->objectName().isEmpty())
            MessageInGamePanel->setObjectName(QStringLiteral("MessageInGamePanel"));
        MessageInGamePanel->resize(489, 78);
        gridLayout = new QGridLayout(MessageInGamePanel);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ByeButton = new QPushButton(MessageInGamePanel);
        ByeButton->setObjectName(QStringLiteral("ByeButton"));

        horizontalLayout->addWidget(ByeButton);

        HelloButton = new QPushButton(MessageInGamePanel);
        HelloButton->setObjectName(QStringLiteral("HelloButton"));

        horizontalLayout->addWidget(HelloButton);

        GodDamnButton = new QPushButton(MessageInGamePanel);
        GodDamnButton->setObjectName(QStringLiteral("GodDamnButton"));

        horizontalLayout->addWidget(GodDamnButton);

        LooserButton = new QPushButton(MessageInGamePanel);
        LooserButton->setObjectName(QStringLiteral("LooserButton"));

        horizontalLayout->addWidget(LooserButton);

        NoobButton = new QPushButton(MessageInGamePanel);
        NoobButton->setObjectName(QStringLiteral("NoobButton"));

        horizontalLayout->addWidget(NoobButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(MessageInGamePanel);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("font.png")));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(MessageInGamePanel);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(MessageInGamePanel);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(MessageInGamePanel);

        QMetaObject::connectSlotsByName(MessageInGamePanel);
    } // setupUi

    void retranslateUi(QDialog *MessageInGamePanel)
    {
        MessageInGamePanel->setWindowTitle(QApplication::translate("MessageInGamePanel", "Dialog", 0));
        ByeButton->setText(QApplication::translate("MessageInGamePanel", "Bye !", 0));
        HelloButton->setText(QApplication::translate("MessageInGamePanel", "Hello", 0));
        GodDamnButton->setText(QApplication::translate("MessageInGamePanel", "Goddamn Vegan ", 0));
        LooserButton->setText(QApplication::translate("MessageInGamePanel", "Looser", 0));
        NoobButton->setText(QApplication::translate("MessageInGamePanel", "Noooooob", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("MessageInGamePanel", ":", 0));
    } // retranslateUi

};

namespace Ui {
    class MessageInGamePanel: public Ui_MessageInGamePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEINGAMEPANEL_H
