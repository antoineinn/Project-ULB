#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include <QCloseEvent>
#include <string>
#include "ui_createaccount.h"

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog, public Ui_CreateAccount
{
    Q_OBJECT

signals:
    void createSignal(std::string username, int password);
    void quitCreateAccountSignal();

public:
    explicit CreateAccount(QWidget *parent = 0);
    ~CreateAccount();
    void clearLineEdit();
    void popupNotValid();
    void popupValid();
    void popupWelcome();

private:
    Ui::CreateAccount  *ui;
private slots:
    void on_CreateButton_clicked();
    void on_QuitButton_clicked();
    void closeEvent(QCloseEvent *event);
};

#endif // CREATEACCOUNT_H
