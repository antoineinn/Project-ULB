#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <QApplication>
#include <QTextStream>
#include <string>
#include <iostream>
#include "menu.hpp"
#include "menu_gui.hpp"
#include "gamedisplaygui.h"
#include "game.hpp"


#define PORT 3490 // the port client will be connecting to

#define MAXDATASIZE 1024 // max number of bytes we can get at once

int main(int argc, char *argv[]) {   
    int sockfd;  
    char* id;

    struct hostent *he;
    struct sockaddr_in their_addr; // connector's address information 

    if (argc != 2) {
        fprintf(stderr,"usage: client hostname\n");
        exit(1);
    }

    if ((he=gethostbyname(argv[1])) == NULL) {  // get the host info 
        perror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;    // host byte order 
    their_addr.sin_port = htons(PORT);  // short, network byte order 
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);  // zero the rest of the struct 

    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    int valid = 0;

    std::cout<<"Welcome to our game\nDo you want to play in the bash or in the GUI? Press B for bash or G for GUI" << std::endl;
    std::string value;
    std::cin >> value;

    do {
        if (value=="B" || value=="G") {
            valid = 1;
        }
        else {
            std::cout<<"Wrong choice. Please make another choice."<< std::endl;
            std::cin >> value;
        }
    } while (!valid);

	char action[MAXDATASIZE];

    if (value=="G") {
        std::cout <<"Launch GUI"<< std::endl;
        QApplication a(argc, argv);
        MenuGui m;
        m.menuInit(sockfd);
   //      read(sockfd, action, MAXDATASIZE);
   //      if (strcmp(action, "startGame")==0){
   //      	recv(sockfd, &gameMode, 1, 0);
   //      	recv(sockfd, &player, 1, 0);
			// GameDisplayGui game_display;
			// send(sockfd, id, MAXDATASIZE, 0);
			// if (gameMode != -1){
			// 	game_display.setWindow(gameMode);
   //      		game_display.show();
			// }
   //      }
        return a.exec();
    }
    else {
        Menu m = Menu(sockfd); // Give the Menu object the socket to send data to the server
        m.menuInit(); // Initializing and launching the menu

        while (1) {
            int player=0, gameMode=0;
    		id = m.get_username();

    		recv(sockfd, action, MAXDATASIZE, 0);
    		if (strcmp(action, "startGame") == 0){

    			recv(sockfd, &gameMode, 1, 0);
    			recv(sockfd, &player, 1, 0);
    			send(sockfd, id, MAXDATASIZE, 0);
    			if (gameMode != -1){
    				Game game = Game(sockfd, player, gameMode, 0);
    				game.start();
    			}
                m.menuEndGame();
    		}
    		else if (strcmp(action, "exit") == 0) {
                break;
    		}
    		else if (strcmp(action, "Support") == 0) {
				std::cout<<"You are now supporting."<< std::endl;
			}
/*
    			int go = 0;
    			recv(sockfd, &go, 1, 0);
    			recv(sockfd, &player, 1, 0);
    			recv(sockfd, &gameMode, 1, 0);
    			if (go) {
    				Game game = Game(sockfd, player, gameMode, 1);
    				game.start();
    			}
                m.menuEndGame();
    		}

*/
        }
    }
    if (value =="G") {
        char action[MAXDATASIZE];
        recv(sockfd, action, MAXDATASIZE, 0);
        if (strcmp(action, "exit") == 0) {
            close(sockfd);
            return 0;
        }
    }
    close(sockfd);

    return 0;
}
