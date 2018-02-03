#include <QMessageBox>
#include "deletefriend.h"
#include "ui_deletefriend.h"

DeleteFriend::DeleteFriend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteFriend)
{
    ui->setupUi(this);
}

DeleteFriend::~DeleteFriend()
{
    delete ui;
}

void DeleteFriend::on_deleteFriend_clicked(){
    hide();
    std::string text = ui->friendDelete->text().toStdString();
    emit deleteSignal(text);
}

void DeleteFriend::on_quitButton_clicked(){
    this->close();
}

void DeleteFriend::closeEvent(QCloseEvent *event){
    emit quitDeleteFriend();
    QWidget::closeEvent(event);
}

void DeleteFriend::popupNotDeleteHimSelf(){
	QMessageBox::information(this,"Delete Friend","You can't add yourself to your friend list. Please try a valid username OR Quit.");
}

void DeleteFriend::popupDeleteFriendSuccess(std::string name){
	const std::string text = "The user "+name+"was sucessfuly deleted";
	QMessageBox::information(this,"Delete Friend", text.c_str());
}

void DeleteFriend::popupNotYourFriend(){
	QMessageBox::information(this,"Delete Friend", "The user isn't in your friend list!");
}

void DeleteFriend::popupFriendNotExist(){
	QMessageBox::information(this,"Delete Friend","The friend you tried to delete doesn't exist!");
}

void DeleteFriend::clearFriendLabel(){
	ui->friendDelete->clear();
}

