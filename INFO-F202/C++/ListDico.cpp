//Antoine Innocent BA2 Informatique
//Matricule: 000394700

#include "ListDico.hpp"



void ListDico::insert(std::string s){
    List::insert(s);
    
}

void ListDico::erase(std::string s){
    List::erase(s);
    
}
void ListDico::search(std::string s){
    List::search(s);
    
}

void ListDico::mergeDict(Dictionary &t){ //Used for merging dictionary on left side
    
    List<std::string>:: Place curr;
    curr=begin();
    while(curr!=this->end()){
        t.insert(*curr);
        curr++;
        
    }
    
}

void ListDico::mergeVector(VectorDico &v){ //Used for merging vectorDico on left side
    
    List<std::string>:: Place curr;
    curr=begin();
    while(curr!=this->end()){
        v.insert(*curr);
        curr++;
        
    }
    
    
    
}


