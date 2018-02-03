#include <QMessageBox>
#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFriend)
{
    ui->setupUi(this);
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::on_addFriend_clicked(){
	hide();
	std::string text = ui->friendAdd->text().toStdString();
	emit addSignal(text);
}

void AddFriend::on_quitButton_clicked(){
    this->close();
}

void AddFriend::closeEvent(QCloseEvent *event){
    emit quitAddFriend();
    QWidget::closeEvent(event);
}

void AddFriend::popupNotAddHimSelf(){
	QMessageBox::information(this,"Add Friend","You can't add yourself to your friend list. Please try a valid username OR Quit.");
}

void AddFriend::clearFriendLabel(){
	ui->friendAdd->clear();
}

void AddFriend::popupRequestFriendSent(){
    QMessageBox::information(this,"Add Friend","The friend request has been send !");
}

void AddFriend::popupRequestFriendAllready(std::string name){
    const std::string text = "Your already send a friend request to "+name+"or the user "+name+" is already your friend !";
    QMessageBox::information(this,"Add Friend", text.c_str());
}

void AddFriend::popupFriendNotExist(){
    QMessageBox::information(this,"Add Friend", "The friend you tried to add doesn't exist!");
}