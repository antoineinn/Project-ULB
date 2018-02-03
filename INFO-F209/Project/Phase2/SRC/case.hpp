//#include <iostream>
#include "coord.hpp"

#ifndef CASE_HPP
#define CASE_HPP

class Case {
	friend class Grid;

	enum Type {path, field};          //Une case fait partie du chemin ou non
	enum State {occupied, freecase};  //Une case est occuppee ou non

	Type m_type;
	State m_state; 
	Coord m_coord; //Coordonnee de la case
	char c_field, c_path; //Path = ' ', field = '#'

public:

	Case(Coord coord) : m_type(field), m_state(freecase), m_coord(coord), c_field('#'), c_path(' '){}

	Case() : m_type(field), m_state(freecase), c_field('#'), c_path(' '){
		struct Coord temp;
		temp._x = 0; temp._y = 0;
		m_coord = temp;
	}

	void set_path(bool type){if (type) this->m_type = path; else this->m_type = field;}
	void set_state(bool state){if (state) this->m_state = occupied; else this->m_state = freecase;}
	inline bool get_type()const{if (this->m_state == occupied) return true; else return false;}
	inline Coord get_coord()const{return m_coord;}

	void print(){
		move(m_coord._x+1, m_coord._y*2+1);
		//Avec les bordures et les espaces, il est nécessaire de calculer la place
		//effective du carractère représentant la case
		if (m_type == field) addch(c_field);
		else addch(c_path);
		addch(' ');
	}

};

#endif
