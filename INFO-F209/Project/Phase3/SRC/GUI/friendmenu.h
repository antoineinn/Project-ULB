#ifndef FRIENDMENU_H
#define FRIENDMENU_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class FriendMenu;
}

class FriendMenu : public QDialog
{
    Q_OBJECT

public:
    explicit FriendMenu(QWidget *parent = 0);
    ~FriendMenu();
signals:
	void signalQuit();
	void showAddFriend();
	void showDeleteFriend();
	void showRequestFriend();
	void showFriendList();
private:
    Ui::FriendMenu *ui;

private slots:
	void on_QuitButton_clicked();
	void on_AddButton_clicked();
	void on_DeleteButton_clicked();
	void on_showRequestButton_clicked();
	void on_showFriendButton_clicked();
	void closeEvent(QCloseEvent *event);
};

#endif // FRIENDMENU_H
