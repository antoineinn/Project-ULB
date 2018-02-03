//#include <iostream>
#include <ncurses.h>
#include "grid.hpp"
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>

#ifndef GAME_HPP
#define GAME_HPP

#define MAXDATASIZE 1024

class Game{

	int delay, sockfd, _player, _laps, _mode, _time, _chrono;
	Grid m_grid;
	bool end, dead;

public:

	Game(int socket, int player, int mode) : sockfd(socket), _player(player), _laps(0), dead(false), _mode(mode), _time(80), _chrono(900){
		//---Début de l'initialisation de l'interface Ncurse---
		initscr();
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		nodelay(stdscr, true);
		keypad(stdscr, true);
		noecho();
		curs_set(0);
		mousemask(ALL_MOUSE_EVENTS, nullptr);
		refresh();
		move(35, 10); printw("%d", _player);
		move(36, 10); printw("%d", mode);
		move(37, 10); printw("Surrender");
		if (mode == 2){
			move(32, 15); addstr("Chrono : "); 
			move(32, 25); printw("%d", _chrono);
			move(33, 15); addstr("Press KEY_RIGHT to make te wave coming");
		}
		//---Fin d'initialisation---
		delay = 250000;
		m_grid = Grid(mode, player);
		end = false;
	}

	~Game(){
		nodelay(stdscr, false);
		getch();
		endwin();
	}

	void start(){
		FILE *fptr = fopen("wave.txt", "r");
		MEVENT event;
		int x, y;
		int nbNextWave;
		int basic;
		while (1){
			if (_mode == 2){
				_laps += 1;
				if (_laps % 4 == 0) _chrono -= 1;
				move(32, 25); printw("    "); printw("%d", _chrono);
			}
			usleep(delay);
			int player;
			recv(this->sockfd,&x, 10, MSG_DONTWAIT);
			recv(this->sockfd,&y, 10, MSG_DONTWAIT);
			recv(this->sockfd,&player, 10, MSG_DONTWAIT);
			if (x && y && player != -1){
				if (x >= 10 && x <= 20 && y == 37){
					m_grid.set_health(player, 0);
					x = 0; y = 0; player = -1;
				}
				else{
					m_grid.addTower(y, x, player, true);
					x = 0; y = 0; player = -1;
				}
			}
			if (m_grid.isEmpty()){
				if (_time == 0){
					fscanf(fptr, "%d %d", &nbNextWave, &basic);
					m_grid.createEnnemies(nbNextWave, basic);
					_time = 80;
				}
				_time -= 1;
				move(32, 10);
				printw("%d", _time/8);
			}
			int tmp = getch(); //Intercepte la touche tapée par l'utilisateur
			switch(tmp){
				case KEY_MOUSE: //Clic gauche : Création de tourelle
					if (getmouse(&event) == OK){
						if (event.x >= 10 && event.x <= 20 && event.y == 37){
							m_grid.set_health(_player, 0);
							send(this->sockfd,&event.x, 10, 0);
							send(this->sockfd,&event.y, 10, 0);
							send(this->sockfd,&_player, 10, 0);
						}
						else{
							if (m_grid.isEmpty()){
								if (!dead){
									if (m_grid.addTower(event.y, event.x, _player)){
										send(this->sockfd,&event.x, 10, 0);
										send(this->sockfd,&event.y, 10, 0);
										send(this->sockfd,&_player, 10, 0);
									}
								}
							}
						}
					}
					break;
				case KEY_RIGHT:
					if (_mode == 2) _time = 0;
					break;
			}
			if (end) break;
			if (!m_grid.isEmpty()){ //Si des ennemis sont présents
				m_grid.moveAllEnnemies();
				if (m_grid.isTower()) //Si des tours sont présentes
					m_grid.makeTowersAttack();
			}
			if (_mode != 2)
				dead = m_grid.isSomeoneDead(_player);
			end = m_grid.isOver(_chrono);
		}
		if (m_grid.get_health(_player) > 0){
			move(50, 50); printw("You win ! Press KEY_LEFT then any key to exit");
		}
		else{
			move(50, 50); printw("You loose ! Press KEY_LEFT then any key to exit");
		}
		while (1){
			bool back;
			int tmp = getch();
			switch (tmp){
				case KEY_LEFT:
					back = true;
					break;
			}
			if (back) break;
		}
	}
};

#endif
