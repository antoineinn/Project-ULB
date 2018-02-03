#include <string>
#include  <QMessageBox>
#include "loginmenu.h"


LoginMenu::LoginMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginMenu)
{
    ui->setupUi(this);
}

LoginMenu::~LoginMenu()
{
    delete ui;
}

void LoginMenu::on_LoginButton_clicked()
{
    std::string username = ui->Username->text().toStdString();
    int password = ui->Password->text().toInt();
    emit loginSignal(username, password);
}

void LoginMenu::on_QuitButton_clicked(){
   this->close();
}

void LoginMenu::closeEvent(QCloseEvent *event){
    emit quitLogInSignal();
    QWidget::closeEvent(event);
}

void LoginMenu::popupValid(){
    QMessageBox::information(this,"Login","Username and password are correct.");
}

void LoginMenu::popupNotValid(){
    QMessageBox::warning(this,"Login","The id or the password is incorrect ! Please retry.");
}

void LoginMenu::popupAlreadyLogged(){
    QMessageBox::warning(this,"Login","The account you tried to connect is already logged!");
}

void LoginMenu::clearLineEdit(){
    ui->Username->clear();
    ui->Password->clear();
}
