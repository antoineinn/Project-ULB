#include "matchmaking.hpp"
#include "matchwrapper.hpp"
#include <iostream>
extern "C" {
	Matchmaking* newMatchmaking()
	{
		return new Matchmaking();
	}

	int* Matchmaking_newPlayer(Matchmaking* v, int newSocket ,int mode)
	{
		return v->newPlayer(newSocket ,mode);
	}
}
