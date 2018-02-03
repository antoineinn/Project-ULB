#include <iostream>
#include <iomanip>

#define ALIVE_CELL_SYM "\u25A0"
#define DEAD_CELL_SYM "\u25A1"

void simulation_step(unsigned char[], unsigned char[]);
void print_world(unsigned char[]);
extern "C" {unsigned char simulation_cell(unsigned char,unsigned char,unsigned char,unsigned char[],unsigned char);}


const unsigned char RULE_SIZE=8;
const unsigned int WORLD_SIZE=8;

int main(int argc, char** argv){
  unsigned char world[WORLD_SIZE] = {0,1,0,0,1,0,1,1};
  unsigned char rule[RULE_SIZE] = {1,0,0,1,0,0,1,0};
  unsigned int simulation_steps = 10;

  for(unsigned int i=0; i < simulation_steps; i++){
    print_world(world);
  	simulation_step(world,rule);
  }

} 


void print_world(unsigned char world[]){
  for(unsigned int i=0; i<WORLD_SIZE; i++){
	   std::cout << (world[i] ? ALIVE_CELL_SYM : DEAD_CELL_SYM);
  }
  std::cout << std::endl;
}

void simulation_step(unsigned char world[], unsigned char rule[]){
  
  
    unsigned char voisingauche;
    unsigned char voisindroit;
    unsigned char cell; 
    unsigned char newworld[WORLD_SIZE];
  
  for(unsigned int i=0; i<WORLD_SIZE; i++){

        if (i==0){

          voisingauche=world[i+WORLD_SIZE-1]; // Pour rendre circulaire 
          voisindroit=world[i+1];
          cell=world[i];
          } 
        else if (i==WORLD_SIZE-1) {

          voisindroit=world[i-WORLD_SIZE-1]; // rendre circulaire
          voisingauche=world[i-1];
          cell=world[i];
          }

        else {

          voisindroit=world[i+1]; 
          voisingauche=world[i-1];
          cell=world[i];
          }

        
        newworld[i]=simulation_cell(voisingauche,cell,voisindroit,rule,RULE_SIZE); // Resultat dans nouveau monde
  
  
        
    
    	
  }
  for (unsigned int i=0; i<WORLD_SIZE;i++){ // Copie du nouveau monde
    world[i]=newworld[i];
  }
}

