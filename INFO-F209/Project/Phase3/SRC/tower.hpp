#ifndef TOWER_HPP
#define TOWER_HPP
#include <iostream>
#include <vector>

#include "case.hpp"
#include "ennemy.hpp"


class Tower {
protected:
	enum Focus {first, last, stronger};

public:
	// constructor
	Tower() = default;
	Tower(const Tower&) = default;
	virtual ~Tower() = default;
	// functions
	virtual void attack() = 0;
	virtual Coord get_coord()const = 0;
	virtual int get_range()const = 0;
	virtual void pushEnnemy(Ennemy*) = 0;
	virtual void clear() = 0;
};


class BasicTower : public Tower {
private:
	// functions
	Coord _coord;
	char _foo;
	int  _damage, _range;
	bool _spread;
	Focus _focus;
	std::vector<Ennemy*> _reachable;

public:
	// constructor
	BasicTower(Coord coord);
	~BasicTower() = default;
	// getters
	inline Coord get_coord()const{return this->_coord;}
	inline int get_range()const{return this->_range;}
	// functions
	void pushEnnemy(Ennemy* unit);
	void clear();
	void attack();
};

class HeavyTower : public Tower {
private:
	// functions
    Coord _coord;
    char _foo;
    int  _damage, _range;
    bool _spread;
    Focus _focus;
    std::vector<Ennemy*> _reachable;

public:
	// constructor
    HeavyTower(Coord coord);
    ~HeavyTower() = default;
	// getters
    inline Coord get_coord()const{return this->_coord;}
    inline int get_range()const{return this->_range;}
	// functions
    void pushEnnemy(Ennemy* unit);
    void clear();
    void attack();
};


class BombTower : public Tower {
private:
	// functions
    Coord _coord;
    char _foo;
    int  _damage, _range;
    bool _spread;
    Focus _focus;
    std::vector<Ennemy*> _reachable;

public:
	// constructors
    BombTower(Coord coord);
    ~BombTower() = default;
	// getters
    inline Coord get_coord()const{return this->_coord;}
    inline int get_range()const{return this->_range;}
	// functions
    void pushEnnemy(Ennemy* unit);
    void dead();
    void clear();
    void attack();
};

#endif
