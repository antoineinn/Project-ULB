#include <QMessageBox>
#include "loginmenuoption.h"

LoginMenuOption::LoginMenuOption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginMenuOption)
{
    ui->setupUi(this);
}
LoginMenuOption::~LoginMenuOption()
{
    delete ui;
}

void LoginMenuOption::on_LoginButton_clicked()
{
    hide();
    emit showLogin();
}

void LoginMenuOption::on_CreateButton_clicked()
{
    hide();
    emit showCreate();
}

void LoginMenuOption::on_QuitButton_clicked()
{
	this->close();
}


void LoginMenuOption::closeEvent(QCloseEvent *event){
    QMessageBox::information(this, "Exit Application", "Bye");
	emit quitAppSignal();
	QWidget::closeEvent(event);
}
