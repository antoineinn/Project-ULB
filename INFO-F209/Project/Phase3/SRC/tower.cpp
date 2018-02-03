#include "tower.hpp"

/* PUBLIC */

// Constructor

BasicTower::BasicTower(Coord coord) : _coord(coord), _foo('T'), _damage(1), _range(2), _spread(false), _focus(first){
	move(coord._x+1, coord._y*2+1);
	addch(_foo); refresh();
}

// Functions

void BasicTower::pushEnnemy(Ennemy* unit){
	_reachable.push_back(unit);
}

void BasicTower::clear(){
	_reachable.clear();
}

void BasicTower::attack(){
	for (unsigned int i = 0; i < _reachable.size(); ++i){
		_reachable[_reachable.size()-1]->hit(_damage);
	}
}

// --------------------------------------------------------------------------

/* PUBLIC */

// Constructor

HeavyTower::HeavyTower(Coord coord) : _coord(coord), _foo('H'), _damage(2), _range(2), _spread(false), _focus(first){
    move(coord._x+1, coord._y*2+1);
    addch(_foo); refresh();
}

// Functions

void HeavyTower::pushEnnemy(Ennemy* unit){
    _reachable.push_back(unit);
}

void HeavyTower::clear(){
    _reachable.clear();
}

void HeavyTower::attack(){
    for (unsigned int i = 0; i < _reachable.size(); ++i){
        _reachable[_reachable.size()-1]->hit(_damage);
    }
}

// --------------------------------------------------------------------------

/* PUBLIC */

// Constructor

BombTower::BombTower(Coord coord) : _coord(coord), _foo('B'), _damage(5), _range(4), _spread(false), _focus(first){
    move(coord._x+1, coord._y*2+1);
    addch(_foo); refresh();
}

// Functions

void BombTower::pushEnnemy(Ennemy* unit){
    _reachable.push_back(unit);
}

void BombTower::dead(){
	_damage=0;
	_range=0;
	move(_coord._x+1, _coord._y*2+1);
	addch('x'); refresh();
}

void BombTower::clear(){
    _reachable.clear();
}

void BombTower::attack(){
    for (unsigned int i = 0; i < _reachable.size(); ++i){
        _reachable[_reachable.size()-1]->hit(_damage);
    }
}
