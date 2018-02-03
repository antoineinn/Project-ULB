#include "grid.hpp"

/* PUBLIC */

// Constructor

Grid::Grid(int mode, int player) : _player(player), _mode(mode){
	if (mode == 1){
		NBQUARTER = 2;
		NBPLAYER  = 4;
	}
	else if (mode == 2){
		NBQUARTER = 1;
		NBPLAYER  = 1;
	}
	else if (mode == 3){
		NBQUARTER = 4;
		NBPLAYER  = 4;
	}
	map[0]="Hello";
	map[1]="Bye";
	map[2]="Goddamn Vegan";
	map[3]="Looser";
	map[4]="Nooooob";
	_vectorEnnemies = new Wave*[NBQUARTER];
	_nbTowers = new int[NBPLAYER];
	for (int i = 0; i < NBPLAYER; ++i) _nbTowers[i] = 0;
	_score = new int[NBPLAYER];
	for (int i = 0; i < NBPLAYER; ++i) _score[i] = 0;
	_money = new int[NBPLAYER];
	for (int i = 0; i < NBPLAYER; ++i) _money[i] = 300;
	_health = new int[NBPLAYER];
	for (int i = 0; i < NBPLAYER; ++i) _health[i] = 9;
	_empty = true;
	edge = static_cast<char>(219);
	m_board = new Case*[taille];
	for (int j = 0; j < taille; ++j)
		m_board[j] = new Case[taille];
	for (int i = 0; i < taille; ++i){
		for (int j = 0; j < taille; ++j){
			struct Coord temp;
			temp._x = i; temp._y = j;
			m_board[i][j] = Case(temp);
		}
	}
	make_path();
	print_grid();
}

// Functions

void Grid::print_grid(){
	//Dessine les bordures
	for (int i = 0; i < taille*2; ++i){
		move(0, i+1);
		addch(edge);
	}
	for (int i = 0; i < taille*2+1; ++i){
		move(taille+1, i);
		addch(edge);
	}
	for (int i = 0; i < taille+2; ++i){
		move(i, 0);
		addch(edge);
	}
	for (int i = 0; i < taille+2; ++i){
		move(i, taille*2+1);
		addch(edge);
	}
	//Dessine le board

	if (_mode == 1){
		for (int i = 0; i<taille; ++i){
			for (int j = 0; j < taille; ++j){
				if ((_player == 0 || _player == 1) && i >= 0 && i <= 15 && j >= 0 && j <= 15)
					attron(COLOR_PAIR(2));
				else if ((_player == 2 || _player == 3) && i <= 29 && i >= 15 && j >= 1 && j <= 15)
					attron(COLOR_PAIR(2));
				m_board[i][j].print();
				attroff(COLOR_PAIR(2));
			}					
		}
	}
	else{
		for (int i = 0; i<taille; ++i){
			for (int j = 0; j < taille; ++j){
				if (_player == 0 && i >= 0 && i <= 15 && j >= 0 && j <= 15)
					attron(COLOR_PAIR(2));
				else if (_player == 1 && i <= 29 && i >= 15 && j >= 1 && j <= 15)
					attron(COLOR_PAIR(2));
				else if (_player == 3 && i <= 29 && i >= 15 && j <= 29 && j >= 15)
					attron(COLOR_PAIR(2));
				else if (_player == 2 && i >= 1 && i <= 15 && j <= 29 && j >= 15)
					attron(COLOR_PAIR(2));
				m_board[i][j].print();
				attroff(COLOR_PAIR(2));
			}					
		}
	}
	//Dessine le tableau d'information
	move(SCORE_Y, SCORE_X*2 + 10);
	addstr("Score");
	move(SCORE_Y, SCORE_X*2 + 20);
	addstr("Money");
	move(SCORE_Y, SCORE_X*2 + 30);
	addstr("Health");
	move(32, 1);
	addstr("Time");
	for (int i = 0; i < NBPLAYER; ++i){
		move(SCORE_Y+1+i, SCORE_X*2); addstr("player");
		move(SCORE_Y+1+i, SCORE_X*2 + 7); printw("%d", _player);
		move(SCORE_Y+1+i, SCORE_X*2 + 10); addch('0');
		move(SCORE_Y+1+i, SCORE_X*2 + 20); addstr("300");
		move(SCORE_Y+1+i, SCORE_X*2 + 30); addstr("9");
	}
	move(9,64);
	addstr("SELECT TOWERS:");
	move(10,80);
	addstr("Basic");
	move(12,80);
	addstr("Heavy");
	move(14,80);
	addstr("Bomb");
	move(17,64);
	addstr("Ennemy types:");
	move(18,80);
	addstr("o: Typical Vegan, Health: 3, Damage: low, Score: 1 ");

	move(20,80);
	addstr("~: Hard Vegan, Health: 6, Damage: low, Score: 2 ");

	move(22,80);
	addstr("%: Damning Vegan, Health: 3, Damage: High, Score: 2 ");

	move(24,64);
	addstr("CHAT:");



	move(25,80);
	addstr("Hello |");
	move(25,88);
	addstr("Bye |");
	move(25,94);
	addstr("Goddamn vegan! |");
	move(25,111);
	addstr("Looser |");
	move(25,119);
	addstr(" Nooooob |");
}

