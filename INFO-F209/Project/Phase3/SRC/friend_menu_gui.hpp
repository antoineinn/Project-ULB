#ifndef FRIEND_HPP
#define FRIEND_HPP
#include <string>
#include <QObject>
#include "./GUI/friendmenu.h"
#include "./GUI/addfriend.h"
#include "./GUI/deletefriend.h"
#include "./GUI/friendlist.h"

class FriendGui : public QObject {
    Q_OBJECT
public:
    FriendGui(QObject *parent=0);
    void menuInit(int, std::string);
    ~FriendGui();
    bool getExitState();

signals:
    void returnMenuOption();
    
private:
    int sockfd;
    std::string username;
    bool exit = false;
    void displayOptionFriend();
    void showFriend();
    void acceptAddFriendAsk();
    FriendMenu friendMenu;
    AddFriend addFriendMenu;
    DeleteFriend deleteFriendMenu;
    FriendList friendList;

private slots:
    void displayAddFriendMenu();
    void displayDeleteFriendMenu();
    void displayRequestMenu();
    void displayFriendList();
    void addFriend(std::string);
    void deleteFriend(std::string);
    void quitAddFriendMenu();
    void quitDeleteFriendMenu();
    void exitMenu();

};

#endif //FRIEND_HPP




