#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using std::string;
class Menu{
public:
	// constructors
    Menu(int &socket);
    ~Menu()=default;
	// functions
    void menuInit();
    void menuEndGame();
    char* get_username();

private:
    int sockfd;
    bool endGame = false;
    bool connected = false;
    bool exitApp = false;
    string username;
	// functions
    void displayPlayerLogIn();
    void displayPlayerOption();
    int playerLoginChoice();
    int playerOptionChoice();
    string playerUsernameChoice();
    string playerSupportChoice();
    int playerPasswordChoice();
    void profileView();
    int rankingOptionChoice();
    void rankingView();
    void friendView();
    void playerLogIn();
    void registerAccount();
    void startParty();
    int playerGameModeChoice();
    void supportParty();
    bool isValid(int, int, int);
    void logOut();
    void exitApplication();
};

#endif //MENU_HPP
