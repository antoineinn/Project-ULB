//#include <iostream>
#include "case.hpp"
//#include "grid.hpp"

#ifndef ENNEMY_HPP
#define ENNEMY_HPP

class Ennemy{
public:
	Ennemy() = default;
	Ennemy(const Ennemy&) = default;
	virtual ~Ennemy() = default;
	virtual void attack() = 0;
	virtual int goForward() = 0;
	virtual Coord get_coord()const = 0;
	virtual int get_score()const = 0;
	virtual void hit(int) = 0;
};

class TypicalVegan : public Ennemy{

	char _foo;
	int  _health, _indice, _score;
	Coord _coord;
	Case* _path;

public:

	TypicalVegan(Case path[]) : _foo('o'), _health(3), _indice(-1), _score(1), _coord(Coord()), _path(path){}

	~TypicalVegan() = default;

	inline Coord get_coord()const{return this->_coord;}

	inline int get_score()const{return this->_score;}

	int goForward(){
		/*
		 * Return true s'il faut détruire l'ennemi
		 */
		int result;
		if (_health > 0){
			//S'il est en vie
			if (_indice < 24){
				//Si l'ennemi n'est pas en fin de chemin
				move(_coord._x+1, _coord._y*2+1);
				addch(' '); refresh();
				_coord = _path[_indice+1].get_coord();
				move(_coord._x+1, _coord._y*2+1);
				addch(_foo); refresh();
				//std::cout<<'('<<_coord._x<<", "<<_coord._y<<')';
				_indice += 1;
				result = 0;
			}
			else if (_indice == 24){
				//Si il l'est
				_path[_indice].set_state(false);
				move(_coord._x+1, _coord._y*2+1);
				addch(' '); refresh();
				attack();
				result = _indice; 
			}
		}
		else{
			//S'il est mort
			move(_coord._x+1, _coord._y*2+1);
			addch(' '); refresh();
			result = _indice;
		}
		return result;
	}

	void attack(){
		// TODO : L'ennemi enlève des hp au joueur s'il a passé tout le path
	}

	void hit(int damage){
		this->_health -= damage;
		attron(COLOR_PAIR(1));
		move(_coord._x+1, _coord._y*2+1);
		addch(_foo); refresh();
		attroff(COLOR_PAIR(1));
	}
};

//class SpeedyVegan : public Ennemy{};

#endif
