//#include <iostream>
#include "grid.hpp"
#include <string>
#include <cstdlib>
#include <unistd.h>

#ifndef GAME_HPP
#define GAME_HPP

class Game{

	int delay;
	Grid m_grid;
	bool end;

public:

	Game(){
		//---Début de l'initialisation de l'interface Ncurse---
		initscr();
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		nodelay(stdscr, true);
		keypad(stdscr, true);
		noecho();
		curs_set(0);
		mousemask(ALL_MOUSE_EVENTS, nullptr);
		refresh();
		//---Fin d'initialisation---
		delay = 500000;
		m_grid = Grid();
		end = false;
	}

	~Game(){
		nodelay(stdscr, false);
		getch();
		endwin();
	}

	void start(){
		MEVENT event;
		while (1){
			int tmp = getch(); //Intercepte la touche tapée par l'utilisateur
			switch(tmp){
				case KEY_LEFT: //Flèche de gauche : Lancement d'une wave
					m_grid.createEnnemies(2, 2);
					break;
				case KEY_RIGHT: //Flèche de droite : fin de partie
					end = true;
					break;
				case KEY_MOUSE: //Clic gauche : Création de tourelle
					if (getmouse(&event) == OK)
						if (m_grid.isEmpty())
							m_grid.addTower(event.y, event.x);
					break;
			}
			if (end) break;
			if (!m_grid.isEmpty()){ //Si des ennemis sont présents
				m_grid.moveAllEnnemies();
				if (m_grid.isTower()) //Si des tours sont présentes
					m_grid.makeTowersAttack();
			}
			usleep(delay);
		}
		printw("Game over");
	}

};

#endif
