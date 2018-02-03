#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "menu.hpp"
#include "limits"
#include "friend.hpp"

//Public Method
void Menu::menuInit() {
    while(!this->connected){
        this->displayPlayerLogIn();
        if (this->connected){
            this->displayPlayerOption();
        }
    }
}

void Menu::menuEndGame() {
    this->displayPlayerOption();
    if(!this->connected){
        this->displayPlayerLogIn();
    }
}

char* Menu::get_username(){return const_cast<char*>(this->username.c_str());}

//Private Method
void Menu::displayPlayerLogIn() {
    int choice = 0;
    std::cout << "Welcome in the tower defense game - Meat war : Rise of the fallen vegan !" << std::endl;
    choice = this->playerLoginChoice();
    while (!this->isValid(choice, 1, 2)){
        std::cout << "You entered a wrong option." << std::endl;
        choice = this->playerLoginChoice();
    }
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
        {
            std::cout<<"send"<<std::endl;
        }
    switch(choice) {
        case 1:
            this->playerLogIn();
            break;
        case 2:
            this->registerAccount();
            break;
    }
}

void Menu::displayPlayerOption() {
    std::cout << "Welcome in the tower defense game - Meat war : Rise of the fallen vegan !" << std::endl;
    int choice = this->playerOptionChoice();

    while (! this->isValid(choice, 1, 6)){
        std::cout<< "Error Bad Choice. Please make a new choice" << std::endl;
        choice = this->playerOptionChoice();
    }
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    switch(choice) {
        case 1:
            this->startParty();
            break;
        case 2:
            this->supportParty();
            break;
        case 3:
            this->profileView();
			this->displayPlayerOption();
            break;
        case 4:
            this->rankingView();
            break;
        case 5:
            this->friendView();
            break;
        case 6:
            this->logOut();
            break;
    }
}
void Menu::setSocket(int &i)
{
    this->sockfd=i;
}

