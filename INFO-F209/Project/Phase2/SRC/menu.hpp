#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using std::string;
class Menu{
public:
    void menuInit();
    void menuEndGame();
    void setSocket(int &i); 
    char* get_username();
    ~Menu();

private:
    int sockfd;
    bool connected;
    string username;
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
};

#endif //MENU_HPP
