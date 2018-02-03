#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using std::string;
class Menu{
public:
    void menuInit();
    void setSocket(int &i);
    ~Menu();

private:
    int sockfd;
    bool connected;
    void displayPlayerLogIn();
    void displayPlayerOption();
    void profileView();
    void rankingView();
    void friendView();
    void playerLogIn();
    void registerAccount();
    int playerLoginChoice();
    int playerOptionChoice();
    string playerUsernameChoice();
    int playerPasswordChoice();
    int playerGameModeChoice();
    int playerSelectNumber(int, int);
    void startParty();
    void supportParty();
    bool isValid(int, int, int);
    void logOut();
    void exitApp();
};

#endif //MENU_HPP
