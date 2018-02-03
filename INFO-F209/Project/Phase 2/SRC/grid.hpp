//#include <iostream>
#include "coord.hpp"
#include "wave.hpp"
#include "case.hpp"
#include "tower.hpp"

#ifndef GRID_HPP
#define GRID_HPP


static const int taille = 30;
static const int NBPLAYER = 4;
#define SCORE_X 32
#define SCORE_Y 0

class Grid {
	char edge; //Caractère représentant les bordure
	Case** m_board; //m_board est une matrice de Case
	Wave* _vectorEnnemies[NBPLAYER]; //Liste de wave
	std::vector<Tower*> _vectorTowers[NBPLAYER]; //Liste des tourelles
	Case** _path;  //Matrice avec les 4 paths
	bool _empty;  //Y a t-il des ennemis présents ?
	int* _nbTowers;
	int* _score;
	int* _money;
	int* _health;

public:
	Grid(){
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

	~Grid(){} //TODO


	inline bool isEmpty()const{return _empty;}
	inline bool isTower()const{
		for (unsigned int i = 0; i < NBPLAYER; ++i)
			if (_nbTowers[i] > 0) return true;
		return false;
	}


	void print_grid(){
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
		for (int i = 0; i<taille; ++i){
			for (int j = 0; j < taille; ++j){
				m_board[i][j].print();
			}					
		}
		//Dessine le tableau d'information
		move(SCORE_Y, SCORE_X*2 + 10);
		addstr("Score");
		move(SCORE_Y, SCORE_X*2 + 20);
		addstr("Money");
		move(SCORE_Y, SCORE_X*2 + 30);
		addstr("Health");
		for (int i = 0; i < NBPLAYER; ++i){
			move(SCORE_Y+1+i, SCORE_X*2);
			addstr("player");
			move(SCORE_Y+1+i, SCORE_X*2 + 10);
			addch('0');
			move(SCORE_Y+1+i, SCORE_X*2 + 20);
			addstr("300");
			move(SCORE_Y+1+i, SCORE_X*2 + 30);
			addstr("9");
		}
	}

	void make_path(){
		/*
		 * Créer le path.
		 * TODO : Fonction à refaire plus proprement.
		 * Idée : Lire un fichier contenant le path, et le créer à partir de celui-ci
		 */
		_path = new Case*[NBPLAYER];
		for (int k = 0; k < NBPLAYER; ++k){
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

	void createEnnemies(int nb, int a = 0){
		/*
		 * 'a', 'b' et 'c' représente le type d'ennemis 'a', 'b' et 'c' à créer
		 * dans la wave. -> Pas propre
		 * TODO : Refaire la fonction. 
		 * Idée : Ici aussi, lire dans fichier contenant les vagues successives d'ennemis
		 */
		for (int i = 0; i < NBPLAYER; ++i)
			_vectorEnnemies[i] = new Wave(_path[i], nb, a);
		_empty = false;
	}

	void moveAllEnnemies(){
		int score;
		for (int i = 0; i < NBPLAYER; ++i){;
			for (int j = 0; j < _vectorEnnemies[i]->get_size(); ++j){
				struct Coord temp = _vectorEnnemies[i]->get_ennemy(j)->get_coord();
				if (temp._x >= 0 && temp._y >=0) m_board[temp._x][temp._y].set_state(false);
			}
			score = _vectorEnnemies[i]->moveWaveEnnemies();
			_score[i] += score;
			_money[i] += 100*score;
			move(SCORE_Y+1+i, SCORE_X*2 + 10);
			printw("%d", _score[i]);
			move(SCORE_Y+1+i, SCORE_X*2 + 20);
			printw("%d", _money[i]);
			for (int k = 0; k < _vectorEnnemies[i]->get_size(); ++k){
				struct Coord temp = _vectorEnnemies[i]->get_ennemy(k)->get_coord();
				if (temp._x >= 0 && temp._y >=0) m_board[temp._x][temp._y].set_state(true);
			}
		}
		_empty = true;
		for (int i = 0; i < NBPLAYER; ++i)
			if (_vectorEnnemies[i]->get_size() != 0) _empty = false;
	}

	bool addTower(int x, int y){
		/* Ajoute une tourelle sur le board.
		 * TODO : Fonction non complete : Vérifier qu'on est bel et bien sur un '#'
		 * avant de créer la tourelle 
		 */
		int player;
		if (x >= 1 && x <= 15 && y >= 1 && y <= 15*2) player = 0;
		else if (x <= 29 && x >= 15 && y >= 1 && y <= 15*2) player = 1;
		else if (x <= 29 && x >= 15 && y <= 29*2 && y >= 15*2) player = 3;
		else if (x >= 1 && x <= 15 && y <= 29*2 && y >= 15*2) player = 2;
		else return false;

		if(_money[player] < 200) return false; //TODO
		_money[player] -= 200;
		move(SCORE_Y+1+player, SCORE_X*2 + 20);
		printw("%d", _money[player]);
		_nbTowers[player] += 1;
		struct Coord temp;
		temp._x = x-1; temp._y = y/2; //Coord interface -> Coord réelles
		_vectorTowers[player].push_back(new BasicTower(temp));
		return true;
	}

	void makeTowersAttack(){
		struct Coord temp;
		for (int i = 0; i < NBPLAYER; ++i){
			for (int j = 0; j < _nbTowers[i]; ++j){
				temp = _vectorTowers[i][j]->get_coord();
				findEnnemies(_vectorTowers[i][j], temp, i);
				_vectorTowers[i][j]->attack(); 
				_vectorTowers[i][j]->clear();
			}
		}
	}

	void findEnnemies(Tower* tower, Coord temp, int player){
		for (int i = temp._x - tower->get_range(); i < temp._x + tower->get_range(); ++i){
			for (int j = temp._y - tower->get_range(); j < temp._y + tower->get_range(); ++j){ 
				if (m_board[i][j].get_type()){
					struct Coord temp = Coord(i, j);
					tower->pushEnnemy(_vectorEnnemies[player]->getEnnemy(temp));
				}					
			}
		}
	}
};

#endif
