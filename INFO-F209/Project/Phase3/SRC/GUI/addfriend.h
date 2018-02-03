#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QDialog>
#include <QCloseEvent>
#include <string>

namespace Ui {
class AddFriend;
}

class AddFriend : public QDialog
{
    Q_OBJECT

public:
    explicit AddFriend(QWidget *parent = 0);
    ~AddFriend();
    void popupNotAddHimSelf();
    void popupRequestFriendSent();
    void popupRequestFriendAllready(std::string);
    void popupFriendNotExist();
    void clearFriendLabel();

signals:
    void addSignal(std::string);
    void quitAddFriend();
private:
    Ui::AddFriend *ui;

private slots:
	void on_addFriend_clicked();
	void on_quitButton_clicked();
    void closeEvent(QCloseEvent *event);
};

#endif // ADDFRIEND_H
