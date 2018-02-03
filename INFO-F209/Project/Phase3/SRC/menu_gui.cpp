#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <QWidget>
#include "menu_gui.hpp"
#include "friend_menu_gui.hpp"

//Public Method

MenuGui::MenuGui(QObject *parent) : QObject(parent){
  connect(&loginMenuOption,SIGNAL(showLogin()),this,SLOT(displayPlayerLogIn()));
  connect(&loginMenuOption,SIGNAL(showCreate()),this,SLOT(displayCreateAccount()));
  connect(&loginMenuOption,SIGNAL(quitAppSignal()), this, SLOT(exitApplication()));
  connect(&loginMenu,SIGNAL(loginSignal(std::string, int)),this,SLOT(playerLogIn(std::string, int)));
  connect(&loginMenu,SIGNAL(quitLogInSignal()),this,SLOT(quitLogInMenu()));
  connect(&createAccount,SIGNAL(createSignal(std::string, int)),this,SLOT(registerAccount(std::string, int)));
  connect(&createAccount,SIGNAL(quitCreateAccountSignal()),this,SLOT(quitCreateAccountMenu()));
  connect(&playerMenuOption,SIGNAL(showFriend()),this,SLOT(friendView()));
  connect(&playerMenuOption,SIGNAL(signalLogOut()),this,SLOT(logOut()));
  connect(&playerMenuOption, SIGNAL(showProfil()), this, SLOT(displayProfil()));
  connect(&friend_menu_gui,SIGNAL(returnMenuOption()),this,SLOT(displayPlayerOption()));
  connect(&profilView, SIGNAL(showMenuOption()), this, SLOT(displayPlayerOption()));
  connect(&playerMenuOption, SIGNAL(playSignal(int)), this, SLOT(startParty(int)));
  connect(&playerMenuOption, SIGNAL(showRanking()), this, SLOT(displayRanking()));
  connect(&rankView, SIGNAL(retMenuOption()), this, SLOT(displayPlayerOption()));
  connect(&game_display, SIGNAL(quitSignalGame()), this, SLOT(quitGame()));
}


void MenuGui::menuInit(int &i){
    this->setSocket(i);
    this->displayPlayerLogInMenuOption();
}

//Private Method

void MenuGui::setSocket(int &i)
{
    this->sockfd=i;
}

void MenuGui::displayProfil(){
	this->profileView();
    profilView.show();
}

void MenuGui::profileView()
{	int choice = 3;
	if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    char friendUsername[1024];
    int isFound;
    profilView.setPlayerLineEdit(this->username);
    const char * finalUsername=this->username.c_str();
    if(send(this->sockfd,finalUsername,1024,0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    int done=0;
    std::string friendList = "";
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
            friendList = friendList + friendUsername + "\n";
        }
    }
    if(friendList.length()==0){
    	friendList = friendList + "┌∩┐(◕_◕)┌∩┐" +"\n";
    }
    profilView.setFriendLabel(friendList);
}

void MenuGui::displayRanking(){
	this->rankingView();
    rankView.show();
}

void MenuGui::rankingView() {
	int choice=4, step=1;
	char save[1024];
	
	while (step<4) {
		// enter the function rankingView on the server
		if(send(this->sockfd,&choice,sizeof(choice),0)==1) {
		    std::cout<<"send"<<std::endl;
		}
		// select each time a different ranking
		if(send(this->sockfd,&step,sizeof(step),0)==1) {
		    std::cout<<"send"<<std::endl;
		}
		// retrieve the ranking
		if(recv(this->sockfd,&save,1024,0)==1) {
			std::cout<<"recv"<<std::endl;
		}
		switch(step){
			case 1:
				rankView.setTeamRankingLineEdit(save);
				break;
			case 2:
				rankView.setChronoRankingLineEdit(save);
				break;
			case 3:
				rankView.setVsRankingLineEdit(save);
				break;
		}
		step++;
	}
}


void MenuGui::displayPlayerLogInMenuOption(){
     loginMenuOption.show();
}

void MenuGui::displayPlayerLogIn(){
    int choice = 1;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    loginMenu.clearLineEdit();
    loginMenu.show();
}

void MenuGui::quitLogInMenu(){
    int quitChoice = 1; 
    if(send(this->sockfd,&quitChoice,sizeof(quitChoice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    loginMenu.clearLineEdit();
    this->displayPlayerLogInMenuOption();
}

void MenuGui::displayCreateAccount(){
    int choice = 2;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    createAccount.clearLineEdit();
    createAccount.show();
    createAccount.popupWelcome();
}

void MenuGui::quitCreateAccountMenu(){
    int quitChoice = 1;
    if(send(this->sockfd,&quitChoice,sizeof(quitChoice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    createAccount.clearLineEdit();
    this->displayPlayerLogInMenuOption();
}

void MenuGui::displayPlayerOption(){
    playerMenuOption.show();
}

void MenuGui::startParty(int gameMode){
    /*int choice = 1;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    if (send(this->sockfd, &gameMode, sizeof(gameMode), 0) == 1)
    {
        std::cout<<"send"<<std::endl;
    }*/
    game_display.setWindow(gameMode);
    game_display.show();
}

void MenuGui::quitGame(){
    this->displayPlayerOption();
}

void MenuGui::friendView() {
    int choice = 5;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    friend_menu_gui.menuInit(this->sockfd, this->username);
}

void MenuGui::playerLogIn(std::string userName, int password) {
    int done=0; int quitChoice = 0;
    username = userName;
    const char *finalUsername = username.c_str();
    if(send(this->sockfd,&quitChoice,sizeof(quitChoice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
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
            //exit(1);
        }
        if(done==0)
        {
            loginMenu.popupNotValid();
            loginMenu.clearLineEdit();
        }
        else if(done==2)
        {
            loginMenu.popupAlreadyLogged();
            loginMenu.clearLineEdit();
        }
        else
        {
            loginMenu.popupValid();
            loginMenu.hide();
            this->displayPlayerOption();
        }
}


void MenuGui::registerAccount(std::string userName, int password){
    int done=0; int quitChoice = 0;
    const char * finalUsername= userName.c_str();
    if(send(this->sockfd,&quitChoice,sizeof(quitChoice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
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
        }
    if(done==0)
    {
       createAccount.popupNotValid();
       createAccount.clearLineEdit();
    }
    else
    {
        createAccount.popupValid();
        createAccount.hide();
        loginMenu.clearLineEdit();
        loginMenu.show();
    }
}


void MenuGui::logOut() {
    int choice = 6;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    const char * finalUsername= this->username.c_str();
    if (send(this->sockfd, finalUsername, 1024, 0)==1) {
        std::cout<<"send"<<std::endl;
    }
    this->displayPlayerLogInMenuOption();
}

void MenuGui::exitApplication(){
    int choice = 3;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
}
