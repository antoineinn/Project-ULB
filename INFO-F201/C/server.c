//ANTOINE INNOCENT
//Matricule: 000394700

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>


#define MAX_CLIENTS 3
#define PORT 5555
#define MAXBUFFER 1000
#define LETTERS 4



char buffer[MAXBUFFER];

pthread_cond_t count_threshold_cv;

typedef struct
{
   int counter;
   pthread_t thread_player;

 
   pthread_mutex_t mutex_player;
}
player_t;


static player_t player =
{  
    .counter=0,
   .mutex_player= PTHREAD_MUTEX_INITIALIZER,
};






//the thread function
void *new_connection_handler(void *);


int server_init(){
    // SERVER INITIALISATION, RETURN SOCKET
    
    int socket_desc ;
    int booltrue;
    booltrue=1;
    struct sockaddr_in server; 

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }

    if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, &booltrue, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( PORT );
    bzero (&server.sin_zero, 8);

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }

    //Listen
    listen(socket_desc , MAX_CLIENTS);

    //Accept and incoming connection
    printf("Waiting for incoming connections\n");
    return socket_desc;}





int main(int argc , char *argv[])
{

    int total_connections,client_sock,socket_desc;
    struct sockaddr_in client;
    socklen_t c = sizeof(client);
    total_connections=0;
    socket_desc=server_init();  // INIT SERVER

    while(1)
    {
        client_sock = accept(socket_desc, (struct sockaddr *)&client, &c);
        total_connections++;
        // Checks to see if the amount players is max
        if (total_connections>MAX_CLIENTS){
            if(send(client_sock,"Terminate",9,0)<0){
                perror("send fail");
            }
            close(client_sock);}
        else {

        if (pthread_create( &player.thread_player , NULL ,  new_connection_handler ,(void*) (intptr_t)client_sock)<0){// &args ) < 0)
        
                perror("could not create thread");
                return 1;
            }

        printf("Handler assigned\n");}}
    

    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    close(client_sock);
    close(socket_desc);

    return 0;
}


void *new_connection_handler(void *socket_desc)
{
    //Thread Function, returns nothing
  

    pthread_mutex_lock (& player.mutex_player);

    int read_size = 0;
    int sock = (intptr_t)socket_desc;
    char client_message[2000];

    // Send "ready" to client 
    char rdy[] = "READY\n";
    write(sock, rdy, sizeof(rdy)-1);


    //Receive a message from client

    read_size = recv(sock , &buffer[player.counter] , sizeof(client_message) , 0);
    

    // Send "Suggestion Registered" to client
    char tmp[] = "Suggestion Registered\r\n";
    write(sock, tmp, sizeof(tmp)-1);
   


    if(read_size == 0)
    {
        printf("Client disconnected\n");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
    else{

        player.counter+=LETTERS;
        buffer[player.counter]=' '; // Add spaces
        player.counter++;
       
    
    }
    //Calculate du number of character in final string
    while (player.counter!=((LETTERS+1)*MAX_CLIENTS)){
        pthread_cond_wait(&count_threshold_cv,& player.mutex_player);

    }
        //Sleep 1second
        sleep(1);
        
        //Send the final result
        send(sock, buffer, sizeof(buffer)-1,0);
        pthread_cond_signal(&count_threshold_cv);
        pthread_mutex_unlock (& player.mutex_player);


   
    pthread_exit(NULL);

    
    return 0;
}

