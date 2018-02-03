#include <string>
#include <QMessageBox>
#include "createaccount.h"

CreateAccount::CreateAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAccount)
{
    ui->setupUi(this);
}
CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_CreateButton_clicked()
{
    std::string username = ui->Username->text().toStdString();
    int password = ui->Password->text().toInt();
    emit createSignal(username, password);
}

void CreateAccount::on_QuitButton_clicked(){
    this->close();
}

void CreateAccount::closeEvent(QCloseEvent *event){
    emit quitCreateAccountSignal();
    QWidget::closeEvent(event);
}


void CreateAccount::popupValid(){
    QMessageBox::information(this,"Create Account","Your account was successfuly created.");
}

void CreateAccount::popupNotValid(){
    QMessageBox::warning(this,"Create Account","The id you choose is already taken! Choose another one.");
}

void CreateAccount::popupWelcome(){
    QMessageBox::information(this,"Create Account","Welcome to the account creation. Please complete the following fields.");
}

void CreateAccount::clearLineEdit(){
    ui->Username->clear();
    ui->Password->clear();
}

