#include "Matchmaking.hpp"
#include "matchwrapper.hpp"
#include <iostream>
extern "C" {
        Matchmaking* newMatchmaking()
		{
                return new Matchmaking();
        }

        void Matchmaking_newPlayer(Matchmaking* v, int newSocket ,int mode)
        {
                v->newPlayer(newSocket ,mode);
        }
}