int Menu::playerLoginChoice() {
    int choice;
    std::cout << "Please choose one of these options:" << std::endl;
    std::cout << "1) Connect." << std::endl;
    std::cout << "2) Create an account." << std::endl;
    while(!(std::cin >> choice)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input.Try again: ";
    }
    std::cout << "You enterd: " << choice << std::endl; 
    return choice;
}
int Menu::playerOptionChoice() {
    int choice;
    std::cout << "Please choose one of these options:" << std::endl;
    std::cout << "1) Play." << std::endl;
    std::cout << "2) Support." << std::endl;
    std::cout << "3) View profil." << std::endl;
    std::cout << "4) Consult ranking." << std::endl;
    std::cout << "5) Consult friend." << std::endl;
    std::cout << "6) Deconnexion." << std::endl;

    while(!(std::cin >> choice)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input.Try again: ";
    }
    std::cout << "You enterd: " << choice << std::endl; 
    return choice;
}
string Menu::playerUsernameChoice() {
    std::string username;
    // Introduire son identifiant
    std::cout << "Username: ";
    std::cin >> username;

    return username;
}
int Menu::playerPasswordChoice() {
    int password;
    // Introduire son mot de passe
    std::cout << "Password: ";
    while(!(std::cin >> password)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input.Try again: ";
    }
    std::cout << "You enterd: " << password << std::endl; 
    return password;
}
void Menu::profileView() 
{
    char friendUsername[1024];
    int isFound;
    const char * finalUsername=this->username.c_str();
    if(send(this->sockfd,finalUsername,1024,0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    int done=0;
    std::cout<<"**********\nYour profil:"<<std::endl;
    std::cout<<"Username: "<< finalUsername<<std::endl;
    std::cout<<"\nYour friend list:"<<std::endl;
    while(!done)
    {
        if(recv(this->sockfd,&done,sizeof(done),0) == -1)
        {
            std::cout<<"recv error"<<std::endl;
        }
		if(recv(this->sockfd,&isFound,sizeof(isFound),0) == -1)
        {
            std::cout<<"recv error"<<std::endl;
        }
        if(isFound==1)
        {
            if(recv(this->sockfd,friendUsername,1024,0) == -1)
            {
                std::cout<<"recv error"<<std::endl;
            }
            std::cout<<friendUsername<<std::endl;
        }
    }
    std::cout<<"**********"<<std::endl;
} 
void Menu::rankingView() {}
void Menu::friendView() {
    Friend friend_menu = Friend(this->sockfd, this->username);
    friend_menu.menuInit();
    this->displayPlayerOption();
}

void Menu::playerLogIn() {
    int password,done=0;
    std::cout<<"-------\n"<<"Enter your username and password to log in\n"<<"------"<<std::endl;
    while(done!=1){
        this->username = this->playerUsernameChoice();
        password = this->playerPasswordChoice();
        const char * finalUsername= username.c_str();
        if(send(this->sockfd,finalUsername,1024,0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
        if(send(this->sockfd,&password,sizeof(password),0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
        if ((recv(this->sockfd,&done,sizeof(done),0)) == -1)
                {
                    std::cout<<"recv"<<std::endl;
                    exit(1);
                }
        if(done==0)
            {
                std::cout<<"The id or the password is incorrect ! Please retry."<<std::endl;
            }
        else if(done==2)
            {
                std::cout<<"The account you tried to connect is already logged!"<<std::endl;
            }
        else
            {
                std::cout<<"The id and the pass are correct! Welcome to the game."<<std::endl;
            }
        }
    this->connected = true;
}

void Menu::registerAccount() {
    std::string username;
    int done=0,password;
    std::cout << "Welcome to the account creation. Please complete the following fields:" << std::endl;
    while(done==0){
        username = this->playerUsernameChoice();
        password = this->playerPasswordChoice();
        const char * finalUsername= username.c_str();
        if(send(this->sockfd,finalUsername,1024,0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
        if(send(this->sockfd,&password,sizeof(password),0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
        if ((recv(this->sockfd,&done,sizeof(done),0)) == -1)
            {
                std::cout<<"redv"<<std::endl;
                exit(1);
            }
        if(done==0)
        {
            std::cout<<"The id you choose is already taken! Choose another one."<<std::endl;
        }
        else
        {
            std::cout<<"Your account was successfuly created."<<std::endl;
        }

    }
    /* envoit des données userName et password pour enregistrer dans bdd(fichier.txt) */
    this->playerLogIn();
}
void Menu::startParty() {
    int gameModeChoice, playerNumber;
    gameModeChoice = this->playerGameModeChoice();
    while(!this->isValid(gameModeChoice, 1, 3)){
        std::cout<< "Error Bad Choice. Please make a new choice" << std::endl;
        gameModeChoice = this->playerGameModeChoice();
    }
    if(send(this->sockfd,&gameModeChoice,sizeof(gameModeChoice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    switch(gameModeChoice){
        case 1:
            playerNumber = this->playerSelectNumber(1, 4);
            while(!this->isValid(playerNumber, 1,4)){
                std::cout<< "Error Bad Choice. Please make a new choice" << std::endl;
                playerNumber = this->playerSelectNumber(1, 4);
            }
            break;
        default:
            playerNumber = 4;
            break;
    }
}
int Menu::playerGameModeChoice() {
    int choice;
    std::cout << "1) Team mode" << std::endl;
    std::cout << "2) Time trial mode" << std::endl;
    std::cout << "3) Vs mode " << std::endl;

    while(!(std::cin >> choice)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input.Try again: ";
    }
    std::cout << "You enterd: " << choice << std::endl; 
    return choice;
}

int Menu::playerSelectNumber(int minValue, int maxValue) {
    int choice;
    std::cout<< "How much player do you want for playing ?\n";
    std::cout<< "Make a choice between " << minValue <<" and "<< maxValue << std::endl;
    while(!(std::cin >> choice)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input.Try again: ";
    }
    std::cout << "You enterd: " << choice << std::endl; 
    return choice;
}
void Menu::supportParty() {
    int choice = this->playerGameModeChoice();
    while(!this->isValid(choice, 1, 3)){
        std::cout<< "Error Bad Choice. Please make a new choice" << std::endl;
        choice = this->playerGameModeChoice();
    }
    /*
    TODO faire appel à la classe supporter et rejoindre une partie en fonction du choix de mode de jeu
    */
}

bool Menu::isValid(int value, int minValue, int maxValue) {
    bool valid = false;
    if(value >= minValue && value <= maxValue){
        valid = true;
    }
    return valid;
}
void Menu::logOut() {
    const char * finalUsername= this->username.c_str();
    if (send(this->sockfd, finalUsername, 1024, 0)==1) {
        std::cout<<"send"<<std::endl;
    }
    this->connected = false;
}
