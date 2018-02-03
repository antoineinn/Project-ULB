#include "case.hpp"

/* PUBLIC */

// Constructors

Case::Case(Coord coord) : m_type(field), m_state(freecase), m_coord(coord), c_field('#'), c_path(' '){}

Case::Case() : m_type(field), m_state(freecase), c_field('#'), c_path(' '){
	struct Coord temp;
	temp._x = 0; temp._y = 0;
	m_coord = temp;
}

// Function

void Case::print(){
	move(m_coord._x+1, m_coord._y*2+1);
	// With the border and the spaces, it is necessary to calcul the space necessary
	// of the character representing the case
	if (m_type == field) addch(c_field);
	else addch(c_path);
	addch(' ');
}
