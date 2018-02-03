#ifndef LOGINMENUOPTION_H
#define LOGINMENUOPTION_H
#include <QCloseEvent>

#include <QDialog>
#include "ui_loginmenuoption.h"

namespace Ui {
class LoginMenuOption;
}

class LoginMenuOption : public QDialog, public Ui_LoginMenuOption
{
    Q_OBJECT

signals:
    void showLogin();
    void showCreate();
    void quitAppSignal();

public:
    explicit LoginMenuOption(QWidget *parent = 0);
    ~LoginMenuOption();

private:
    Ui::LoginMenuOption *ui;

private slots:
    void on_LoginButton_clicked();
    void on_CreateButton_clicked();
    void on_QuitButton_clicked();
    void closeEvent(QCloseEvent *event);

};

#endif // LOGINMENUOPTION_H
