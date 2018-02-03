#include <iostream>
#include <set>
#include "Lobby.hpp"

#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

class Matchmaking {
public:
    // constructors
    Matchmaking();
    ~Matchmaking() = default;
	void newPlayer(int newSocket ,int mode);
private:
    std::set<Lobby*> _setOfLobby;

    int _counter;
    // functions
    void createLobby(int mode);	
    Lobby* searchLobby(int mode);
};
            
#endif // MATCHMAKING_HPP
