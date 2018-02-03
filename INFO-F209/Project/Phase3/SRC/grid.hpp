#ifndef GRID_HPP
#define GRID_HPP
#include <ncurses.h>
#include <stack>
#include <map>
#include "coord.hpp"
#include "wave.hpp"
#include "case.hpp"
#include "tower.hpp"
static const int taille = 30;
static const int NB = 4;
static const int priceBasic = 100;
static const int priceHard = 200;
static const int priceBomb= 400;
#define SCORE_X 32
#define SCORE_Y 0

class Grid {
private:
	char edge; //Caractère représentant les bordure
	Case** m_board; //m_board est une matrice de Case
	Wave** _vectorEnnemies; //Liste de wave
	std::vector<Tower*> _vectorTowers[NB]; //Liste des tourelles
	std::stack<BombTower*> _bombTowers;
	std::map<int,const char*> map;
	Case** _path;  //Matrice avec les 4 paths
	bool _empty;  //Y a t-il des ennemis présents ?
	int* _nbTowers;
	int* _score;
	int* _money;
	int* _health;
	int _player;
	int _mode;
	int NBPLAYER, NBQUARTER;

public:
	//constructors
	Grid(int, int);
	Grid(){}
	~Grid(){} //TODO
	// setters & getters
	inline void set_player(int player){this->_player = player;}
	inline int get_health(int player)const{return _health[player];}
	inline void set_health(int player, int health){this->_health[player] = health;}
	inline int get_score(int player)const{return this->_score[player];}
	inline void add_money(){
		this->_money[_player] += 100;
		move(SCORE_Y+1+_player, SCORE_X*2 + 20); printw("%d", _money[_player]);
		refresh();
	}
	// functions
	inline bool isEmpty()const{return _empty;}
	bool isTower()const{
		for (int i = 0; i < NBPLAYER; ++i)
			if (_nbTowers[i] > 0) return true;
		return false;
	}
	void print_grid();
	void make_path();
	void createEnnemies(int nb, int a = 0, int b = 0, int c = 0);
	inline bool isBombtower() {return _bombTowers.empty();}
	void moveAllEnnemies();
	void printMessage(int message,int player, int mode);
	bool addTower(int x, int y, int c, int player, bool check = false);
	bool isAble(int quarter);
	void killAllBombs();
	void makeTowersAttack();
	void findEnnemies(Tower* tower, Coord temp, int player);
	bool isSomeoneDead(int player);
	void clearGrid(int player);
	bool isOver(int time);
};

#endif
