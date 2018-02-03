#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <pthread.h>
//#include "Matchmaking.hpp"
#include "matchwrapper.hpp"

#define MYPORT 3490    // the port users will be connecting to
#define BACKLOG 10     // how many pending connections queue will hold

struct Data{
	Matchmaking* match;
	int socket;
};

void* threadFunction(void* param)
{
	struct Data* data = (struct Data*) param;
    int done=0;
	int gameMode;
    int positionInFile,c;
    FILE *fp;
    int numbytes;
    int new_fd=data->socket;
    char buffer[100]; 
    int pass;
    char id[100];
    char * tempId = (char*)malloc(sizeof(char));// Will contain the pseudos read in the file.
    int tempPass=0,isConnected=0;// Will contain password and the boolean value in the file.
    int choice;
    fp = fopen("accounts.txt", "r+");
      if (fp == NULL) {
         printf("I couldn't open accounts.txt for reading.\n");
         exit(0);
      }
    if ((numbytes=recv(new_fd,&choice,10,0)) == -1)
        {
            perror("recv");
            exit(1);
        }

        if(choice==1)//If the user choose to connect himself.
        {
            done=0;
            while(done!=1)
            {
                /*
                    Fseek will in this case put the pointer fp at the beginning of the file.
                    It's important because if the user enter a wrong id/pass or choose an account
                    already logged, the pointer fp will be at end of the files from the previous reading.
                */
                fseek(fp,0,SEEK_SET);
                if ((numbytes=recv(new_fd,id,50,0)) == -1)
                {
                    perror("recv");
                    exit(1);
                }
                printf("User id:%s\n",id);
                if ((numbytes=recv(new_fd,&pass,sizeof(pass),0)) == -1)//rece
                {
                    perror("recv");
                    exit(1);
                }
                printf("User password:%d\n",pass);
                while (!feof (fp))// while it's not end of file.
                 {
                    fscanf (fp, "%s %d %d", tempId,&tempPass,&isConnected);// we get the id,pass and the boolean of the line.
                    if(strcmp(tempId,id)==0 && tempPass==pass)//compare the id and the pass with the values given by the user.
                    {
                        if(isConnected!=1)//check if somoene isn't already connected with the account that we are trying to use.
                        {
                            done=1;
                            positionInFile=ftell(fp);
                            /*
                                We change the boolean value to know which account are connected.
                            */
                            fseek(fp,positionInFile-1,SEEK_SET);
                            fputs("1",fp);
                            fseek(fp,positionInFile+1,SEEK_SET);
                            break;
                        }
                        else
                        {
                            done=2;
                            break;
                        }
                    }

                 }
                if(done==0)
                {
                
                    printf("Paswword or id is incorrect.\n");
                    fseek(fp,0,SEEK_SET);
                }
                else if(done==2)
                {
                    printf("Account already logged.\n");
                }
                if(send(new_fd,&done,1,0)==-1)// *new_fd isn't recognized as a socket from here. Don't know the reason.
                {
                    perror("ERROR");
                    exit(1);
                } 
                
            }                                                                     
        }
        else if(choice==2)
        {  
            done=0;
            while(done==0)
            {
                fseek(fp,0,SEEK_SET);// same reason as "co".
                if((numbytes=recv(new_fd,id,50,0)) == -1)
                {
                    perror("recv");
                    exit(1);
                }
                printf("User new id:%s\n",id);
                if ((numbytes=recv(new_fd,&pass,sizeof(pass),0)) == -1)//rece
                {
                    perror("recv");
                    exit(1);
                }
                printf("User new password:%d\n",pass);
                done=1;
                while(fscanf(fp,"%s\n",tempId)==1)
                {
                    if(strcmp(tempId,id)==0)//compare the file id with the id given by the user.
                    {
                        printf("Id already exist!\n");
                        done=0;
                        break;
                    }
                    if(feof(fp))
                    {
                      break;
                    }
                }
                if(done)
                {
                    printf("Account created\n");
                    fprintf(fp,"\n%s %d %d",id,pass,0);
                }
                if(send(new_fd,&done,1,0)==-1)
                {
                    perror("Error\n");
                    exit(1);
                } 
            }
            done=0;
            while(done!=1)
            {
                /*
                    Fseek will in this case put the pointer fp at the beginning of the file.
                    It's important because if the user enter a wrong id/pass or choose an account
                    already logged, the pointer fp will be at end of the files from the previous reading.
                */
                fseek(fp,0,SEEK_SET);
                if ((numbytes=recv(new_fd,id,50,0)) == -1)
                {
                    perror("recv");
                    exit(1);
                }
                printf("User id:%s\n",id);
                if ((numbytes=recv(new_fd,&pass,sizeof(pass),0)) == -1)
                {
                    perror("recv");
                    exit(1);
                }
                printf("User password:%d\n",pass);
                while (!feof (fp))// while it's not end of file.
                 {
                    fscanf (fp, "%s %d %d", tempId,&tempPass,&isConnected);// we get the id,pass and the boolean of the line.
                    if(strcmp(tempId,id)==0 && tempPass==pass)//compare the id and the pass with the values given by the user.
                    {
                        if(isConnected!=1)//check if somoene isn't already connected with the account that we are trying to use.
                        {
                            done=1;
                            positionInFile=ftell(fp);
                            /*
                                We change the boolean value to know which account are connected.
                            */
                            fseek(fp,positionInFile-1,SEEK_SET);
                            fputs("1",fp);
                            fseek(fp,positionInFile+1,SEEK_SET);
                            break;
                        }
                        else
                        {
                            done=2;
                            break;
                        }
                    }

                 }
                if(done==0)
                {
                
                    printf("Paswword or id is incorrect.\n");
                    fseek(fp,0,SEEK_SET);
                }
                else if(done==2)
                {
                    printf("Account already logged.\n");
                }
                if(send(new_fd,&done,1,0)==-1)// *new_fd isn't recognized as a socket from here. Don't know the reason.
                {
                    perror("ERROR");
                    exit(1);
                } 
                
			
            }

        }
        fclose(fp); 
		if (recv(new_fd,&gameMode,sizeof(gameMode),0) == -1)
        {
            perror("recv");
            exit(1);
        }
		Matchmaking_newPlayer(data->match, new_fd, gameMode);
        pthread_exit(0);

}

