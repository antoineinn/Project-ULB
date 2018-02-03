#include "friendlist.h"
#include "ui_friendlist.h"

FriendList::FriendList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendList)
{
    ui->setupUi(this);
}

FriendList::~FriendList()
{
    delete ui;
}

void FriendList::setFriendList(std::string data){
	QString text = QString::fromStdString(data);
	ui->friendList->setText(text);
}

void FriendList::on_QuitButton_clicked(){
    this->close();
}