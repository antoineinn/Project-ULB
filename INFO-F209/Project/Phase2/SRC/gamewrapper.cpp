#include <ncurses.h>
#include "game.hpp"
#include "gamewrapper.hpp"
#include <iostream>
extern "C" {
        Game* newGame(int socket, int player, int mode)
		{
                return new Game(socket, player, mode);
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