void beginListen(int *sockfd,struct Data* array_client,struct sockaddr_in my_addr,struct sockaddr_in their_addr)
{
    int yes = 1;

    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }
    
    my_addr.sin_family = AF_INET;         // host byte order
    my_addr.sin_port = htons(MYPORT);     // short, network byte order
    my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
    memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct

    if (bind(*sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(*sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
}

int acceptClient(int *sockfd,struct sockaddr_in my_addr,struct sockaddr_in their_addr,socklen_t sin_size,struct Data* array_client){
    int numbytes=0,new_fd,totalClient=0;
    pthread_t connectedClient;
    while(1) {  // main accept() loop
    
        if ((new_fd = accept(*sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1) {
            perror("accept");
            continue;
        }
        array_client[totalClient].socket=new_fd;
        printf("server: got connection from socket %d\n",new_fd);
        int ret=pthread_create(&connectedClient,NULL,threadFunction,(void*)&array_client[totalClient]);//Creation of multiple thread for each client.
        totalClient++;
        if(ret!=0)
        {
            printf("creation of thread failed.");
            return 0;
        }
    }

}
 
int main(void)
{
	struct Matchmaking* match = newMatchmaking();
    int sockfd;
	struct Data array_client[30];  // listen on sock_fd, new connection on new_fd
	for (int i =0; i < 30; ++i){
		array_client[i].match = match;
	}
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    socklen_t sin_size;
    sin_size = sizeof(struct sockaddr_in);
    beginListen(&sockfd,array_client,my_addr,their_addr);
    acceptClient(&sockfd,my_addr,their_addr,sin_size, array_client);

    return 0;
}
