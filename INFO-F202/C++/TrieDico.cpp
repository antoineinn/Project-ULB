//Antoine Innocent BA2 Informatique
//Matricule: 000394700

#include "TrieDico.hpp"




void TrieDico::insert(std::string s){
    
    Trie::insert(s);
    
    
}


void TrieDico::erase(std::string s){
    
    Trie::erase(s);
    
    
}




void TrieDico::search(std::string s){
    
    Trie::search(s);
    
    
}


void TrieDico::mergeDict(Dictionary &t){
    merge(root,t);
    
    
}

void TrieDico::mergeVector(VectorDico& vDico){
    
    mergeVect(root,vDico);
    
    
}


void TrieDico::merge(Trie::Node* curr,Dictionary &t,std::string s)const{
    // Function used for merging two dictionary
    
    if(!curr){
        curr=root;
    }
    if(curr->getChaine()==1){
        t.insert(s);
    }
    if(curr->getSon()){
        merge(curr->getSon(),t, s + curr->getSon()->getData());
    }
    if(curr->getBrother()) {
        s.pop_back();
        merge(curr->getBrother(),t, s+curr->getBrother()->getData());
    }
    
    
}

void TrieDico::mergeVect(Trie::Node* curr,VectorDico &v,std::string s)const{
    // Function used for merging with vectorDico type
    
    if(!curr){
        curr=root;
    }
    if(curr->getChaine()==1){
        v.insert(s);
    }
    if(curr->getSon()){
        mergeVect(curr->getSon(),v, s + curr->getSon()->getData());
    }
    if(curr->getBrother()) {
        s.pop_back();
        mergeVect(curr->getBrother(),v, s+curr->getBrother()->getData());
    }
    
    
}

