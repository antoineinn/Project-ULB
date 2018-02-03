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
  /* ... À completer ... */  
  for(unsigned int i=0; i<WORLD_SIZE; i++){
    /* ... À completer ... */	
  }

}

