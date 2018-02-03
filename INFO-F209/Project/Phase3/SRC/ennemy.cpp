#include "ennemy.hpp"


TypicalVegan::TypicalVegan(Case path[]) : _foo('o'), _health(3), _indice(-1), _score(1), _attack(1), _coord(Coord()), _path(path){}

int TypicalVegan::goForward(){
	/* Return true if we need to kill an enemy */
	int result = 0;
	if (_health > 0){ // If he's alive
		if (_indice < 24){ // If the enemy is not at the end of his path
			move(_coord._x+1, _coord._y*2+1);
			addch(' '); refresh();
			_coord = _path[_indice+1].get_coord();
			move(_coord._x+1, _coord._y*2+1);
			addch(_foo); refresh();
			//std::cout<<'('<<_coord._x<<", "<<_coord._y<<')';
			_indice += 1;
			result = 0;
		}
		else if (_indice == 24){ // If he is at the end of his path
			_path[_indice].set_state(false);
			move(_coord._x+1, _coord._y*2+1);
			addch(' '); refresh();
			attack();
			result = _indice; 
		}
	}
	else{ // If he's dead
		move(_coord._x+1, _coord._y*2+1);
		addch(' '); refresh();
		result = _indice;
	}
	return result;
}

void TypicalVegan::hit(int damage){
	this->_health -= damage;
	attron(COLOR_PAIR(1));
	move(_coord._x+1, _coord._y*2+1);
	addch(_foo); refresh();
	attroff(COLOR_PAIR(1));
}

HardVegan::HardVegan(Case path[]) : _foo('~'), _health(6), _indice(-1), _score(2),_attack(1), _coord(Coord()), _path(path){}

int HardVegan::goForward(){
	/* Return true if we need to kill an enemy */
	int result=0;
	if (_health > 0){ // If he's alive
		if (_indice < 24){ // If the enemy is not at the end of his path
			move(_coord._x+1, _coord._y*2+1);
			addch(' '); refresh();
			_coord = _path[_indice+1].get_coord();
			move(_coord._x+1, _coord._y*2+1);
			addch(_foo); refresh();
			//std::cout<<'('<<_coord._x<<", "<<_coord._y<<')';
			_indice += 1;
			result = 0;
		}
		else if (_indice == 24){ // If he is at the end of his path
			_path[_indice].set_state(false);
			move(_coord._x+1, _coord._y*2+1);
			addch(' '); refresh();
			attack();
			result = _indice; 
		}
	}
	else{ // if he's dead
		move(_coord._x+1, _coord._y*2+1);
		addch(' '); refresh();
		result = _indice;
	}
	return result;
}

void HardVegan::hit(int damage){
	this->_health -= damage;
	attron(COLOR_PAIR(1));
	move(_coord._x+1, _coord._y*2+1);
	addch(_foo); refresh();
	attroff(COLOR_PAIR(1));
}

DamageVegan::DamageVegan(Case path[]) : _foo('%'), _health(3), _indice(-1), _score(2),_attack(3), _coord(Coord()), _path(path){}

int DamageVegan::goForward(){
	/* Return true if we need to kill an enemy */
	int result =0;
	if (_health > 0){ // If he's alive
		if (_indice < 24){ // If the enemy is not at the end of his path
			move(_coord._x+1, _coord._y*2+1);
			addch(' '); refresh();
			_coord = _path[_indice+1].get_coord();
			move(_coord._x+1, _coord._y*2+1);
			addch(_foo); refresh();
			//std::cout<<'('<<_coord._x<<", "<<_coord._y<<')';
			_indice += 1;
			result = 0;
		}
		else if (_indice == 24){ // If he is at the end of his path
			_path[_indice].set_state(false);
			move(_coord._x+1, _coord._y*2+1);
			addch(' '); refresh();
			attack();
			result = _indice; 
		}
	}
	else{ // if he's dead
		move(_coord._x+1, _coord._y*2+1);
		addch(' '); refresh();
		result = _indice;
	}
	return result;
}

void DamageVegan::hit(int damage){
	this->_health -= damage;
	attron(COLOR_PAIR(1));
	move(_coord._x+1, _coord._y*2+1);
	addch(_foo); refresh();
	attroff(COLOR_PAIR(1));
}
