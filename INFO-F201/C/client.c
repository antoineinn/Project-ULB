//ANTOINE INNOCENT
//Matricule: 000394700

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdint.h>

#define MESSAGESIZE 10
#define PORT 5555

int initclient(char* argv){
    /// Initialise connection to server, return socket
    struct sockaddr_in server;
    unsigned long inaddr;
    int sock;

    //Create socket
    inaddr = inet_addr(argv);

    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_family = AF_INET;
    server.sin_port = htons( PORT );
    memcpy(&server.sin_addr, &inaddr, sizeof(inaddr));


    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    puts("Welcome please wait, when notified enter a 4 letter word \n");

   return sock; 
}


int main(int argc , char *argv[])
{
    
    char message[1000] , server_reply[2000]; //initialise buffers arbitrarly 
    int flag,sock,len;
    sock=initclient(argv[1]);
    flag=0;

    //keep communicating with server
    while((len = recv(sock, server_reply, sizeof(server_reply), 0)) > 0)
    {   
        //If received "Terminate" from server
        if (strcmp(server_reply,"Terminate")==0){
            puts("Oups, already too much player.\n");
            printf("Server reply: %.*s\n", len, server_reply);

            break;
        }
        //If received "Finished" from server
        else if (strcmp(server_reply,"Finished\n")==0){
            printf("Server reply: %.*s\n", len, server_reply);
            break;
        }
        //If received "Suggestion Registered" from server
        else if(strcmp(server_reply,"Suggestion Registered\n")==0){
            printf("Server reply: %.*s\n", len, server_reply);
            continue;
        }

  
        //If received "Ready" from server
        else if (strcmp(server_reply,"READY\n")==0){
            
            printf("Server reply: %.*s\n", len, server_reply);
            printf("Enter message : ");
            //Wait for user input 
            if (fgets(message, sizeof(message), stdin) == NULL)
                break;

            //Send some data
            if( send(sock , message , strlen(message) , 0) < 0)
            {
                perror("Send failed");
                return 1;
            }
            continue;}

        else{
            //Receive the first input
            if (flag==0){
                flag+=1;
            }
            else{
            //Receive the final message
            printf("This is the final mix of all sugestions:  %.*s\n", len, server_reply);
            puts("\nThank you for playing");
            break;}
      
            }
    }

    close(sock);

    return 0;
}