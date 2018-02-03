//Antoine Innocent BA2 Informatique
//Matricule: 000394700


#ifndef TRIEDICO_HPP
#define TRIEDICO_HPP

#include "Trie.hpp"
#include "string"
#include "Dictionary.hpp"
#include "ListDico.hpp"



class ListDico;
class TrieDico:public Trie, public Dictionary

{
    public:
        virtual void insert(std::string s);
        virtual void erase(std::string s);
        virtual void search(std::string s) ;
        virtual void mergeDict(Dictionary &t);
        virtual void mergeVector(VectorDico&);
        virtual void merge(Trie::Node*,Dictionary &t,std::string="")const;
        virtual void mergeVect(Trie::Node*,VectorDico &t,std::string="")const;
        virtual ~TrieDico()= default;  
    
};
























#endif /* TRIEDICO_HPP */

