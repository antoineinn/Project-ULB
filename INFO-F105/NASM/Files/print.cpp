#include <iostream>

extern "C" void printMessage(char* message, unsigned size){
	std::cout<<"Message size: "<<size<<std::endl;
	std::cout<<"Message:"<<std::endl<<"\"";
	for(unsigned i=0; i<size; i++){
		std::cout<<message[i];
	}
	std::cout<<"\""<<std::endl;
}



