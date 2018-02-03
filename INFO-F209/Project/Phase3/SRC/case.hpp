#ifndef CASE_HPP
#define CASE_HPP
#include <ncurses.h>
#include "coord.hpp"


class Case {
private:
	friend class Grid;

	enum Type {path, field};          // A case is or is not part of the path
	enum State {occupied, freecase};  // A case is occupied or not

	Type m_type;
	State m_state; 
	Coord m_coord; // Coordinates of the case
	char c_field, c_path; // Path = ' ', field = '#'

public:
	// constructors
	Case(Coord coord);
	Case();
	// getters & setters
	inline void set_path(bool type){if (type) this->m_type = path; else this->m_type = field;}
	inline void set_state(bool state){if (state) this->m_state = occupied; else this->m_state = freecase;}
	inline bool get_type()const{if (this->m_state == occupied) return true; else return false;}
	inline Coord get_coord()const{return m_coord;}
	// function
	void print();
};

#endif
