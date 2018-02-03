#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include "grid.hpp"
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#define MAXDATASIZE 1024

class Game{
private:
	int delay, sockfd, _player, _laps, _mode, _time, _chrono, _sup;
	Grid m_grid;
	bool end, dead;

public:
	// constructors
	Game(int, int, int, int);
	~Game();
	// function
	void start();
};

#endif
