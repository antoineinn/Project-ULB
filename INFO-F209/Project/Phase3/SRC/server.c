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
#include "ranking.hpp"
#define MYPORT 3490    // the port users will be connecting to
#define BACKLOG 10     // how many pending connections queue will hold
#define DATASIZE 1024

static int ID = 0;  
static const int max = 4;

pthread_rwlock_t rwlock;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//-----------SOCKET'S ARRAY STRUCTURE----------------

/*
* Struct wich is a dynamic array of sockets. Used by the gameMaker to know where to send
* the data
*/

struct Array{
	int* array;
	size_t size;
	size_t used;
};

int get_size_int(int* array){
	int i = 0;
	while(array[i] != 0)
		i++;
	return i;
}

void initArray_int(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray_int(Array *a, int element) {
/*
* a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
* Therefore a->used can go up to a->size 
*/
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray_int(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}


//-----------END OF SOCKET'S ARRAY STRUCTURE----------------

struct DataSpectate{ //Spectate struct
	int socket;
	int playerToJoin;
};

//----------COORD'S ARRAY STRUCTURE-----------

/* Struct used by the serveur to know where are each towers */ 

struct CoordArray{
	Coord* array;
	size_t size;
	size_t used;
};

int get_size_coord(CoordArray array){
	int i = 0;
	while(array.array[i]._x != 0 && array.array[i]._y != 0)
		i++;
	return i;
}

void initArray_coord(CoordArray *a, size_t initialSize) {
  a->array = (Coord *)malloc(initialSize * sizeof(Coord));
  a->used = 0;
  a->size = initialSize;
}

void insertArray_coord(CoordArray *a, Coord element) {
/*
* a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
* Therefore a->used can go up to a->size 
*/
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (Coord *)realloc(a->array, a->size * sizeof(Coord));
  }
  a->array[a->used++] = element;
}

void freeArray_coord(CoordArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}


//-----------END OF COORD'S ARRAY STRUCTURE------------

struct Data{ //Client struct
    Matchmaking* match;
    int socket;
    int isConnected = 0;
};

struct gameData{ //Struct used by gameMaker
	int id;
    int* sockets;
	int nbPlayer;
	char players[max][DATASIZE];
	int gameMode;
	CoordArray towers;
};

//-----------SERVER-DATA'S ARRAY STRUCTURE------------

struct DataServer{ //Struct being static for the server
	gameData* array;
	size_t size;
	size_t used;
};

int get_size_data(DataServer array){
	return array.size;
}

void initArray_data(DataServer *a, size_t initialSize) {
  a->array = (gameData *)malloc(initialSize * sizeof(gameData));
  a->used = 0;
  a->size = initialSize;
}

void insertArray_data(DataServer *a, gameData element) {
/*
* a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
* Therefore a->used can go up to a->size 
*/
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (gameData *)realloc(a->array, a->size * sizeof(gameData));
  }
  a->array[a->used++] = element;
}

void freeArray_data(DataServer *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}


//-----------END OF SERVER-DATA'S ARRAY STRUCTURE------------

struct DataToSend{
	int socket;
	CoordArray towers;
};

static DataServer myData;
static DataSpectate spectateQueue[BACKLOG];

int checkQueue(int* sockets){
	int result = 0;
	for (int i = 0; i < BACKLOG; ++i)
		for (int j = 0; j < get_size_int(sockets); ++j)
			if (spectateQueue[i].playerToJoin == sockets[j]){
				result = spectateQueue[i].playerToJoin;
				spectateQueue[i].socket = 0;
				spectateQueue[i].playerToJoin = 0;
			}
	return result;
}

int addToQueue(int new_fd, int socket){
	struct DataSpectate data;
	data.socket = new_fd;
	data.playerToJoin = socket;
	for (int i = 0; i < BACKLOG; ++i){
		if (spectateQueue[i].socket == 0){
			spectateQueue[i] = data;
			return 1;
		}
	}
	return 0;
}

int get_socket(char* player){ //get socket from the player's name
	for (int i = 0; i < get_size_data(myData); ++i){
		for (int j = 0; j < get_size_int(myData.array[i].sockets); ++j){
			if ( strcmp(player, myData.array[i].players[j]) == 0 ){
				return myData.array[i].sockets[j];
			}
		}
	}
	return 0;
}

