/********************************************************************************
** Form generated from reading UI file 'rankingview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKINGVIEW_H
#define UI_RANKINGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_RankingView
{
public:
    QLabel *vsLabel;
    QPushButton *QuitButton;
    QTextEdit *team_ranking;
    QTextEdit *chrono_ranking;
    QTextEdit *vs_ranking;
    QLabel *chronoLabel;
    QLabel *teamLabel;
    QLabel *background;

    void setupUi(QDialog *RankingView)
    {
        if (RankingView->objectName().isEmpty())
            RankingView->setObjectName(QStringLiteral("RankingView"));
        RankingView->resize(552, 420);
        RankingView->setLayoutDirection(Qt::RightToLeft);
        RankingView->setAutoFillBackground(false);
        vsLabel = new QLabel(RankingView);
        vsLabel->setObjectName(QStringLiteral("vsLabel"));
        vsLabel->setGeometry(QRect(380, 30, 111, 51));
        vsLabel->setPixmap(QPixmap(QString::fromUtf8("VS.png")));
        vsLabel->setScaledContents(true);
        QuitButton = new QPushButton(RankingView);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));
        QuitButton->setGeometry(QRect(220, 380, 99, 27));
        team_ranking = new QTextEdit(RankingView);
        team_ranking->setObjectName(QStringLiteral("team_ranking"));
        team_ranking->setGeometry(QRect(30, 90, 141, 281));
        team_ranking->setReadOnly(true);
        chrono_ranking = new QTextEdit(RankingView);
        chrono_ranking->setObjectName(QStringLiteral("chrono_ranking"));
        chrono_ranking->setGeometry(QRect(200, 90, 141, 281));
        chrono_ranking->setReadOnly(true);
        vs_ranking = new QTextEdit(RankingView);
        vs_ranking->setObjectName(QStringLiteral("vs_ranking"));
        vs_ranking->setGeometry(QRect(370, 90, 141, 281));
        vs_ranking->setReadOnly(true);
        chronoLabel = new QLabel(RankingView);
        chronoLabel->setObjectName(QStringLiteral("chronoLabel"));
        chronoLabel->setGeometry(QRect(200, 30, 141, 51));
        chronoLabel->setPixmap(QPixmap(QString::fromUtf8("Chrono.png")));
        chronoLabel->setScaledContents(true);
        teamLabel = new QLabel(RankingView);
        teamLabel->setObjectName(QStringLiteral("teamLabel"));
        teamLabel->setGeometry(QRect(30, 30, 141, 51));
        teamLabel->setPixmap(QPixmap(QString::fromUtf8("Team.png")));
        teamLabel->setScaledContents(true);
        background = new QLabel(RankingView);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-60, -20, 621, 441));
#ifndef QT_NO_WHATSTHIS
        background->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        background->setLayoutDirection(Qt::RightToLeft);
        background->setText(QStringLiteral(""));
        background->setPixmap(QPixmap(QString::fromUtf8("ranking.png")));
        background->setScaledContents(false);
        background->raise();
        vsLabel->raise();
        QuitButton->raise();
        team_ranking->raise();
        chrono_ranking->raise();
        vs_ranking->raise();
        chronoLabel->raise();
        teamLabel->raise();

        retranslateUi(RankingView);

        QMetaObject::connectSlotsByName(RankingView);
    } // setupUi

    void retranslateUi(QDialog *RankingView)
    {
        RankingView->setWindowTitle(QApplication::translate("RankingView", "Ranking", 0));
        vsLabel->setText(QString());
        QuitButton->setText(QApplication::translate("RankingView", "Quit", 0));
        QuitButton->setShortcut(QApplication::translate("RankingView", "Ctrl+Q", 0));
        chronoLabel->setText(QString());
        teamLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RankingView: public Ui_RankingView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKINGVIEW_H
