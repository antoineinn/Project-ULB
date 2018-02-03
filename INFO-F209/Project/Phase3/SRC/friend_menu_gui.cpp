#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "limits"
#include <QMessageBox>
#include "friend_menu_gui.hpp"
#define DATASIZE 1024
//Constructor
FriendGui::FriendGui(QObject *parent):
    QObject(parent){
    connect(&friendMenu, SIGNAL(showAddFriend()), this, SLOT(displayAddFriendMenu()));
    connect(&friendMenu, SIGNAL(showDeleteFriend()), this, SLOT(displayDeleteFriendMenu()));
    connect(&friendMenu, SIGNAL(showRequestFriend()), this, SLOT(displayRequestMenu()));
    connect(&friendMenu, SIGNAL(showFriendList()), this, SLOT(displayFriendList()));
    connect(&friendMenu, SIGNAL(signalQuit()), this, SLOT(exitMenu()));
    connect(&addFriendMenu, SIGNAL(addSignal(std::string)), this, SLOT(addFriend(std::string)));
    connect(&addFriendMenu, SIGNAL(quitAddFriend()),this, SLOT(quitAddFriendMenu()));
    connect(&deleteFriendMenu, SIGNAL(deleteSignal(std::string)), this, SLOT(deleteFriend(std::string)));
    connect(&deleteFriendMenu, SIGNAL(quitDeleteFriend()), this, SLOT(quitDeleteFriendMenu()));
    }

FriendGui::~FriendGui(){}

void FriendGui::menuInit(int socketfd, std::string user){
    this->sockfd = socketfd;
    this->username = user;
    this->displayOptionFriend();
}



void FriendGui::displayOptionFriend(){
    friendMenu.show();
}

void FriendGui::displayAddFriendMenu(){
    int choice = 1;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    addFriendMenu.show();
}

