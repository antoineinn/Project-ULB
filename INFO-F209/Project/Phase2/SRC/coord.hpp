//#include <iostream>

#ifndef COORD_HPP
#define COORD_HPP

struct Coord {
	int _x;
	int _y;

	Coord(int x, int y) : _x(x), _y(y){} 
	Coord() : _x(-1), _y(-1){}

	bool operator ==(const Coord& other){
		if (_x == other._x && _y == other._y)
			return true;
		return false;
	}

};

#endif
