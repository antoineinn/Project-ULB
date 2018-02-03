#ifndef RANKINGVIEW_H
#define RANKINGVIEW_H

#include <QDialog>
#include <QCloseEvent>
#include <string>

namespace Ui {
class RankingView;
}

class RankingView : public QDialog
{
    Q_OBJECT

public:
    explicit RankingView(QWidget *parent = 0);
    ~RankingView();
    void setTeamRankingLineEdit(std::string);
    void setChronoRankingLineEdit(std::string);
    void setVsRankingLineEdit(std::string);
signals:
    void retMenuOption();
private:
    Ui::RankingView *ui;
private slots:
    void on_QuitButton_clicked();
    void closeEvent(QCloseEvent *event);
};

#endif // RANKINGVIEW_H