void support(int* new_fd){
	char playerToJoin[DATASIZE];
	int sockToJoin;
	recv(*new_fd, playerToJoin, DATASIZE, 0);
	sockToJoin = get_socket(playerToJoin);
	addToQueue(*new_fd, sockToJoin);
	pthread_exit(0);
}

void* supportHandler(void* param){
	struct DataToSend* data = (struct DataToSend*) param;
	for (int i = 0; i < get_size_coord(data->towers); ++i){
		send(data->socket, &data->towers.array[i]._x, 0, 0);
		send(data->socket, &data->towers.array[i]._y, 0, 0);
	}
}

void update_highscore(char* playername, int score, int mode){
	const char* MODE_1 = "team_ranking.txt";
	const char* MODE_2 = "chrono_ranking.txt";
	const char* MODE_3 = "vs_ranking.txt";
	Ranking ranking;
	pthread_rwlock_wrlock(&rwlock);
	switch(mode){
		case 1:
			ranking.init(MODE_1);
			break;
		case 2:
			ranking.init(MODE_2);
			break;
		case 3:
			ranking.init(MODE_3);
			break;
	}
	ranking.update_ranking(playername, score);
	ranking.update_file();
	pthread_rwlock_unlock(&rwlock);
}

void* threadFunction(void* param);

void* gameMaker(void* param){
/* Updates the game for every player until the end and returns them to the lobby */
	Array sockets;
	initArray_int(&sockets, 1);
    char buffer[DATASIZE];
    fd_set rdfs;
    struct gameData* data = (struct gameData*) param;
    int i, max, done=0, number=0, spectatefd=0, go=1, saveGameMode=data->gameMode, mess;
	int numberPlayers;
	if (data->gameMode == 2)
		numberPlayers=1;
	else
		numberPlayers=4;
    char playerUserNames[numberPlayers][DATASIZE]; //get_size_int(data->sockets)
	for (i = 0; i < numberPlayers; ++i) { // get_size_int(data->sockets)
		if (data->sockets[i] != -1 && data->sockets[i] != 0) { // Adds the socket to the array
            printf("SOCKET: %d\n", data->sockets[i]);
            number++;
			insertArray_int(&sockets, data->sockets[i]);
            strncpy(playerUserNames[i], data->players[i], DATASIZE);
        }
        else {
            char Nobody[DATASIZE] = " ";
            strncpy(playerUserNames[i], Nobody, DATASIZE);
        }
    }
    printf("Number of players: %d\n", number);
    while(done==0){
        FD_ZERO(&rdfs);
        FD_SET(STDIN_FILENO, &rdfs);
		spectatefd = checkQueue(sockets.array);
		printf("Spectator : %d \n", spectatefd);

/*
		if (spectatefd != 0){
			data->nbPlayer++;
			insertArray_int(&sockets, spectatefd);
			send(spectatefd, &go, 1, 0);
			send(spectatefd, &data->nbPlayer, 1, 0);
			send(spectatefd, &data->gameMode, 1, 0);
			pthread_t support;
			struct DataToSend coords;
			coords.towers = data->towers;
			coords.socket = spectatefd;
			pthread_create(&support, NULL, supportHandler, (void*)&coords);
			printf("%d \n", spectatefd);
		}

*/

		if (spectatefd != 0){
			int x = 500; int y = 500;
			send(spectatefd, &x, sizeof(x), 0);
            send(spectatefd, &y, sizeof(y), 0);
		}
		printf("FOR\n");


        for(i = 0; i < numberPlayers; i++) //get_size_int(data->sockets)
        {
			printf("SOCKET: %d\n", sockets.array[i]);
            if (sockets.array[i] != 0) { // Adds the socket to the select
                FD_SET(sockets.array[i], &rdfs);
				printf("FD_SET\n");
                if (max < sockets.array[i]) max = sockets.array[i];
            }
        }
		printf("SELECT\n");
		if(select(max + 1, &rdfs, NULL, NULL, NULL) == -1) // We wait until one of the sockets is ready in I/O
        {
            perror("select()");
            exit(errno);
        }
		printf("FOR\n");
        for(i = 0; i < numberPlayers; i++){ //get_size_int(data->sockets)
            if(FD_ISSET(sockets.array[i], &rdfs)){ //When a socket is modified, we check which one
                printf("Socket n°%d has been modified.\n", sockets.array[i]);
                int x, y, tour, sender;
				int client = sockets.array[i];
                recv(sockets.array[i],&x, sizeof(x), 0); // And we receive his buffer
                recv(sockets.array[i],&y, sizeof(y), 0);
				recv(sockets.array[i], &sender, sizeof(sender), 0);
				if (y != 37 && y != 25)
             	   recv(sockets.array[i],&tour,sizeof(tour),0);
				else if (y == 25)
					recv(sockets.array[i], &mess, sizeof(mess), 0);
				printf("%d %d %d %d \n", x, y, tour, sender);
				if (x == 1000 && y == 1000) { // Creates a new thread for the socket to return to the menu
					//update file
					int score;
					recv(sockets.array[i], &score, sizeof(score), 0);
                    printf("Username: %s, score: %d, gameMode: %d\n", playerUserNames[i], score, saveGameMode);
					update_highscore(playerUserNames[i], score, saveGameMode);
                    struct Data {
                        Matchmaking* match;
                        int socket;
                        int isConnected = 0;
                    } newData;
                    number--;
                    pthread_t newClient;
                    struct Matchmaking* newMatch = newMatchmaking();
                    newData.socket = sockets.array[i];
                    newData.match = newMatch;
                    newData.isConnected = 1;
                    sockets.array[i] = 0;
					int ret;
                    ret = pthread_create(&newClient,NULL,threadFunction,(void*)&newData);
                    if(ret!=0) {
                        printf("Creation of thread failed.");
                        return 0;
                    }
                    printf("Thread for socket n°%d has been created.\n", newData.socket);
                    if (number==0) {
                        printf("Ending thread gameMaker\n");
                        done=1;
                        break;
                    }
                }
                else { // update the map to the other players
                    Coord temp; temp._x = x; temp._y = y;
                    insertArray_coord(&data->towers, temp);
					int j;
                    for(j = 0; j < numberPlayers; j++) {//get_size_int(data->sockets)
						// don't send infos to the client socket nor an empty socket
                        if (sockets.array[j] != client && sockets.array[j] != -1 && sockets.array[j] != 0) {
                            printf("Player: %d, client: %d\n", sockets.array[j], client);
                            send(sockets.array[j], &x, sizeof(x), 0);
                            send(sockets.array[j], &y, sizeof(y), 0);
                            send(sockets.array[j], &sender, sizeof(sender), 0);
                            if (y != 37 && y != 25)
                                send(sockets.array[j], &tour, sizeof(tour), 0);
							else if ( y == 25)
								send(sockets.array[j], &mess, sizeof(mess), 0);
                        }
                    }
                }
            }
        }
    }
    pthread_exit(0);
}

