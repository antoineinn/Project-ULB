#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP
#include <iostream>
#include <set>
#include "lobby.hpp"

class Matchmaking {
public:
    // constructors
    Matchmaking();
    ~Matchmaking() = default;
	int* newPlayer(int newSocket ,int mode);
private:
    std::set<Lobby*> _setOfLobby;

    int _counter;
    // functions
    void createLobby(int mode);	
    Lobby* searchLobby(int mode);
};
            
#endif // MATCHMAKING_HPP
