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
#include "matchwrapper.hpp"
#include "coord.hpp"
#define MYPORT 3490    // the port users will be connecting to
#define BACKLOG 10     // how many pending connections queue will hold
#define DATASIZE 1024

static int ID = 0;

struct DataSpectate{
	int socket;
	int playerToJoin;
};

static DataSpectate spectateQueue[BACKLOG];

struct Array{
	int* array;
	size_t size;
	size_t used;
};

struct Data{
    Matchmaking* match;
    int socket;
};

struct gameData{
	char** players;
	int id;
    int* sockets;
	int nbPlayer;
};

struct DataServer{
	gameData* array;
	size_t size;
	size_t used;
};

static DataServer myData;

int get_size_int(int* array){
	int i = 0;
	while(array[i] != NULL)
		i++;
	return i;
}

void initArray_int(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray_int(Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

int get_size_data(DataServer array){
	int i = 0;
	while(array.array->sockets[i] != NULL)
		i++;
	return i;
}

void initArray_data(DataServer *a, size_t initialSize) {
  a->array = (gameData *)malloc(initialSize * sizeof(gameData));
  a->used = 0;
  a->size = initialSize;
}

void insertArray_data(DataServer *a, gameData element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (gameData *)realloc(a->array, a->size * sizeof(gameData));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}


unsigned char * serialize_int(unsigned char *buffer, int value)
{
    buffer[0] = value >> 24;
    buffer[1] = value >> 16;
    buffer[2] = value >> 8;
    buffer[3] = value;
    return buffer + 4;
}

unsigned char * serialize_coord(unsigned char *buffer, struct Coord *value)
{
    buffer = serialize_int(buffer, value->_x);
    buffer = serialize_int(buffer, value->_y);
    return buffer;
}

int deserialize_int(unsigned char *buffer)
{
    int value = 0;
    value |= buffer[0] << 24;
    value |= buffer[1] << 16;
    value |= buffer[2] << 8;
    value |= buffer[3];
    return value;
}

void read_Coord(int sockfd, char *buffer){
    recv(sockfd, buffer, DATASIZE - 1, 0);
}

void send_Coord(int sockfd, struct Coord *temp)
{
    unsigned char buffer[32], *ptr;
    ptr = serialize_coord(buffer, temp);
    if(send(sockfd, buffer, ptr-buffer, 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

int checkQueue(int* sockets){
	for (int i = 0; i < BACKLOG; ++i)
		for (int j = 0; j < get_size_int(sockets); ++j)
			if (spectateQueue[i].playerToJoin == sockets[j])
				return spectateQueue[i].socket;
	return 0;
}

int addToQueue(int new_fd, int socket){
	struct DataSpectate data;
	data.socket = new_fd;
	data.playerToJoin = socket;
	for (int i = 0; i < BACKLOG; ++i){
		if (spectateQueue[i].socket == NULL){
			spectateQueue[i] = data;
			return 1;
		}
	}
	return 0;
}

int get_socket(char* player){
	for (int i = 0; i < get_size_data(myData); ++i){
		for (int j = 0; j < get_size_int(myData.array[i].sockets); ++j){
			if ( myData.array[i].players[j] == player ) 
				return myData.array[i].sockets[j];
		}
	}
	return 0;
}

void support(int* new_fd){
	char playerToJoin[DATASIZE];
	int sockToJoin;
	//friendView(*new_fd);
	recv(*new_fd, playerToJoin, DATASIZE, 0);
	sockToJoin = get_socket(playerToJoin);
	addToQueue(*new_fd, sockToJoin);
}


void* gameMaker(void* param){
	Array sockets;
	initArray_int(&sockets, 1);
    char buffer[DATASIZE];
    fd_set rdfs;
    int max;
    struct gameData* data = (struct gameData*) param;
	for (int i = 0; i < get_size_int(data->sockets); ++i)
		insertArray_int(&sockets, data->sockets[i]);
    while(1){
        FD_ZERO(&rdfs);
        FD_SET(STDIN_FILENO, &rdfs);
		int spectatefd = checkQueue(data->sockets);
		if (spectatefd != 0)
			insertArray_int(&sockets, spectatefd);
    
        for(int i = 0; i < get_size_int(sockets.array); i++)
        {
            FD_SET(sockets.array[i], &rdfs);
            if (max < sockets.array[i]) max = sockets.array[i];
        }

        //FD_SET : ajout des sockets gérés par le select()

        if(select(max + 1, &rdfs, NULL, NULL, NULL) == -1) //On attent qu'un des sockets est pret en I/O
        {
            perror("select()");
            exit(errno);
        }

        int i = 0;
        for(i = 0; i < get_size_int(sockets.array); i++){
            if(FD_ISSET(sockets.array[i], &rdfs)){ //Lorsqu'un socket est modifié, on regarde lequel
                int x, y;
                int client = sockets.array[i];
				int sender;
                recv(sockets.array[i],&x, 10, 0); //Et on récupere son buffer
                recv(sockets.array[i],&y, 10, 0);
				recv(sockets.array[i], &sender, 10, 0);
                for(int j = 0; j < get_size_int(sockets.array); j++)
                {
                    if (j != i)
                    {
                        send(sockets.array[j], &x, 10, 0);
                        send(sockets.array[j], &y, 10, 0);
						send(sockets.array[j], &sender, 10, 0);
                    }
                }
            }
        }
    }
}

void startParty(int *new_fd, Matchmaking* match)
{
	char id[DATASIZE];
    int gameMode;
    if (recv(*new_fd,&gameMode,sizeof(gameMode),0) == -1)
        {
            perror("recv");
            exit(1);
        }
    int* socketList = Matchmaking_newPlayer(match, *new_fd, gameMode);
    if (socketList)
    {
        pthread_t game;
        struct gameData gameInfo;
        gameInfo.sockets = socketList;
		gameInfo.id = ID;
		ID++;
		switch(gameMode){
			case 1:
				gameInfo.nbPlayer = 4;
				break;
			case 2:
				gameInfo.nbPlayer = 1;
				break;
			case 3:
				gameInfo.nbPlayer = 4;
				break;
		}
		gameInfo.players = new char*[DATASIZE];
        for (int i = 0; i < gameInfo.nbPlayer; ++i){
            send(gameInfo.sockets[i], &gameMode, 1, 0);
			send(gameInfo.sockets[i], &i, 1, 0);
			recv(gameInfo.sockets[i], id, DATASIZE, 0);
			gameInfo.players[i] = id;
			printf("%s \n", id);
        }
		insertArray_data(&myData, gameInfo);
        int ret=pthread_create(&game,NULL,gameMaker,(void*)&gameInfo); 
    } 
	pthread_exit(0);
}


int connectUser(int param){
    int done=0;
    int positionInFile,c;
    FILE *fp;
    int new_fd=param;
    int pass;
    char id[DATASIZE];
    char tempId[DATASIZE];// Will contain the pseudos read in the file.
    int tempPass=0,isConnected=0;// Will contain password and the boolean value in the file.
    fp = fopen("accounts.txt", "r+");
    if (fp == NULL) {
        printf("I couldn't open accounts.txt for reading.\n");
        exit(0);
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
        if ((recv(new_fd,id,DATASIZE,0)) == -1)
        {
            perror("recv");
            exit(1);
        }
        printf("User id:%s\n",id);
        if ((recv(new_fd,&pass,sizeof(pass),0)) == -1)//rece
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
        if(send(new_fd,&done,sizeof(done),0)==-1)// *new_fd isn't recognized as a socket from here. Don't know the reason.
        {
            perror("ERROR");
            exit(1);
        } 
        
    }
    fclose(fp);
    return 1;
}

int registerAccount(int fd){
    int done=0;
    int positionInFile,c;
    FILE *fp;
    int new_fd=fd; 
    int pass;
    char id[DATASIZE];
    char tempId[DATASIZE];// Will contain the pseudos read in the file.
    int tempPass=0,isConnected=0;// Will contain password and the boolean value in the file.
    fp = fopen("accounts.txt", "r+");
    if (fp == NULL) {
        printf("I couldn't open accounts.txt for reading.\n");
        exit(0);
    }
    while(done==0)
    {
        fseek(fp,0,SEEK_SET);// same reason as "co".
        if(recv(new_fd,id,DATASIZE,0)== -1)
        {
            perror("recv");
            exit(1);
        }
        printf("User new id:%s\n",id);
        if (recv(new_fd,&pass,sizeof(pass),0) == -1)//rece
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
        if(send(new_fd,&done,sizeof(done),0)==-1)
        {
            perror("Error\n");
            exit(1);
        }
    }
    fclose(fp);
    return 1;
}

void addFriend(int fd)
{
    FILE *fptr,*fptr2,*fptrAccount; 
    int isFinished=0;
    while(!isFinished)
    {
        fptrAccount=fopen("accounts.txt","r");   
        char myUsername[DATASIZE],friendToAdd[DATASIZE],tempBuff[DATASIZE];
        char id[DATASIZE];
        int done=1, exist=0;
        if(recv(fd,friendToAdd,DATASIZE,0) == -1)
        {
            perror("recv");
            exit(1);
        }
        if(strcmp(friendToAdd,"q")==0)
        {
            printf("The user choose to quit\n");
            isFinished=1;
        }
        else
        {
            printf("The friend to add:%s\n",friendToAdd);
            if(recv(fd,myUsername,DATASIZE,0) == -1)
            {
                perror("recv");
                exit(1);
            }
            printf("%s\n",myUsername);
            while(fscanf(fptrAccount,"%s\n",tempBuff)==1)
            {
                if(strcmp(tempBuff,friendToAdd)==0)
                {
                    exist=1;
                }
            }
            fclose(fptrAccount);
            if(send(fd,&exist,sizeof(exist),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }   
            if(exist)
            {
                fptr = fopen(friendToAdd, "r");
                if(fptr == NULL) //if file does not exist, create it
                {
                  printf("creating the file:%s\n",friendToAdd);
                  fptr = fopen(friendToAdd, "w+");
                }
                while(fscanf(fptr,"%s\n",tempBuff)==1)
                    {
                        if(strcmp(tempBuff,myUsername)==0)
                        {
                            done=0;
                            break;
                        }
                    }
                    if(done)
                    {
                        fptr = fopen(friendToAdd, "a");
                        printf("%s\n",myUsername);
                        fprintf(fptr,"%s %s\n",myUsername,"0");
                    }
                if(send(fd,&done,sizeof(done),0)==-1)
                    {
                        perror("Error\n");
                        exit(1);
                    }
                fclose(fptr);
                //fclose(fptr2);
            }
            
            if(recv(fd,&isFinished,sizeof(isFinished),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
        }
    } 
}

void deleteFriend(int fd)
{
    FILE *fptr,*fptr2, *fptr3, *fptr4, *fptrAccount;;
    int isFinished=0,isFriend,done=0;
    while(!isFinished)
    {
        fptrAccount=fopen("accounts.txt", "r");   
        char myUsername[DATASIZE],friendToDelete[DATASIZE], tempBuff[DATASIZE];
        char id[DATASIZE];
        int isFound = 0, exist=0;
        if(recv(fd,friendToDelete,DATASIZE,0) == -1)
            {
                perror("recv");
                exit(1);
            }
        if(strcmp(friendToDelete,"q")==0)
        {
            printf("The user choose to quit\n.");
            isFinished=1;
            fclose(fptrAccount);
        }
        else
        {
            printf("%s\n",friendToDelete);
            if(recv(fd,myUsername,DATASIZE,0) == -1)
                {
                    perror("recv");
                    exit(1);
                }
            printf("%s\n",myUsername);
            while(fscanf(fptrAccount,"%s\n",tempBuff)==1)
                {
                    if(strcmp(tempBuff,friendToDelete)==0)
                    {
                        exist=1;
                    }
                }
            fclose(fptrAccount);
            if(send(fd,&exist,sizeof(exist),0)==-1)
                {
                    perror("Error\n");
                    exit(1);
                }
            if(exist){
                fptr = fopen(myUsername, "r");
                if(fptr == NULL) //if file does not exist, create it
                {
                    printf("creating the file:%s\n",myUsername);
                    fptr = fopen(myUsername, "w+");
                }
                fptr2=fopen("temp1","w+");//create file temp.
                while(fscanf(fptr, "%s %d", id,&isFriend)==2)
                {

                    if((strcmp(id,friendToDelete)==0) && isFriend==1)
                    {
                        isFound=1;
                        int friendTag;
                        char tempId[DATASIZE];
                        fptr3 = fopen(friendToDelete,"r");
                        if(fptr3 == NULL) //if file does not exist, create it
                        { 
                            printf("creating the file:%s\n",friendToDelete);
                            fptr3 = fopen(friendToDelete, "w+");
                        }
                        fptr4=fopen("temp2","w+");//create file temp.
                        while(fscanf(fptr3,"%s %d", tempId,&friendTag)==2)
                        {
                            if((strcmp(tempId,myUsername) != 0))
                            {
                                fprintf(fptr4,"%s %d\n",tempId,friendTag);
                            }
                        }
                        fclose(fptr3);
                        fclose(fptr4);
                    }
                    else
                    {   
                        
                        fprintf(fptr2,"%s %d\n",id,isFriend);
                    }
                }
                done=1;
                remove(myUsername);
                rename("temp1",myUsername);
                rename("temp2",friendToDelete);
                fclose(fptr);
                fclose(fptr2);
                
                if(send(fd,&done,sizeof(done),0)==-1)
                {
                    perror("Error\n");
                    exit(1);
                }
                if(send(fd,&isFound,sizeof(isFound),0)==-1)
                {
                    perror("Error\n");
                    exit(1);
                }
            }
            if(recv(fd,&isFinished,sizeof(isFinished),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
        }
    }   
}

void accepteFriend(int fd)
{
    FILE *fptr,*fptr2,*fptr3;
    char myUsername[DATASIZE],clientChoice[DATASIZE];
    char id[DATASIZE];
    if(recv(fd,myUsername,DATASIZE,0) == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s\n",myUsername);
    fptr= fopen(myUsername,"r");
    if (fptr == NULL) {
        perror("Failed: ");
    }
    fptr2=fopen("temp","w");
    int isFriend,done=0,hasRequest=0;
    char choiceA[1024];
    while(fscanf(fptr, "%s %d", id,&isFriend)==2)
    {

        if(isFriend==0)
        {
            hasRequest=1;
            if(send(fd,&done,sizeof(done),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
            if(send(fd,id,DATASIZE,0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
            if(recv(fd,clientChoice,sizeof(clientChoice),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
            strcpy(choiceA,"A");
            if(strcmp(clientChoice,choiceA)==0)
            {
                fprintf(fptr2,"%s %d\n",id,1);
                fptr3=fopen(id,"a");
                fprintf(fptr3,"%s %d\n",myUsername,1);
                fclose(fptr3);
            }
        }
        else
        {
            fprintf(fptr2,"%s %d\n",id,isFriend);
        }
    }
    remove(myUsername);
    rename("temp",myUsername);
    done=1;
    if(send(fd,&done,sizeof(done),0)==-1)
    {
        perror("Error\n");
        exit(1);
    }
    if(send(fd,&hasRequest,sizeof(hasRequest),0)==-1)
    {
        perror("Error\n");
        exit(1);
    }
    fclose(fptr);
    fclose(fptr2);
}

void showFriend(int fd)
{  
    FILE *fptr;
    char myUsername[DATASIZE];
    char id[DATASIZE];
    if(recv(fd,myUsername,DATASIZE,0) == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s\n",myUsername);
    fptr= fopen(myUsername,"r+");
    if (fptr == NULL) {
        printf("I couldn't open %s for reading.\n",myUsername);
        printf("creating the file for further operation\n");
        fptr= fopen(myUsername,"w");
    
    }
    fptr= fopen(myUsername,"r+");
    int isFriend,done=0;
    while(fscanf(fptr, "%s %d", id,&isFriend)==2)
    {
        
        if(isFriend==1)
        {
            if(send(fd,&done,sizeof(done),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
            if(send(fd,id,sizeof(id),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
        }
    }

    done=1;
    if(send(fd,&done,sizeof(done),0)==-1)
    {
        perror("Error\n");
        exit(1);
    }
    fclose(fptr);
}

void friendView(int *fd)
{
    int choice=0;
    while(choice!=5)
    {
         if(recv(*fd,&choice,sizeof(choice),0) == -1)
        {
            perror("recv");
            exit(1);
        }
        switch(choice)
        {
            case 1:
                addFriend(*fd);
                break;
            case 2:
                deleteFriend(*fd);
                break;
            case 3:
                accepteFriend(*fd);
                break;
            case 4:
                showFriend(*fd);
                break;
            case 5:
                break;
        }
    }
}

void profilView(int *fd){
    FILE *fp;
    char myUsername[DATASIZE];
    char id[DATASIZE];
    int isFriend,done=0;
    if ((recv(*fd,myUsername,DATASIZE,0)) == -1)
    {
        perror("recv");
        exit(1);
    }
    fp= fopen(myUsername,"r");
    if (fp == NULL) {
        printf("I couldn't open %s for reading.\n",myUsername);
        printf("creating the file for further operation\n");
        fp= fopen(myUsername,"w");
    
    }
    fp= fopen(myUsername,"r");
    int isFound=0;
    while(fscanf(fp, "%s %d", id,&isFriend)==2)
    {  
        if(isFriend == 1){
            isFound=1;
            if(send(*fd,&done,sizeof(done),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
            if(send(*fd,&isFound,sizeof(isFound),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
            if(send(*fd,id,DATASIZE,0)==-1)
            {
                perror("Error\n");
                exit(1);
            }
        }
    }
        done=1;
        isFound=0;
        if(send(*fd,&done,sizeof(done),0)==-1)
        {
            perror("Error\n");
    
        }
        if(send(*fd,&isFound,sizeof(isFound),0)==-1)
        {
            perror("Error\n");

        }
        fclose(fp);
}

void disconnectUser(int* fd) {
    char username[DATASIZE];
    if (recv(*fd, username, DATASIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }
    FILE *fp;
    fp = fopen("accounts.txt", "r+"); // Open accounts.txt
    if (fp == NULL) {
        printf("I couldn't open accounts.txt for reading.\n");
        exit(0);
    }
    //fseek(fp,0,SEEK_SET);
    char tempId[DATASIZE]; // Will contain the pseudos read in the file.
    int positionInFile;
    int tempPass=0,isConnected=0;
    //int done=1;
    while (!feof(fp)) // while it's not end of file.
         {
            fscanf(fp, "%s %d %d", tempId, &tempPass, &isConnected); // we get the id of the line.;
            if(strcmp(tempId,username)==0) //compare the id with the value given by the user.
            {
                //done=1;
                positionInFile=ftell(fp);
                /*
                    We change the boolean value
                */
                fseek(fp,positionInFile-1,SEEK_SET);
                fputs("0",fp);
                fseek(fp,positionInFile+1,SEEK_SET);
                break;
            }
         }
    fclose(fp); // close accounts.txt
}

void* threadFunction(void* param)
{

    /*int choice;
    struct Data* data = (struct Data*) param;
    int gameMode, connected, new_fd=data->socket;*/

    int choice, done=0;
    struct Data* data = (struct Data*) param;
    int connected=0, new_fd=data->socket;
    while (done==0) {
        if (connected == 0) {
            if (recv(new_fd,&choice,sizeof(choice),0) == -1) {
                perror("recv");
                exit(1);
            }
            switch(choice) {
                case 1:
                    connected = connectUser(new_fd);
                    break;
                case 2:
                    int createAccount;
                    createAccount = registerAccount(new_fd);
                    if (createAccount == 1) {
                        connected = connectUser(new_fd);
                    }
                    break;
            }
        }
        else if (connected == 1) {
            if (recv(new_fd,&choice,sizeof(choice),0) == -1) {
                perror("recv");
                exit(1);
            }
            switch(choice) {
                case 1:
					send(new_fd, "startGame", DATASIZE, 0);
                    startParty(&new_fd, data->match);
                    break;
                case 2:
					support(&new_fd);
                    break;
                case 3:
                    profilView(&new_fd);
                    break;
                case 4:
                    break;
                case 5:
                    friendView(&new_fd);
                    break;
                case 6:
					send(new_fd, "exit", DATASIZE, 0);
                    disconnectUser(&new_fd);
                    connected=0;
                    break;
            }
        }

    }
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
	initArray_data(&myData, 1);
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