void Grid::make_path(){
	/*
	 * Créer le path.
	 */
	_path = new Case*[NBQUARTER];
	for (int k = 0; k < NBQUARTER; ++k){
		_path[k] = new Case[26];
		int j = 0;
		for (int i = 0; i < 13; ++i){
			if (k == 0){
				m_board[i][i].set_path(true);
				_path[k][j] = Case(Coord(i, i)); j+=1;
				m_board[i+1][i].set_path(true);
				_path[k][j] = Case(Coord(i+1, i)); j+=1;
			}
			else if (k == 1){
				m_board[28-i+1][i].set_path(true);
				_path[k][j] = Case(Coord(28-i+1, i)); j+=1;
				m_board[28-i][i].set_path(true);
				_path[k][j] = Case(Coord(28-i, i)); j+=1;
			}
			else if (k == 2){
				m_board[i+1][29-i].set_path(true);
				_path[k][j] = Case(Coord(i, 29-i)); j+=1;
				m_board[i][29-i].set_path(true);
				_path[k][j] = Case(Coord(i+1, 29-i)); j+=1;
			}
			else{
				m_board[28-i+1][29-i].set_path(true);
				_path[k][j] = Case(Coord(28-i+1, 29-i)); j+=1;
				m_board[28-i][29-i].set_path(true);
				_path[k][j] = Case(Coord(28-i, 29-i)); j+=1;
			}
		}
	}
}

void Grid::createEnnemies(int nb, int a, int b, int c){
	for (int i = 0; i < NBQUARTER; ++i){
		if (_health[i] > 0) _vectorEnnemies[i] = new Wave(_path[i], nb, a, b, c);
	}
	_empty = false;
}

