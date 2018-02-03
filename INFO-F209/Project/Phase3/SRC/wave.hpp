#ifndef WAVE_HPP
#define WAVE_HPP
#include <vector>
#include "ennemy.hpp"
#include "coord.hpp"


class Wave{
private:
	int _nbEnnemies;
	std::vector<Ennemy*> _wave;

public:
	// constructors
	Wave() = delete;
	Wave(Case path[], int nb, int a = 0, int b = 0, int c = 0);
	~Wave(){} //TODO
	// getters
	inline int get_size()const{return _nbEnnemies;}
	Ennemy* getEnnemy(Coord temp);
	inline Ennemy* get_ennemy(int indice)const{return this->_wave[indice];}
	// functions
	int deleteEnnemy(int indice);
	int moveWaveEnnemies();
};

#endif
