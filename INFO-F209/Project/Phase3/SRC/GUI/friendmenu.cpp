#include "friendmenu.h"
#include "ui_friendmenu.h"

FriendMenu::FriendMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendMenu)
{
    ui->setupUi(this);
}

FriendMenu::~FriendMenu()
{
    delete ui;
}

void FriendMenu::on_QuitButton_clicked(){
    this->close();
}

void FriendMenu::on_AddButton_clicked(){
	emit showAddFriend();
}

void FriendMenu::on_DeleteButton_clicked(){
	emit showDeleteFriend();
}

void FriendMenu::on_showFriendButton_clicked(){
	emit showFriendList();
}

void FriendMenu::on_showRequestButton_clicked(){
	emit showRequestFriend();
}

void FriendMenu::closeEvent(QCloseEvent *event){
    emit signalQuit();
    QWidget::closeEvent(event);
}