void Grid::moveAllEnnemies(){
	int score;
	for (int i = 0; i < NBQUARTER; ++i){
		for (int j = 0; j < _vectorEnnemies[i]->get_size(); ++j){
			struct Coord temp = _vectorEnnemies[i]->get_ennemy(j)->get_coord();
			if (temp._x >= 0 && temp._y >=0) m_board[temp._x][temp._y].set_state(false);
		}
		score = _vectorEnnemies[i]->moveWaveEnnemies();
		if (score > 0){
			if (_mode == 1){
				if (i == 0){
					_money[0] += 20*score;
					_score[0] += score;
					_money[1] += 20*score;
					_score[1] += score;
				}
				else if (i == 1){
					_money[2] += 20*score;
					_score[2] += score;
					_money[3] += 20*score;
					_score[3] += score;
				}
			}
			else{
				_money[i] += 20*score;
				_score[i] += score;
			}
		}
		else{
			if (_mode == 1){
				if (i == 0){
					_health[0] += score;
					_health[1] += score;
				}
				else if (i == 1){
					_health[2] += score;
					_health[3] += score;
				}
			}
			else{
				_health[i] += score;
			}
		}
		if (_mode == 1){
			if (i == 0){
				move(SCORE_Y+1, SCORE_X*2 + 30);
				printw("%d", _health[0]);
				move(SCORE_Y+1, SCORE_X*2 + 10);
				printw("%d", _score[0]);
				move(SCORE_Y+1, SCORE_X*2 + 20);
				printw("%d", _money[0]);
				move(SCORE_Y+2, SCORE_X*2 + 30);
				printw("%d", _health[1]);
				move(SCORE_Y+2, SCORE_X*2 + 10);
				printw("%d", _score[1]);
				move(SCORE_Y+2, SCORE_X*2 + 20);
				printw("%d", _money[1]);
				refresh();
			}
			else if (i == 1){
				move(SCORE_Y+3, SCORE_X*2 + 30);
				printw("%d", _health[2]);
				move(SCORE_Y+3, SCORE_X*2 + 10);
				printw("%d", _score[2]);
				move(SCORE_Y+3, SCORE_X*2 + 20);
				printw("%d", _money[2]);
				move(SCORE_Y+4, SCORE_X*2 + 30);
				printw("%d", _health[3]);
				move(SCORE_Y+4, SCORE_X*2 + 10);
				printw("%d", _score[3]);
				move(SCORE_Y+4, SCORE_X*2 + 20);
				printw("%d", _money[3]);
				refresh();
			}
		}
		else{
			move(SCORE_Y+1+i, SCORE_X*2 + 30);
			printw("%d", _health[i]);
			move(SCORE_Y+1+i, SCORE_X*2 + 10);
			printw("%d", _score[i]);
			move(SCORE_Y+1+i, SCORE_X*2 + 20);
			printw("%d", _money[i]);
			refresh();
		}
		for (int k = 0; k < _vectorEnnemies[i]->get_size(); ++k){
			struct Coord temp = _vectorEnnemies[i]->get_ennemy(k)->get_coord();
			if (temp._x >= 0 && temp._y >=0) m_board[temp._x][temp._y].set_state(true);
		}
	}
	_empty = true;
	for (int i = 0; i < NBQUARTER; ++i)
		if (_vectorEnnemies[i]->get_size() != 0) _empty = false;
}

void Grid::printMessage(int message,int player,int mode){
	// move(56, 56); printw("%d %d",mode,player); refresh();

	if (mode==3 or mode==1){	//4joueurs
		if (player==0){
			move(1,104);
			addstr("                 ");
			refresh();
			move(1,104);
			addstr(map[message]);
			refresh();

		}
		else if (player==1){
			move(2,104);
			addstr("                ");
			refresh();
			move(2,104);
			addstr(map[message]);
			refresh();

		}

		else if (player==2){
			move(3,104);
			addstr("                ");
			refresh();
			move(3,104);
			addstr(map[message]);
			refresh();

		}
		else if (player==3){
			move(4,104);
			addstr("                ");
			refresh();
			move(4,104);
			addstr(map[message]);
			refresh();

		}
	}
}

bool Grid::addTower(int x, int y, int c, int player, bool check){
	/* Ajoute une tourelle sur le board.
	 * TODO : Fonction non complete : Vérifier qu'on est bel et bien sur un '#'
	 * avant de créer la tourelle 
	 */
	int quarter;
	if (x >= 1 && x <= 15 && y >= 1 && y <= 15*2) quarter = 0;
	else if (x <= 29 && x >= 15 && y >= 1 && y <= 15*2) quarter = 1;
	else if (x <= 29 && x >= 15 && y <= 29*2 && y >= 15*2) quarter = 3;
	else if (x >= 1 && x <= 15 && y <= 29*2 && y >= 15*2) quarter = 2;
	else return false;

	if (isAble(quarter) || check){
		struct Coord temp;
		temp._x = x-1; temp._y = y/2; //Coord interface -> Coord réelles

		if (c==1){
			if(_money[player] < priceBasic) return false;
            _vectorTowers[player].push_back(new BasicTower(temp));
			_money[player] -= priceBasic;
        }
        else if (c==2){
			if(_money[player] < priceHard) return false;
            _vectorTowers[player].push_back(new HeavyTower(temp));
			_money[player] -= priceHard;
        }
        else if (c==3){
			if(_money[player] < priceBomb) return false;
        	BombTower* tempT= new BombTower(temp);
        	_vectorTowers[player].push_back(tempT);
        	_bombTowers.push(tempT);
			_money[player] -= priceBomb;
        }
		move(SCORE_Y+1+player, SCORE_X*2 + 20); printw("    ");
		move(SCORE_Y+1+player, SCORE_X*2 + 20); printw("%d", _money[player]);
		refresh();
		_nbTowers[player] += 1;
		return true;
	}
	else return false;
}

