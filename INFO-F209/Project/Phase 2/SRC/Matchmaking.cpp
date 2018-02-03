#include "Matchmaking.hpp"

Matchmaking::Matchmaking(): _counter(0) {

    // create a lobby for each mode
    createLobby(1);
    createLobby(2);
    createLobby(3);
	newPlayer(1,1);
	newPlayer(2,1);
	newPlayer(3,1);
	newPlayer(4,1);
	newPlayer(5,1);
	
}

void Matchmaking::createLobby(int mode) {
    // create a lobby with 4 people and a mode
    Lobby* newLobby = new Lobby(_counter, mode);
    _counter++;
    _setOfLobby.insert(newLobby);
}

Lobby* Matchmaking::searchLobby(int mode) {
    // search for a lobby with a mode
    std::set<Lobby*>::iterator current;
    current = _setOfLobby.begin();
    // search in the existing lobbies
    while (current != _setOfLobby.end()) {
        // the lobby who's not full and has the right mode
        if (!(*current)->isFull() && mode==(*current)->getMode()){

            return (*current);}

        current++;
    }
    return 0;
}









void Matchmaking::newPlayer(int newSocket, int mode) {
    // Add a new player to the matchmaking system
	
	bool flag=false;
	while (!flag){	
		Lobby* currLobby = searchLobby(mode);
		if (currLobby!=0) {  //lobby found
                // add the player to the lobby and erase it from the waiting list
                currLobby->addPlayer(newSocket, mode);
                std::cout << "Player added " << newSocket<< std::endl;
                std::cout << "Lobby " << currLobby << std::endl;
				flag=true;
           	 }
     	else {   //lobby not found
                // create a new lobby with the right mode
                createLobby(mode);	 }}
	
}
