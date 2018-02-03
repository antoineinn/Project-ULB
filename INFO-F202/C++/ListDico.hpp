//Antoine Innocent BA2 Informatique
//Matricule: 000394700


#ifndef LISTDICO_HPP
#define LISTDICO_HPP

#include "string"
#include "List.hpp"
#include "Dictionary.hpp"
#include "TrieDico.hpp"


class TrieDico;
class ListDico:public List<std::string>,public Dictionary
{
    public:
        virtual void insert(std::string s);
        virtual void erase(std::string s);
        virtual void search(std::string s);
        virtual void mergeDict(Dictionary &t);
        virtual void mergeVector(VectorDico&);
        virtual ~ListDico()=default;

};









#endif /* LISTDICO_HPP */

