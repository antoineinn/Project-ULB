#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "menu.hpp"
#include "limits"
#include "friend.hpp"

/* PUBLIC */

// Constructor

Menu::Menu(int &socket): sockfd(socket) {}

// Functions

void Menu::menuInit() {
    while(!this->connected and !this->exitApp){
        if (this->endGame) {
            this->connected = true;
            this->endGame = false;
        }
        else
            this->displayPlayerLogIn();
        if (this->connected){
            this->displayPlayerOption();
        }
    }
}

void Menu::menuEndGame() {
    this->endGame = true;
    this->connected = false;
    this->menuInit();
}

char* Menu::get_username(){
    return const_cast<char*>(this->username.c_str());
}

/* PRIVATE */

// Fonctions

void Menu::displayPlayerLogIn() {
    int choice = 0;

    std::cout << "Welcome in the game : \"Tower Defense - Meat war : Rise of the fallen vegan\" !" << std::endl;
    choice = this->playerLoginChoice();
    while (!this->isValid(choice, 1, 3)){
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
        case 3:
            this->exitApplication();
            break;
    }
}

void Menu::displayPlayerOption() {
    std::cout << "Welcome in the game : \"Tower Defense - Meat war : Rise of the fallen vegan\" !" << std::endl;
    int choice = this->playerOptionChoice();

    while (! this->isValid(choice, 1, 6)){
        std::cout<< "Error Bad Choice. Please make a new choice." << std::endl;
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
			this->displayPlayerOption();
            break;
        case 5:
            this->friendView();
            break;
        case 6:
            this->logOut();
            break;
    }
}

int Menu::playerLoginChoice() {
    int choice;
    
	std::cout << "Please choose one of these options:" << std::endl;
    std::cout << "1) Connect." << std::endl;
    std::cout << "2) Create an account." << std::endl;
    std::cout << "3) Exit Application" << std::endl;
    while(!(std::cin >> choice)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Try again: ";
    } 
    
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
    std::cout << "Invalid input. Try again: ";
    } 
    
	return choice;
}

string Menu::playerSupportChoice(){
	std::string username;
    std::cout << "Insert the player you want to join : ";
    std::cin >> username;
    return username;
}

string Menu::playerUsernameChoice() {
    std::string username;

    std::cout << "Username: "; // Enter the username
    std::cin >> username;

    return username;
}
int Menu::playerPasswordChoice() {
    int password;

    std::cout << "Password: "; // Enter the password
    while(!(std::cin >> password)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Try again: ";
    }

    return password;
}

void Menu::profileView() {
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

void Menu::rankingView() {
	int choice = this->rankingOptionChoice();
	while(!this->isValid(choice,1, 3)){
		std::cout<<"Error bad choice. Make a new one."<<std::endl;
		choice = this->rankingOptionChoice();
	}
	if(send(this->sockfd, &choice, sizeof(choice), 0)==-1){
		std::cout<<"error ranking choice"<<std::endl;
	}
	char highscore[1024];
	std::cout<<"**Top highscore**"<<std::endl;
	if(recv(this->sockfd, highscore, 1024, 0)==-1){
		std::cout<<"highscore recv error"<<std::endl;
		exit(1);
	}
	std::cout<<highscore;
    std::cout<<"*****************"<<std::endl;
}
int Menu::rankingOptionChoice(){
	int choice;
	std::cout<<"Choose your ranking:\n";
	std::cout<<"1)team ranking\n";
	std::cout<<"2)chrono ranking\n";
	std::cout<<"3)vs ranking\n";
	while(!(std::cin >> choice)){
    	std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    	std::cout << "Invalid input. Try again: ";
    }
	return choice;
}
void Menu::friendView() {
    Friend friend_menu = Friend(this->sockfd, this->username);
    friend_menu.menuInit();
    this->displayPlayerOption();
}

void Menu::playerLogIn() {
    int password, done=0;

    while(done!=1){
        std::cout<<"-------\n"<<"To quit the Login Menu tap 'Q' or something else to log in."<<std::endl;
        std::string quitChoice;
        std::cin>>quitChoice;
        if(quitChoice == "Q"){
            int quit = 1;
            if(send(this->sockfd,&quit,sizeof(quit),0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
            return;
        }
        else{
            int quit = 0;
            if(send(this->sockfd,&quit,sizeof(quit),0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
        }
        std::cout<<"-------\n"<<"Enter your username and password to log in.\n"<<"------"<<std::endl;
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
                std::cout<<"The ID or the password is incorrect ! Please retry."<<std::endl;
            }
        else if(done==2)
            {
                std::cout<<"The account you tried to connect is already logged!"<<std::endl;
            }
        else
            {
                std::cout<<"The ID and the password are correct! Welcome to the game."<<std::endl;
            }
        }
    this->connected = true;
}

void Menu::registerAccount() {
    std::string username;
    int done=0, password;

    std::cout << "Welcome to the account creation. Please complete the following fields:" << std::endl;
    while(done==0){
        std::cout<<"-------\n"<<"To quit the Create Account Menu tap 'Q' or something else to continue."<<std::endl;
        std::string quitChoice;
        std::cin>>quitChoice;
        if(quitChoice == "Q"){
            int quit = 1;
            if(send(this->sockfd,&quit,sizeof(quit),0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
            return;
        }
        else{
            int quit = 0;
            if(send(this->sockfd,&quit,sizeof(quit),0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
        }
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
            std::cout<<"The ID you choose is already taken! Choose another one."<<std::endl;
        }
        else
        {
            std::cout<<"Your account was successfully created."<<std::endl;
        }

    }
    this->playerLogIn();
}

void Menu::startParty() {
    int gameModeChoice;

    gameModeChoice = this->playerGameModeChoice();
    while(!this->isValid(gameModeChoice, 1, 3)){
        std::cout<< "Error: bad choice. Please make a new choice." << std::endl;
        gameModeChoice = this->playerGameModeChoice();
    }
    if(send(this->sockfd,&gameModeChoice,sizeof(gameModeChoice),0)==1)
    {
        std::cout<<"send"<<std::endl;
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
    std::cout << "Invalid input. Try again: ";
    }
    
	return choice;
}

void Menu::supportParty() {
    string name = this->playerSupportChoice();
	const char* finalName = name.c_str();
	send(this->sockfd, finalName, 1024, 0);
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

void Menu::exitApplication(){
    this->exitApp = true;
    std::cout << "Bye !" << std::endl;
}
