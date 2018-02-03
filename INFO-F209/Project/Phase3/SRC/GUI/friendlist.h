#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QDialog>
#include <string>

namespace Ui {
class FriendList;
}

class FriendList : public QDialog
{
    Q_OBJECT

public:
    explicit FriendList(QWidget *parent = 0);
    ~FriendList();
    void setFriendList(std::string);

private:
    Ui::FriendList *ui;

private slots:
    void on_QuitButton_clicked();
};


#endif // FRIENDLIST_H