void startParty(int *new_fd, Matchmaking* match)
{
	/* Gets the user in the matchmaking and launch the game */
	char* id;
	id = (char*)malloc(DATASIZE);
    int gameMode;
    if (recv(*new_fd,&gameMode,sizeof(gameMode),0) == -1) {
            perror("recv");
            exit(1);
        }
    printf("SOCKETLIST\n");
    int* socketList = Matchmaking_newPlayer(match, *new_fd, gameMode);
	// Returns "0" if the lobby is not full
    if (socketList) { // Launch the game
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
		gameInfo.gameMode = gameMode;
		initArray_coord(&gameInfo.towers, 1);
        for (int i = 0; i < gameInfo.nbPlayer; ++i){
            send(gameInfo.sockets[i], &gameMode, 1, 0);
			send(gameInfo.sockets[i], &i, 1, 0);
			recv(gameInfo.sockets[i], id, DATASIZE, 0);
			printf("%d %s \n", i, id);
			strncpy(gameInfo.players[i], id, DATASIZE);
        }
		insertArray_data(&myData, gameInfo);
		for (int i = 0; i < gameInfo.nbPlayer; ++i){
			printf("%s \n", gameInfo.players[i]);
		}
        printf("gameInfo.gameMode: %d\n", gameInfo.gameMode);
        printf("Create thread gameMaker\n");
        int ret=pthread_create(&game,NULL,gameMaker,(void*)&gameInfo); 
    }
	free(id);
    printf("Exit startParty\n");
	pthread_exit(0);
}


