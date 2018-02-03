#include "profilview.h"
#include "ui_profilview.h"


ProfilView::ProfilView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfilView)
{
    ui->setupUi(this);
    this->movie = new QMovie("../GUI/Bobpub.jpg");
    ui->BestScoreLabel->setMovie(movie);
    movie->start();
}

ProfilView::~ProfilView()
{
    delete ui;
}

void ProfilView::on_QuitButton_clicked(){
	this->close();
}

void ProfilView::setFriendLabel(std::string data){
	QString text = QString::fromStdString(data);
	ui->FriendLabel->setText(text);
}

void ProfilView::setPlayerLineEdit(std::string data){
	QString text = QString::fromStdString(data);
	ui->PlayerLineEdit->setText(text);
}


void ProfilView::closeEvent(QCloseEvent *event){
    emit showMenuOption();
    QWidget::closeEvent(event);
}