void FriendGui::addFriend(std::string friendUsername)
{   
    int done=0,exist=0;
    if(friendUsername == this->username){
        addFriendMenu.popupNotAddHimSelf();
        addFriendMenu.clearFriendLabel();
        addFriendMenu.show();
        return;
    }
    int isFinished=0;
    if(send(this->sockfd,&isFinished,sizeof(isFinished),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    const char * friendToAdd= friendUsername.c_str();    
    if(send(this->sockfd,friendToAdd,DATASIZE,0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    const char *myUsername=this->username.c_str();
    if(send(this->sockfd,myUsername,DATASIZE,0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    if(recv(this->sockfd,&exist,sizeof(exist),0) == -1)
    {
        std::cout<<"recv"<<std::endl;
    }
    if(exist)
    {
        if(recv(this->sockfd,&done,sizeof(done),0) == -1)
        {
            std::cout<<"recv"<<std::endl;
        }
        if(done)
        {
            addFriendMenu.popupRequestFriendSent();
        }
        else
        {
            addFriendMenu.popupRequestFriendAllready(friendUsername);
        }
    }
    else
    {
        addFriendMenu.popupFriendNotExist();
    }
    int answer;
    answer = QMessageBox::question(&addFriendMenu, "Add Friend", "Do you want to add another user as your friend ?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (answer == QMessageBox::Yes) {
        addFriendMenu.clearFriendLabel();
        addFriendMenu.show();
        done = 0;
    } else {
        done = 1;
        addFriendMenu.hide();
    }
    if(send(this->sockfd,&done,sizeof(done),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
}

void FriendGui::quitAddFriendMenu(){
    int isFinished = 1;
    if(send(this->sockfd,&isFinished,sizeof(isFinished),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }

}

void FriendGui::displayDeleteFriendMenu(){
    int choice = 2;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    deleteFriendMenu.show();
}




void FriendGui::deleteFriend(std::string friendUsername)
{
    //CODE A REVOIR et donc serveur à modifier A VOIR car très flou
    int done=0,exist=0;
    const char * finalUsername;
    if(friendUsername == this->username){
        deleteFriendMenu.popupNotDeleteHimSelf();
        deleteFriendMenu.clearFriendLabel();
        deleteFriendMenu.show();
        return;
    }
    int isFinished=0;
    if(send(this->sockfd,&isFinished,sizeof(isFinished),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    finalUsername= friendUsername.c_str();
    
    if(send(this->sockfd,finalUsername,DATASIZE,0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    finalUsername=this->username.c_str();
    if(send(this->sockfd,finalUsername,DATASIZE,0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    if(recv(this->sockfd,&exist,sizeof(exist),0) == -1)
    {
        std::cout<<"recv"<<std::endl;
    }
    if(exist)
    {
        if(recv(this->sockfd,&done,sizeof(done),0) == -1)
        {
            std::cout<<"recv"<<std::endl;
        }
        if(done)
        {
            int isFound;
            if(recv(this->sockfd,&isFound,sizeof(isFound),0) == -1)
            {
                std::cout<<"recv"<<std::endl;
            }
            if(isFound==1)
            {
                deleteFriendMenu.popupDeleteFriendSuccess(friendUsername);
            }
            else
            {
                deleteFriendMenu.popupNotYourFriend();
            }
        }
    }
    else{
        deleteFriendMenu.popupFriendNotExist();
    }
    int answer;
    answer = QMessageBox::question(&addFriendMenu, "Delete Friend", "Do you want to delete another friend ?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (answer == QMessageBox::Yes) {
        deleteFriendMenu.clearFriendLabel();
        deleteFriendMenu.show();
        done = 0;
    } else {
        done = 1;
        deleteFriendMenu.hide();
    }
    if(send(this->sockfd,&done,sizeof(done),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
}

void FriendGui::quitDeleteFriendMenu(){
    int isFinished = 1;
    if(send(this->sockfd,&isFinished,sizeof(isFinished),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }

}

void FriendGui::displayFriendList(){
    int choice = 4;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    this->showFriend();
    friendList.show();
}

void FriendGui::showFriend()
{
    std::string frList = ""; 
    char friendUsername[DATASIZE];
    if(send(this->sockfd,this->username.c_str(),DATASIZE,0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    int done=0;
    while(!done)
    {   

        if(recv(this->sockfd,&done,sizeof(done),0) == -1)
        {
           std::cout<<"recv error"<<std::endl;
        }
        if(done==0)
        {
            if(recv(this->sockfd,friendUsername,DATASIZE,0) == -1)
            {
                std::cout<<"recv error"<<std::endl;
            }
            frList = frList+friendUsername+"\n";
        }
    }
    if(frList.length() == 0){
        frList = "Go make some friends you pathetic carrot eater!\n╭∩╮(Ο_Ο)╭∩╮";
    }
    friendList.setFriendList(frList);
}

void FriendGui::displayRequestMenu(){
    int choice = 3;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    this->acceptAddFriendAsk();
}

void FriendGui::acceptAddFriendAsk()
{
    if(send(this->sockfd,this->username.c_str(),DATASIZE,0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    int done=0,hasRequest=0;
    std::string choice;
    char friendUsername[DATASIZE];
    while(!done)
    {
        if(recv(this->sockfd,&done,sizeof(done),0) == -1)
        {
           std::cout<<"recv error1"<<std::endl;
        }

        if(done==0)
        {
            if(recv(this->sockfd,friendUsername,DATASIZE,0) == -1)
            {
                std::cout<<"recv error2"<<std::endl;
            }

            int answer;
            std::string text = "Do you want to accept the request friend from";
            text = text +friendUsername + "?";
            answer = QMessageBox::question(&friendMenu, "Accept Request Friend", text.c_str(),
                                QMessageBox::Yes|QMessageBox::No);

            if(answer == QMessageBox::Yes)
            {
                choice = "A";
            }
            else
            {
               choice = "D";
            }

            if(send(this->sockfd,choice.c_str(),DATASIZE,0)==1)
            {
                std::cout<<"send"<<std::endl;
            }
        }

    }
    if(recv(this->sockfd,&hasRequest,sizeof(hasRequest),0) == -1)
        {
            std::cout<<"recv error2"<<std::endl;
        }
    if(hasRequest==0)
    {
        QMessageBox::information(&friendMenu, "Accept Request Friend", "You didn't receive new friend requests");
    }
}

bool FriendGui::getExitState(){
    return exit;
}

void FriendGui::exitMenu(){
    int choice = 5;
    if(send(this->sockfd,&choice,sizeof(choice),0)==1)
    {
        std::cout<<"send"<<std::endl;
    }
    emit returnMenuOption();
}
