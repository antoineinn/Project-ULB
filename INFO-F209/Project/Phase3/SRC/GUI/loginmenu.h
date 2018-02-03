#ifndef LOGINMENU_H
#define LOGINMENU_H

#include <QDialog>
#include <QCloseEvent>
#include <string>
#include "ui_loginmenu.h"

namespace Ui {
class login;
}

class LoginMenu : public QDialog
{
    Q_OBJECT
signals:
    void loginSignal(std::string username, int password);
    void quitLogInSignal();
public:
    explicit LoginMenu(QWidget *parent = 0);
    ~LoginMenu();
    void popupValid();
    void popupNotValid();
    void popupAlreadyLogged();
    void clearLineEdit();

private:
    Ui::LoginMenu  *ui;

private slots:
    void on_LoginButton_clicked();
    void on_QuitButton_clicked();
    void closeEvent(QCloseEvent *event);
};

#endif // LOGINMENU_H