int connectUser(int param){
    int done=0, positionInFile, c, new_fd=param, pass, quitChoice;
    FILE *fp;
    char id[DATASIZE];
    char tempId[DATASIZE]; // Will contain the pseudos read in the file.
    int tempPass=0, isConnected=0; // Will contain password and the boolean value in the file.

    fp = fopen("accounts.txt", "r+"); // Opening accounts.txt
    if (fp == NULL) {
        printf("I couldn't open accounts.txt for reading.\n");
        exit(0);
    }
    done=0;
    while(done!=1)
    {
        /*
        *   Fseek will in this case put the pointer fp at the beginning of the file.
        *   It's important because if the user enter a wrong id/pass or choose an account
        *   already logged, the pointer fp will be at end of the files from the previous reading.
        */
        fseek(fp,0,SEEK_SET);
        if ((recv(new_fd,&quitChoice,sizeof(quitChoice),0)) == -1)
        {
            perror("recv");
            exit(1);
        }
        if(quitChoice == 1){
            fclose(fp);
            return 0;
        }
        if ((recv(new_fd,id,DATASIZE,0)) == -1)
        {
            perror("recv");
            exit(1);
        }
        printf("User id:%s\n",id);
        if ((recv(new_fd,&pass,sizeof(pass),0)) == -1)
        {
            perror("recv");
            exit(1);
        }
        printf("User password:%d\n",pass);
        while (!feof (fp)) // While it's not end of file.
         {
            fscanf (fp, "%s %d %d", tempId,&tempPass,&isConnected); // We get the id, pass and the boolean of the line.
            if(strcmp(tempId,id)==0 && tempPass==pass) // Compare the id and the pass with the values given by the user.
            {
                if(isConnected!=1) // Check if someone isn't already connected with the account that we are trying to use.
                {
                    done=1;
                    positionInFile=ftell(fp);
                    fseek(fp,positionInFile-1,SEEK_SET);
                    fputs("1",fp); // We change the boolean value to know which account are connected.
                    fseek(fp,positionInFile+1,SEEK_SET);
                    break;
                }
                else
                {
                    done=2;
                    break;
                }
            }
            else{
                done = 0;
            }

         }
        if(done==0)
        {
        
            printf("Password or id is incorrect.\n");
            fseek(fp,0,SEEK_SET);
        }
        else if(done==2)
        {
            printf("Account is already logged.\n");
        }
        if(send(new_fd,&done,sizeof(done),0)==-1)
        {
            perror("send");
            exit(1);
        } 
        
    }
    fclose(fp); // Closing accounts.txt
    return 1;
}

