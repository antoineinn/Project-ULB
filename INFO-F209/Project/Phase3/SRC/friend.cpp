#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "limits"
#include "friend.hpp"
#define DATASIZE 1024

/* PUBLIC */

//Constructor
Friend::Friend(int socketfd, std::string user):
    sockfd(socketfd), username(user){}

Friend::~Friend() {}

// Functions
void Friend::menuInit() {
    int choice;
    while(not exit){
        choice = this->displayOptionChoice();
        while (!this->isValid(choice, 1, 5)) {
            std::cout << "You entered a wrong option." << std::endl;
            choice = this->displayOptionChoice();
        }
        if(send(this->sockfd,&choice,sizeof(choice),0)==1) {
            std::cout<<"send"<<std::endl;
        }
        switch(choice) {
            case 1:
                this->addFriend();
                break;
            case 2:
                this->deleteFriend();
                break;
            case 3:
                this->acceptAddFriendAsk();
                break;
            case 4:
                this->showFriend();
                break;
            case 5:
                this->exit = true;
                break;
        }
    }
}

/* PRIVATE */

int Friend::displayOptionChoice() {
    int choice;

    std::cout << "Please choose one of these options:" << std::endl;
    std::cout << "1) Add a friend." << std::endl;
    std::cout << "2) Delete a friend." << std::endl;
    std::cout << "3) Accept request of a friend." << std::endl;
    std::cout << "4) Show friend list." << std::endl;
    std::cout << "5) quit." << std::endl;
    while(!(std::cin >> choice)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Try again: ";
    }

    return choice;
}

void Friend::addFriend() {
    int done=0,exist=0;

    while(!done) {
        std::string friendUsername;
        std::cout<<"User id you want to add:";
        std::cin >> friendUsername;
        while(friendUsername == this->username) {
            std::cout<< "You can't add yourself to your friend list. Please try a valid username.\nOr press \"q\" to quit." << std::endl;
            std::cin >> friendUsername;
        }
        int isFinished = 0;
        if(send(this->sockfd,&isFinished,sizeof(isFinished),0) == -1) {
            std::cout<<"send"<<std::endl;
        }
        const char * friendToAdd= friendUsername.c_str();
        if(friendUsername=="q") {
            std::cout<<"You choose to quit."<<std::endl;
            if(send(this->sockfd,friendToAdd,DATASIZE,0)==1) {
                std::cout<<"send"<<std::endl;
            }
            done=1;
        }
        else {
            if(send(this->sockfd,friendToAdd,DATASIZE,0)==1) {
                std::cout<<"send"<<std::endl;
            }
            const char *myUsername=this->username.c_str();
            if(send(this->sockfd,myUsername,DATASIZE,0)==1) {
                std::cout<<"send"<<std::endl;
            }
            if(recv(this->sockfd,&exist,sizeof(exist),0) == -1) {
                std::cout<<"recv"<<std::endl;
            }
            if(exist) {
                if(recv(this->sockfd,&done,sizeof(done),0) == -1) {
                    std::cout<<"recv"<<std::endl;
                }
                if(done) {
                    std::cout<<"The friend request has been send !"<<std::endl;
                }
                else {
                    std::cout<<"You already sent a friend request to "<<friendUsername.c_str()<<" or the user "<<friendUsername.c_str()<<" is already your friend !"<<std::endl;
                }
                bool isValid=false;
                while(!isValid) {
                    std::string choice;
                    std::cout<<"Choose \"add\" to add another friend or \"q\" to quit"<<std::endl;
                    std::cin >> choice;
                    if(choice=="add") {
                        done=0;
                        isValid=true;
                    }
                    else if(choice=="q") {

                        isValid=true;
                        done=1;
                    }
                    else {
                        std::cout<<"Please choose a valid option."<<std::endl;
                    }

                }
                if(send(this->sockfd,&done,sizeof(done),0)==1) {
                    std::cout<<"send"<<std::endl;
                }
            }
            else {
                std::cout<<"The friend you tried to add doesn't exist!"<<std::endl;
                std::string choice;
                std::cout<<"if you want to retry press \"r\" or press \"q\" to quit:"<<std::endl;
                std::cin>>choice;
                bool finish=false;
                while(not finish) {
                    if(choice=="r") {
                        finish=true;
                        done = 0;
                    }
                    else if(choice=="q") {
                        done=1;
                        finish=true;
                    }
                    if(send(this->sockfd,&done,sizeof(done),0)==1) {
                        std::cout<<"send"<<std::endl;
                    }
                }
            }
        }
    }
}