bool Grid::isAble(int quarter){
	if (_mode == 1){
		if (_player == 0 || _player == 1){
			if (quarter == 0)
				return true;
		}
		else if (_player == 2 || _player == 3){
			if (quarter == 1)
				return true;
		}
	}
	else if (_mode == 2){
		if (_player == 0)
			if (quarter == 0) return true;
	}
	else if (_mode == 3){
		if (_player == quarter) return true;
	}
	return false;
}

void Grid::killAllBombs(){
	while (!_bombTowers.empty()){
		BombTower* temp= _bombTowers.top();
		_bombTowers.pop();
		temp->dead();
	}
}

void Grid::makeTowersAttack(){
	struct Coord temp;
	int player;
	for (int i = 0; i < NBPLAYER; ++i){
		if (_mode == 1){
			if (i == 0 || i == 1) player = 0;
			else if (i == 2 || i == 3) player = 1;
		}
		else player = i;
		for (int j = 0; j < _nbTowers[i]; ++j){
			temp = _vectorTowers[i][j]->get_coord();
			findEnnemies(_vectorTowers[i][j], temp, player);
			_vectorTowers[i][j]->attack(); 
			_vectorTowers[i][j]->clear();
		}
	}
}

void Grid::findEnnemies(Tower* tower, Coord temp, int player){
	for (int i = temp._x - tower->get_range(); i < temp._x + tower->get_range(); ++i){
		for (int j = temp._y - tower->get_range(); j < temp._y + tower->get_range(); ++j){
			if (i >= 0 && j >= 0 && i <= 60 && j <= 30){ 
				if (m_board[i][j].get_type()){
					struct Coord temp = Coord(i, j);
					tower->pushEnnemy(_vectorEnnemies[player]->getEnnemy(temp));
				}	
			}				
		}
	}
}

bool Grid::isSomeoneDead(int player){
	for (int i = 0; i < NBPLAYER; ++i)
		if (_health[i] <= 0) clearGrid(i);
	for (int i = 0; i < NBPLAYER; ++i){
		if (player == i){
			if (_health[i] == 0) return true;
			else return false;
		}
		else return false;
	}
	return false;
}

void Grid::clearGrid(int player){
	if (player == 0){
		for (int i = 1; i < 16; ++i){
			for (int j = 1; j < 16*2; ++j){move(i, j); addch(' '); refresh();}
		}		
	}
	else if (player == 1){
		for (int i = 16; i < 31; ++i){
			for (int j = 1; j < 16*2; ++j){move(i, j); addch(' '); refresh();}
		}
	}
	else if (player == 2){
		for (int i = 1; i < 16; ++i){
			for (int j = 15*2; j < 30*2; ++j){move(i, j); addch(' '); refresh();}
		}
	}
	else if (player == 3){
		for (int i = 15; i < 31; ++i){
			for (int j = 15*2; j < 30*2; ++j){move(i, j); addch(' '); refresh();}
		}
	}
}

bool Grid::isOver(int time){
	int nbDeath = 0;
	if (_mode == 1){
		for (int i = 0; i<NBPLAYER; ++i)
			if (_health[i] <= 0) nbDeath++;
		if (nbDeath >= 1) return true;
	}
	else if (_mode == 2){
		if (_health[_player] <= 0 || time <= 0) return true;
	}
	else if (_mode == 3){
		for (int i = 0; i<NBPLAYER; ++i)
			if (_health[i] <= 0) nbDeath++;
		if (nbDeath >= 3) return true;
	}
	return false;
}
