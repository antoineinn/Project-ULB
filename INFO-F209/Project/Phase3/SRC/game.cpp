#include "game.hpp"

/* PUBLIC */

// Constructors

Game::Game(int socket, int player, int mode, int support) : sockfd(socket), _player(player), _laps(0), _mode(mode), _time(80), _chrono(900), _sup(support), dead(false){
		// Beginning of the initialization of the NCURSE interface
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
		// End of the initialization
		delay = 250000;
		m_grid = Grid(mode, player);
		end = false;
}

Game::~Game(){
		nodelay(stdscr, false);
		getch();
		endwin();
}

// Function

void Game::start(){
	FILE *fptr = fopen("wave.txt", "r");
	MEVENT event;
	int x, y;
	int nbNextWave;
	int basic;
	int hard;
	int damaging;
	int mess = -1;
	int playermess=_player;
    int tour=0;
	bool killBombs = false;
	while (1){
		if (_mode == 2){
			_laps += 1;
			if (_laps % 4 == 0) _chrono -= 1;
			move(32, 25); printw("    "); printw("%d", _chrono);
		}
		usleep(delay);
		int player;
		recv(this->sockfd,&x, sizeof(x), MSG_DONTWAIT);
		if (x)
			recv(this->sockfd,&y, sizeof(y), MSG_DONTWAIT);
		if (x && y)
			recv(this->sockfd,&player, sizeof(player), MSG_DONTWAIT);
		if (x && y && player != -1){
			if (x >= 10 && x <= 20 && y == 37){
				m_grid.set_health(player, 0);
				x = 0; y = 0;
			}
			else if (x == 500 && y == 500){
				m_grid.add_money();
				x = 0; y = 0;
			}
			else if (y==25 && x >= 80){
				recv(this->sockfd,&playermess, sizeof(playermess), MSG_DONTWAIT);
				m_grid.printMessage(playermess,player, _mode);
				x = 0; y = 0;
				mess=-1;
			}		
			else{
				recv(this->sockfd,&tour, sizeof(tour), MSG_DONTWAIT);
				m_grid.addTower(y, x, tour, player, true);
				x = 0; y = 0;
				killBombs = true;
			}
		}
		if (m_grid.isEmpty()){
			if (_time == 0){
				if (fscanf(fptr, "%d %d %d %d", &nbNextWave, &basic, &hard, &damaging)==4){}
				m_grid.createEnnemies(nbNextWave, basic,hard,damaging);
				_time = 80;
				killBombs = true;
			}
			_time -= 1;
			move(32, 10);
			printw("%d", _time/8);
		}
		int tmp = getch();
		switch(tmp){
			case KEY_MOUSE: // Left click : Create a turret
				if (getmouse(&event) == OK){
					if (event.x >= 10 && event.x <= 20 && event.y == 37){ // Surrender selected
						m_grid.set_health(_player, 0);
						send(this->sockfd,&event.x, sizeof(x), 0);
						send(this->sockfd,&event.y, sizeof(y), 0);
						send(this->sockfd,&_player, sizeof(_player), 0);
					}
					else if (event.x>=80 && event.x<=85  && event.y==10){ // Basic tower selected
        				attron(COLOR_PAIR(2));
						move(10, 80);
						addstr("Basic");
						attroff(COLOR_PAIR(2));
						move(10,86);
						addstr(": Damage: 1, Price: 100");
						move(14, 80);
						addstr("Bomb"); 
						move(14,85);
						addstr("                                        ");
						///////RETURNS OTHER TO NORMAL
						move(12, 80);
						addstr("Heavy"); 
						move(12,86);
						addstr("                       ");
						refresh();
						tour=1;
					}
            		
            		else if (event.x>=80 && event.x<=85 && event.y==12){ // Heavy tower selected
            			attron(COLOR_PAIR(2));
						move(12, 80);
						addstr("Heavy"); 
						attroff(COLOR_PAIR(2));
						move(12,86);
						addstr(": Damage: 2, Price: 200");
						move(10, 80);
						addstr("Basic"); 
						move(10,86);
						addstr("                       ");
						move(14,85);
						addstr("                                        ");
						///////RETURNS OTHER TO NORMAL
						move(14, 80);
						addstr("Bomb"); 
						refresh();
						tour=2;
					}

            		else if (event.x>=80 && event.x<=84 && event.y==14){ // Bomb tower selected
            			attron(COLOR_PAIR(2));
						move(14, 80);
						addstr("Bomb");
						attroff(COLOR_PAIR(2));
						move(14,85);
						addstr(": Damage: 4, Price:400, Lifespan: 1 wave");
						move(10, 80);
						addstr("Basic"); 
						move(10,86);
						addstr("                       ");
						///////RETURNS OTHER TO NORMAL
						move(12, 80);
						addstr("Heavy"); 
						move(12,86);
						addstr("                       ");
						refresh();
						tour=3;
					}

					else if (event.x>=80 && event.x<=87 && event.y==25){
						move(25, 80);
						addstr("Hello |");
						refresh();

						mess=0;
					}

					else if (event.x>=88 && event.x<=93 && event.y==25){
						move(25, 88);
						addstr("Bye |");
						refresh();
						
						mess=1;
					}

					else if (event.x>=94 && event.x<=110 && event.y==25){
						move(25, 94);
						addstr("Goddamn vegan! |");
						refresh();			
						mess=2;
					}

					else if (event.x>=111 && event.x<=117 && event.y==25){
						move(25, 111);
						addstr("Looser |");
						refresh();
						mess=3;
					}
					else if (event.x>=119 && event.x<=129 && event.y==25){
						move(25, 119);
						addstr(" Nooooob |");
						refresh();	
						mess=4;
					}
					else{
						if (m_grid.isEmpty()){
							if (!dead){
								if (m_grid.addTower(event.y, event.x, tour, _player)){
									send(this->sockfd,&event.x, sizeof(x), 0);
									send(this->sockfd,&event.y, sizeof(y), 0);
									send(this->sockfd,&_player, sizeof(_player), 0);
									send(this->sockfd,&tour, sizeof(tour), 0);
									if (tour == 3){
										killBombs = false;
									}
								}
							}
						}
					}
				}
				break;
			case KEY_RIGHT: // Pressing the right key launch the new wave
				if (_mode == 2) _time = 0;
				break;
		}
		if (mess!=-1){
			m_grid.printMessage(mess,_player, _mode);
			send(this->sockfd,&event.x, sizeof(event.x), 0);
			send(this->sockfd,&event.y, sizeof(event.y), 0);
			send(this->sockfd,&_player, sizeof(_player), 0);
			send(this->sockfd,&mess, sizeof(mess), 0);
			mess=-1;
		}
		if (end) break;
		if (!m_grid.isEmpty()){ // If enemies are already present
			m_grid.moveAllEnnemies();
			if (m_grid.isTower()) // If towers were already present
				m_grid.makeTowersAttack();
		}
		if (m_grid.isEmpty()){ 
			if (!m_grid.isBombtower()){
				if (killBombs)
					m_grid.killAllBombs();
			}
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
	fclose(fptr);
	while (1){
		bool back = false;
		int tmp = getch();
		if (tmp == KEY_LEFT) { 
			/* 
			* when the player press the left key, he sends to the server
			* 1000 and 1000 to signal him that he quitted the game.
			*/
			int x = 1000;
			int y = 1000;
			int tour = 0;
			int score = m_grid.get_score(_player);
			send(this->sockfd,&x,sizeof(x),0);
			send(this->sockfd,&y,sizeof(y),0);
			send(this->sockfd,&tour,sizeof(tour),0);
			send(this->sockfd,&_player,sizeof(_player),0);
			send(this->sockfd,&score,sizeof(score),0);
			back = true;
			break;
		}
		if (back) break;
	}
}