void Friend::deleteFriend() {
    int done=0, exist=0;
    const char * finalUsername;
    while(!done) {
        std::string friendUsername;
        std::cout<<"User ID you want to delete from your friend list:";
        std::cin >> friendUsername;
        while(friendUsername == this->username) {
            std::cout<< "You can't delete yourself. Please try to delete a valid username.\nOr press \"q\" to quit." << std::endl;
            std::cin >> friendUsername;
        }
        int isFinished = 0;
        if(send(this->sockfd,&isFinished,sizeof(isFinished),0) == -1) {
            std::cout<<"send"<<std::endl;
        }
        finalUsername= friendUsername.c_str();
        if(friendUsername=="q") {
            std::cout<<"You choose to quit."<<std::endl;
            done=true;
            if(send(this->sockfd,finalUsername,DATASIZE,0)==1) {
                std::cout<<"send"<<std::endl;
            }
        }
        else {
            if(send(this->sockfd,finalUsername,DATASIZE,0)==1) {
                std::cout<<"send"<<std::endl;
            }
            finalUsername=this->username.c_str();
            std::cout<<finalUsername<<std::endl;
            if(send(this->sockfd,finalUsername,DATASIZE,0)==1) {
                std::cout<<"send"<<std::endl;
            }
            if(recv(this->sockfd,&exist,sizeof(exist),0) == -1) {
                std::cout<<"recv"<<std::endl;
            }
            if(exist) {
                if(recv(this->sockfd,&done,sizeof(done),0) == -1) {
                    std::cout<<"recv"<<std::endl;
                }
                if(done) {
                    int isFound;
                    if(recv(this->sockfd,&isFound,sizeof(isFound),0) == -1) {
                        std::cout<<"recv"<<std::endl;
                    }
                    if(isFound==1) {
                        std::cout<<"The user "<<username<<" was sucessfully deleted."<<std::endl;
                    }
                    else {
                        std::cout<<"The user "<<finalUsername<<" isn't in your friend list!"<<std::endl;
                    }
                }
            }
            else {
                std::cout<<"The friend you tried to delete doesn't exist!"<<std::endl;
            }
            bool isDone=false;
            while(!isDone) {
                std::string choice;
                std::cout<<"Choose \"delete\" to delete another friend or \"q\" to quit"<<std::endl;
                std::cin >> choice;
                if(choice=="delete") {
                    done=0;
                    isDone=true;
                }
                else if(choice=="q") {

                    isDone=true;
                    done=1;
                }
                else {
                    std::cout<<"Please choose a valid option."<<std::endl;
                }
            }
            if(send(this->sockfd,&done,sizeof(done),0)==1) {
                std::cout<<"send"<<std::endl;
            }
        }

    }

}

void Friend::showFriend() {
    char friendUsername[DATASIZE];
    if(send(this->sockfd,this->username.c_str(),DATASIZE,0)==1) {
        std::cout<<"send"<<std::endl;
    }
    int done=0;
    std::cout<<"**********\nYour friend list:"<<std::endl;
    while(!done) {
        if(recv(this->sockfd,&done,sizeof(done),0) == -1) {
           std::cout<<"Function \"showFriend\": \"done\" recv error"<<std::endl;
        }
        if(done==0) {
            if(recv(this->sockfd,friendUsername,DATASIZE,0) == -1) {
                std::cout<<"Function \"showFriend\": \"friendUsername\" recv error"<<std::endl;
            }
            std::cout<<friendUsername<<std::endl;
        }
    }
    std::cout<<"**********"<<std::endl;

}

bool Friend::isValid(int value,int minValue,int maxValue) {
   bool valid = false;
    if(value >= minValue && value <= maxValue){
        valid = true;
    }
    return valid;
}

void Friend::acceptAddFriendAsk() {
    if(send(this->sockfd,this->username.c_str(),DATASIZE,0)==1) {
        std::cout<<"send"<<std::endl;
    }
    int done=0,hasRequest=0;
    std::string choice;
    char friendUsername[DATASIZE];
    bool correct=false;
    while(!done) {
        if(recv(this->sockfd,&done,sizeof(done),0) == -1) {
           std::cout<<"Function \"acceptAddFriendAsk\": done recv error"<<std::endl;
        }
        if(done==0) {
            if(recv(this->sockfd,friendUsername,DATASIZE,0) == -1) {
                std::cout<<"Function \"acceptAddFriendAsk\": \"friendUsername\" recv error"<<std::endl;
            }
            while(!correct) {
                    std::cout<<"*******\nYou received a friend request from:";
                std::cout<<friendUsername<<std::endl;
                std::cout<<"press \"A\" to add him or \"D\" to erase the request:";
                std::cin >> choice;
                if(choice=="A" or choice=="D") {
                    correct=true;

                }
                else {
                    std::cout<<"Please choose the right option"<<std::endl;
                }
            }
            if(send(this->sockfd,choice.c_str(),DATASIZE,0)==1) {
                std::cout<<"send"<<std::endl;
            }
            std::cout<<"*******"<<std::endl;
            correct=false;
        }
    }
    if(recv(this->sockfd,&hasRequest,sizeof(hasRequest),0) == -1) {
            std::cout<<"Function \"acceptAddFriendAsk\": \"hasRequest\" recv error"<<std::endl;
        }
    if(hasRequest==0) {
        std::cout<<"You didn't receive new friend requests."<<std::endl;
    }
}
