#include "rankingview.h"
#include "ui_rankingview.h"

RankingView::RankingView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RankingView)
{
    ui->setupUi(this);
}

RankingView::~RankingView()
{
    delete ui;
}

void RankingView::on_QuitButton_clicked(){
    this->close();
}

void RankingView::setTeamRankingLineEdit(std::string data){
    QString text = QString::fromStdString(data);
    ui->team_ranking->setText(text);
}

void RankingView::setChronoRankingLineEdit(std::string data){
    QString text = QString::fromStdString(data);
    ui->chrono_ranking->setText(text);
}

void RankingView::setVsRankingLineEdit(std::string data){
    QString text = QString::fromStdString(data);
    ui->vs_ranking->setText(text);
}

void RankingView::closeEvent(QCloseEvent *event){
    emit retMenuOption();
    QWidget::closeEvent(event);
}