int registerAccount(int fd){
    int done=0, positionInFile, c, new_fd=fd, pass, quitChoice;
    FILE *fp;
    char id[DATASIZE];
    char tempId[DATASIZE]; // Will contain the pseudos read in the file.
    int tempPass=0,isConnected=0; // Will contain password and the boolean value in the file.
    
    fp = fopen("accounts.txt", "r+"); // Opening accounts.txt
    if (fp == NULL) {
        printf("I couldn't open accounts.txt for reading.\n");
        exit(0);
    }
    while(done==0)
    {
        if ((recv(new_fd,&quitChoice,sizeof(quitChoice),0)) == -1)
        {
            perror("recv");
            exit(1);
        }
        if(quitChoice == 1){
            fclose(fp);
            return 0;
        }
        fseek(fp,0,SEEK_SET); // fp pointer is set at the beginning of the file
        if(recv(new_fd,id,DATASIZE,0)== -1)
        {
            perror("recv");
            exit(1);
        }
        printf("User new ID: %s\n",id);
        if (recv(new_fd,&pass,sizeof(pass),0) == -1)
        {
            perror("recv");
            exit(1);
        }
        printf("User new password: %d\n",pass);
        done=1;
        while(fscanf(fp,"%s\n",tempId)==1)
        {
            if(strcmp(tempId,id)==0)// Compare the file id with the id given by the user.
            {
                printf("ID already exist!\n");
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
            perror("Error");
            exit(1);
        }
    }
    fclose(fp); // Closing accounts.txt
    return 1;
}

void addFriend(int fd)
{
    FILE *fptr,*fptr2,*fptrAccount; 
    int isFinished=0;
    while(!isFinished)
    {
		if(recv(fd,&isFinished,sizeof(isFinished),0)==-1)
		{
		    perror("recv");
		    exit(1);
		}
		if(isFinished){
			return;
		}
        fptrAccount=fopen("accounts.txt","r"); // Opening accounts.txt
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
            printf("The friend to add: %s\n",friendToAdd);
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
            fclose(fptrAccount); // Closing accounts.txt
            if(send(fd,&exist,sizeof(exist),0)==-1)
            {
                perror("Error\n");
                exit(1);
            }   
            if(exist)
            {
                fptr = fopen(friendToAdd, "r"); // Opening the friend's file
                if(fptr == NULL) // If the file doesn't exist, create it
                {
                  printf("Creating the file: %s\n",friendToAdd);
                  fptr = fopen(friendToAdd, "w+"); // Creating the friend's file
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
                fclose(fptr); // Closing the friend's file
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
		if(recv(fd,&isFinished,sizeof(isFinished),0)==-1)
		{
		    perror("error\n");
		    exit(1);
		}
		if(isFinished){
			return;
		}
        fptrAccount=fopen("accounts.txt", "r"); // Opening accounts.txt
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
            fclose(fptrAccount); // Closing accounts.txt
            if(send(fd,&exist,sizeof(exist),0)==-1)
                {
                    perror("error");
                    exit(1);
                }
            if(exist){
                fptr = fopen(myUsername, "r"); // Opening the user's file
                if(fptr == NULL) // If the file doesn't exist, create it
                {
                    printf("Creating the file: %s\n",myUsername);
                    fptr = fopen(myUsername, "w+"); // Creating the user's file
                }
                fptr2=fopen("temp1","w+");// Creates a temporary #1 file
                while(fscanf(fptr, "%s %d", id,&isFriend)==2)
                {

                    if((strcmp(id,friendToDelete)==0) && isFriend==1)
                    {
                        isFound=1;
                        int friendTag;
                        char tempId[DATASIZE];
                        fptr3 = fopen(friendToDelete,"r"); // Opening the friend's file
                        if(fptr3 == NULL) // If the file does not exist, create it
                        { 
                            printf("creating the file:%s\n",friendToDelete);
                            fptr3 = fopen(friendToDelete, "w+"); // Creating the friend's file
                        }
                        fptr4=fopen("temp2","w+");// Creates a temporary #2 file
                        while(fscanf(fptr3,"%s %d", tempId,&friendTag)==2)
                        {
                            if((strcmp(tempId,myUsername) != 0))
                            {
                                fprintf(fptr4,"%s %d\n",tempId,friendTag);
                            }
                        }
                        fclose(fptr3); // Closing the friend's file
                        fclose(fptr4); // Closing the temporary #2 file
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
                fclose(fptr); // Closing the user's file
                fclose(fptr2); // Closing the temporary #1 file
                
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

void acceptFriend(int fd)
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
    fptr= fopen(myUsername,"r"); // Opening the user's file
    if (fptr == NULL) {
        perror("Failed: ");
    }
    fptr2=fopen("temp","w"); // Creating/opening a temporary file
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
    fclose(fptr); // closing the user's file
    fclose(fptr2); // Closing the temporary file
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
    printf("The user %s is trying to see his friend list\n",myUsername);
    pthread_mutex_lock(&mutex);
	fptr= fopen(myUsername,"r+");
    if (fptr == NULL) {
        printf("I couldn't open \"%s\" for reading.\n",myUsername);
        printf("Creating the file for further operations\n");
        fptr= fopen(myUsername,"w");
    
    }
    fptr= fopen(myUsername,"r+");
	pthread_mutex_unlock(&mutex);
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
				pthread_mutex_lock(&mutex);
                addFriend(*fd);
				pthread_mutex_unlock(&mutex);
                break;
            case 2:
				pthread_mutex_lock(&mutex);
                deleteFriend(*fd);
				pthread_mutex_unlock(&mutex);
                break;
            case 3:
				pthread_mutex_lock(&mutex);
                acceptFriend(*fd);
				pthread_mutex_unlock(&mutex);
                break;
            case 4:
                showFriend(*fd);
                break;
            case 5:
                break;
        }
    }
}

void rankingView(int* fd){
	const char* MODE_1 = "team_ranking.txt";
	const char* MODE_2 = "chrono_ranking.txt";
	const char* MODE_3 = "vs_ranking.txt";
	int choice;
	if( recv(*fd, &choice, sizeof(choice), 0)==-1){
		perror("error highscore choice\n");
	}
	Ranking ranking;
	pthread_rwlock_rdlock(&rwlock);
	switch(choice)
	{
		case 1:
			ranking.init(MODE_1);
			break;
		case 2:
			ranking.init(MODE_2);
			break;
		case 3:
			ranking.init(MODE_3);
			break;
	}
	const char* highscore= ranking.get_highscore();
	pthread_rwlock_unlock(&rwlock);
	if(send(*fd, highscore, 1024, 0)==-1){
		perror("error highscore\n");
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
	pthread_mutex_lock(&mutex);
    fp= fopen(myUsername,"r");
    if (fp == NULL) {
        printf("I couldn't open \"%s\" for reading.\n",myUsername);
        printf("Creating the file for further operations\n");
        fp= fopen(myUsername,"w");
    
    }
    fp= fopen(myUsername,"r");
	pthread_mutex_unlock(&mutex);
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
        printf("I couldn't open \"accounts.txt\" for reading.\n");
        exit(0);
    }
    char tempId[DATASIZE]; // Will contain the pseudos read in the file.
    int positionInFile;
    int tempPass=0,isConnected=0;
    while (!feof(fp)) // While it's not end of file.
         {
            fscanf(fp, "%s %d %d", tempId, &tempPass, &isConnected); // We get the id of the line
            if(strcmp(tempId,username)==0) // Compare the id with the value given by the user.
            {
                positionInFile=ftell(fp);
                fseek(fp,positionInFile-1,SEEK_SET);
                fputs("0",fp); // We change the boolean value
                fseek(fp,positionInFile+1,SEEK_SET);
                break;
            }
         }
    fclose(fp); // close accounts.txt
}

void* threadFunction(void* param)
{
    int choice, done=0;
    struct Data* data = (struct Data*) param;
    int connected=data->isConnected, new_fd=data->socket;
    printf("threadFunction - Socket n°%d\n", new_fd);
    while (done==0) {
        if (connected == 0) {
            if (recv(new_fd,&choice,sizeof(choice),0) == -1) {
                perror("recv");
                exit(1);
            }
            switch(choice) {
                case 1:
                    printf("Socket n°%d wants to connect.\n", new_fd);
                    connected = connectUser(new_fd);
                    break;
                case 2:
                    printf("Socket n°%d wants to create an account.\n", new_fd);
                    int createAccount;
                    createAccount = registerAccount(new_fd);
                    if (createAccount == 1) {
                        connected = connectUser(new_fd);
                    }
                    break;
                case 3:
                    printf("Socket n°%d has exited the game.\n", new_fd);
                    send(new_fd, "exit", DATASIZE, 0);
                    done = 1;
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
					printf("Socket n°%d wants to start a game.\n", new_fd);
                    send(new_fd, "startGame", DATASIZE, 0);
                    startParty(&new_fd, data->match);
                    break;
                case 2:
					printf("Socket n°%d wants to support a friend.\n", new_fd);
                    send(new_fd, "Support", DATASIZE, 0);
					support(&new_fd);
                    break;
                case 3:
                    printf("Socket n°%d wants to access his profile.\n", new_fd);
                    profilView(&new_fd);
                    break;
                case 4:
					printf("Socket n°%d wants to access the ranking list.\n", new_fd);
					rankingView(&new_fd);
                    break;
                case 5:
                    printf("Socket n°%d wants to access his friend list.\n", new_fd);
                    friendView(&new_fd);
                    break;
                case 6:
                    printf("Socket n°%d has been deconnected.\n", new_fd);
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
        printf("Server: got connection from socket %d\n",new_fd);
		// Creation of multiple threads for each client.
        int ret=pthread_create(&connectedClient,NULL,threadFunction,(void*)&array_client[totalClient]);
        totalClient++;
        if(ret!=0)
        {
            printf("Creation of thread failed.");
            return 0;
        }
    }
}
 
int main(void)
{
	initArray_data(&myData, 1);
    struct Matchmaking* match = newMatchmaking();
    int sockfd;
    struct Data array_client[30];
    for (int i =0; i < 30; ++i){
        array_client[i].match = match;
    }
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // Connector's address information
    socklen_t sin_size;
    sin_size = sizeof(struct sockaddr_in);
	pthread_rwlock_init(&rwlock, NULL);
    beginListen(&sockfd,array_client,my_addr,their_addr);
    acceptClient(&sockfd,my_addr,their_addr,sin_size,array_client);
	pthread_rwlock_destroy(&rwlock);
    return 0;
}
