#ifndef MENUGUI_HPP
#define MENUGUI_HPP
#include <string>
#include <QObject>
#include "./GUI/loginmenuoption.h"
#include "./GUI/loginmenu.h"
#include "./GUI/createaccount.h"
#include "./GUI/menuoption.h"
#include "./GUI/friendmenu.h"
#include "friend_menu_gui.hpp"
#include "./GUI/profilview.h"
#include "./GUI/rankingview.h"
#include "./GUI/gamedisplaygui.h"

using std::string;

class MenuGui : public QObject {
    Q_OBJECT
public:
    MenuGui(QObject *parent=0);
    void menuInit(int&i);

private:
    int sockfd;
    string username;
    void setSocket(int &i);
    void displayPlayerLogInMenuOption();
    void profileView();
    void rankingView();
    void supportParty();
    void exit();
    LoginMenuOption loginMenuOption;
    LoginMenu loginMenu;
    CreateAccount createAccount;
    MenuOption playerMenuOption;
    FriendGui friend_menu_gui;
    ProfilView profilView;
	RankingView rankView;
	GameDisplayGui game_display;

private slots:
    void displayPlayerLogIn();
    void displayCreateAccount();
	void startParty(int);
    void friendView();
    void displayProfil();
	void displayRanking();
    void playerLogIn(std::string, int);
    void registerAccount(std::string, int);
    void displayPlayerOption();
    void quitLogInMenu();
    void quitCreateAccountMenu();
    void logOut();
    void exitApplication();
    void quitGame();
};

#endif //MENUGUI_HPP
