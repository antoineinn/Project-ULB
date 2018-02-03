#include <ncurses.h>
#include "game.hpp"
#include "gamewrapper.hpp"
#include <iostream>
extern "C" {
    Game* newGame(int socket, int player, int mode, int support)
	{
		return new Game(socket, player, mode, support);
    }

    void gameStart(Game* v)
    {
		return v->start();
    }

	void endGame(Game* v)
	{
		delete v;
	}
}
