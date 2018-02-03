//Antoine Innocent BA2 Informatique
//Matricule: 000394700

#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#include "VectorDico.hpp"

 
class Dictionary

{
public:
    virtual void insert(std::string)=0;
    virtual void erase(std::string)=0;
    virtual void search(std::string)=0;
    virtual void mergeDict(Dictionary &t)=0;
    virtual void mergeVector(VectorDico&)=0;
    
    friend Dictionary& operator+=(Dictionary& dico1,Dictionary& dico2){ //Operator for dictionary fusion
        dico2.mergeDict(dico1);   
    }
   
   Dictionary& operator+=(VectorDico& vDico){ //operator for Dictionary+=VectorDico

       for (int i=0; i<vDico.getVector().size();i++){
            this->insert(vDico.getVector()[i]);        
        }}
   
   friend VectorDico& operator+=(VectorDico& vecDico,Dictionary& dico1){ //operator for VectorDico+=Dictionary
       dico1.mergeVector(vecDico);}
        
    
    
 


    
    
    
    
    
};











#endif /* DICTIONARY_HPP */

