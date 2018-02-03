#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "MyWrapper.hpp"
#include "gamewrapper.hpp"

#define PORT 3490 // the port client will be connecting to 

#define MAXDATASIZE 100 // max number of bytes we can get at once 

int main(int argc, char *argv[])
{   
    int choice;
    int sockfd, numbytes;  
    char* id;
    int pass;
    int done=0;
    char buf[MAXDATASIZE];
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

	struct Menu* m=newMenu();
	Menu_setSocket(m,sockfd);//give the client socket to the Menu class to send data to the server.
	Menu_MenuInit(m);//Will call the init function of the menu and launch the menu.
	int player = 0;
	int gameMode = 0;
	char action[1024];
	id = Menu_getUsername(m);
	recv(sockfd, action, 1024, 0);
	if (strcmp(action, "startGame") == 0){
		recv(sockfd, &gameMode, 1, 0);
		recv(sockfd, &player, 1, 0);
		send(sockfd, id, 1024, 0);
		if (gameMode != -1){
			struct Game* game = newGame(sockfd, player, gameMode);
			gameStart(game);
			endGame(game);
			//TODO : return to menu
		}
	}
	else if (strcmp(action, "exit") == 0){

	}
    close(sockfd);

    return 0;
}
