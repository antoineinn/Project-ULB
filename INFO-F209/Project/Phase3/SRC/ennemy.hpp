#ifndef ENNEMY_HPP
#define ENNEMY_HPP
#include <ncurses.h>
#include "case.hpp"


class Ennemy{ // virtual pure
public:
	// constructors
	Ennemy() = default;
	Ennemy(const Ennemy&) = default;
	virtual ~Ennemy() = default;
	// getters
	virtual Coord get_coord()const = 0;
	virtual int get_score()const = 0;
	virtual int get_attack()const = 0;
	// functions
	virtual void attack() = 0;
	virtual int goForward() = 0;
	virtual void hit(int) = 0;
};

class TypicalVegan : public Ennemy{
private:
	char _foo;
	int  _health, _indice, _score, _attack;
	Coord _coord;
	Case* _path;

public:
	// constructors
	TypicalVegan(Case path[]);
	~TypicalVegan() = default;
	// getters
	inline Coord get_coord()const{return this->_coord;}
	inline int get_score()const{return this->_score;}
	inline int get_attack()const{return this->_attack;}
	int goForward();
	void hit(int damage);
	void attack(){}// TODO : L'ennemi enlève des hp au joueur s'il a passé tout le path
};

class HardVegan : public Ennemy{
private:
	char _foo;
	int  _health, _indice, _score,_attack;
	Coord _coord;
	Case* _path;

public:
	// constructors
	HardVegan(Case path[]);
	~HardVegan() = default;
	// getters
	inline Coord get_coord()const{return this->_coord;}
	inline int get_score()const{return this->_score;}
	inline int get_attack()const{return this->_attack;}
	// functions
	int goForward();
	void hit(int damage);
	void attack(){}// TODO : L'ennemi enlève des hp au joueur s'il a passé tout le path
};


class DamageVegan : public Ennemy{
private:
	char _foo;
	int  _health, _indice, _score,_attack;
	Coord _coord;
	Case* _path;

public:
	// constructors
	DamageVegan(Case path[]);
	~DamageVegan() = default;
	// getters
	inline Coord get_coord()const{return this->_coord;}
	inline int get_score()const{return this->_score;}
	inline int get_attack()const{return this->_attack;}
	// functions
	int goForward();
	void hit(int damage);
	void attack(){}// TODO : L'ennemi enlève des hp au joueur s'il a passé tout le path
};



#endif
