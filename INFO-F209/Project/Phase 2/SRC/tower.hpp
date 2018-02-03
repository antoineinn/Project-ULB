#include <iostream>
#include <vector>
#include "case.hpp"
#include "ennemy.hpp"

#ifndef TOWER_HPP
#define TOWER_HPP

class Tower {
protected:
	enum Focus {first, last, stronger};

public:
	Tower() = default;
	Tower(const Tower&) = default;
	virtual ~Tower() = default;

	virtual void attack() = 0;
	virtual Coord get_coord()const = 0;
	virtual int get_range()const = 0;
	virtual void pushEnnemy(Ennemy*) = 0;
	virtual void clear() = 0;

};


class BasicTower : public Tower {

	Coord _coord;
	char _foo;
	int  _damage, _range;
	bool _spread;
	Focus _focus;
	std::vector<Ennemy*> _reachable;

public:

	BasicTower(Coord coord) : _coord(coord), _foo('T'), _damage(1), _range(2), _spread(false), _focus(first){
		move(coord._x+1, coord._y*2+1);
		addch(_foo); refresh();
	}
	~BasicTower() = default;

	inline Coord get_coord()const{return this->_coord;}
	inline int get_range()const{return this->_range;}

	void pushEnnemy(Ennemy* unit){
		_reachable.push_back(unit);
	}

	void clear(){
		_reachable.clear();
	}

	void attack(){
		for (unsigned int i = 0; i < _reachable.size(); ++i){
			_reachable[_reachable.size()-1]->hit(_damage);
		}
	}
	
};

#endif
