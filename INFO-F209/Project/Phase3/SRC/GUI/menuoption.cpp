#include "menuoption.h"
#include "ui_menuoption.h"

MenuOption::MenuOption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuOption)
{
    ui->setupUi(this);
    ui->playButton->setEnabled(false);
    this->movie = new QMovie("../GUI/test.gif");
    ui->gifLabel->setMovie(movie);
    movie->start();
    this->movie2 = new QMovie("../GUI/title2.gif");
    ui->titleLabel->setMovie(movie2);
    movie2->start();
}

MenuOption::~MenuOption()
{
    delete ui;
}

void MenuOption::on_showFriendButton_clicked(){
    hide();
    emit showFriend();
}

void MenuOption::on_showProfilButton_clicked(){
	hide();
	emit showProfil();
}

void MenuOption::on_showRankingButton_clicked(){
	hide();
	emit showRanking();
}

void MenuOption::on_leaveButton_clicked(){
	this->close();
}

void MenuOption::closeEvent(QCloseEvent *event){
    emit signalLogOut();
    QWidget::closeEvent(event);
}

void MenuOption::on_playButton_clicked(){
    this->hide();
    ui->playButton->setEnabled(false);
    this->resetRadioButton();
    emit playSignal(gameMode);
}

void MenuOption::on_teamButton_toggled(){
    this->handleRadioButton(ui->teamButton);
}


void MenuOption::on_timeButton_toggled(){
    this->handleRadioButton(ui->timeButton);
}


void MenuOption::on_vsButton_toggled(){
    this->handleRadioButton(ui->vsButton);
}
void MenuOption::handleRadioButton(QRadioButton *button){
    std::string buttonName  = button->objectName().toStdString();
    if (button->isChecked()){
        if (buttonName == "teamButton"){
            this->gameMode = 1;
        }
        else if(buttonName == "timeButton"){
            this->gameMode = 2;
        }
        else if (buttonName == "vsButton") {
            this->gameMode = 3;
        }
    }
    ui->playButton->setEnabled(true);
}

void MenuOption::resetRadioButton(){
    ui->teamButton->setChecked(false);
    ui->timeButton->setChecked(false);
    ui->vsButton->setChecked(false);
}
