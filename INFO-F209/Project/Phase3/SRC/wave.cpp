#include "wave.hpp"

/* PUBLIC */

// Constructor

Wave::Wave(Case path[], int nb, int a, int b, int c) : _nbEnnemies(nb) {
	for (int i = 0; i < a; ++i){
		Ennemy* temp = new TypicalVegan(path);
		_wave.push_back(temp);
	}	
	for (int i=0;i<b;++i){
		Ennemy* temp = new HardVegan(path);
		_wave.push_back(temp);
	}

	for (int i=0;i<c;++i){
		Ennemy* temp = new DamageVegan(path);
		_wave.push_back(temp);
	}		
}

// Functions

Ennemy* Wave::getEnnemy(Coord temp){
	for (int i = 0; i < _nbEnnemies; ++i){
		if (_wave[i]->get_coord() == temp)
			return _wave[i];
	}
	return nullptr;
}

int Wave::deleteEnnemy(int indice){
	int result = _wave[indice]->get_score();
	delete _wave[indice];
	_wave.erase(_wave.begin() + indice);
	_nbEnnemies -= 1;
	return result;
}

int Wave::moveWaveEnnemies(){
	/* 
	 * Waves starts at case (-1, -1), and progress in their designed path.
	 * When a wave begins, only the first enemy will be visible.
     * The other enemies will be waiting at case (-1, -1).
     * We test if the enemy who wants to move was at case (-1, -1) before.
     * If this is the case, the next enemy must not move forward but will wait
	 * for the next step.
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
		else if (toDelete == 24) {result-=_wave[i]->get_attack();deleteEnnemy(i);
		}
	}
	return result;
}
