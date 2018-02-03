#ifndef DELETEFRIEND_H
#define DELETEFRIEND_H

#include <QDialog>
#include <QCloseEvent>
#include <string>

namespace Ui {
class DeleteFriend;
}

class DeleteFriend : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteFriend(QWidget *parent = 0);
    ~DeleteFriend();
    void popupNotDeleteHimSelf();
    void popupDeleteFriendSuccess(std::string);
    void popupNotYourFriend();
    void popupFriendNotExist();
    void clearFriendLabel();

signals:
    void deleteSignal(std::string);
    void quitDeleteFriend();

private:
    Ui::DeleteFriend *ui;

private slots:
    void on_deleteFriend_clicked();
    void on_quitButton_clicked();
    void closeEvent(QCloseEvent *event);
};

#endif // DELETEFRIEND_H
