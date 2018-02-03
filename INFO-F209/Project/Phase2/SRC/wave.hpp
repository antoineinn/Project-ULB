//#include <iostream>
#include <vector>
#include "ennemy.hpp"
#include "coord.hpp"

#ifndef WAVE_HPP
#define WAVE_HPP

class Wave{

	int                  _nbEnnemies;
	std::vector<Ennemy*> _wave;

public:

	Wave() = delete;

	Wave(Case path[], int nb, int a = 0) : _nbEnnemies(nb) {
		for (int i = 0; i < a; ++i){
			Ennemy* temp = new TypicalVegan(path);
			_wave.push_back(temp);
		}			
	}

	~Wave(){} //TODO

	int deleteEnnemy(int indice){
		int result = _wave[indice]->get_score();
		delete _wave[indice];
		_wave.erase(_wave.begin() + indice);
		_nbEnnemies -= 1;
		return result;
	}

	inline int get_size()const{return _nbEnnemies;}

	Ennemy* getEnnemy(Coord temp){
		for (int i = 0; i < _nbEnnemies; ++i){
			if (_wave[i]->get_coord() == temp)
				return _wave[i];
		}
		return nullptr;
	}

	inline Ennemy* get_ennemy(int indice)const{return this->_wave[indice];}

	int moveWaveEnnemies(){
		/* 
		 * Les wave commencent à la case (-1, -1), et avancent dans leur path.
         * Lorsqu'une vague commence, seul le premier ennemis sera visible lors
         * de la première étape. Les autres seront toujours en (-1, -1)
         * C'est pourquoi on teste si l'ennemi qu'on bouge était avant cela en (-1, -1)
         * car si c'est le cas, l'ennemi suivant lui ne doit pas avancer mais attendra la prochaine étape.
		 */
		int result = 0;
		int toDelete = 0;
		for (int i = 0; i < _nbEnnemies; ++i){
			if (_wave[i]->get_coord() == Coord(-1, -1)){
				toDelete = _wave[i]->goForward();
				if (toDelete) deleteEnnemy(i);
				break;
			}
			toDelete = _wave[i]->goForward();
			if (toDelete >0 && toDelete < 24) result += deleteEnnemy(i);
			else if (toDelete == 24) result -= deleteEnnemy(i);
		}
		return result;
	}


};

#endif
