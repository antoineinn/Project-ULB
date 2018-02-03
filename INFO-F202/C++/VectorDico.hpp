//Antoine Innocent BA2 Informatique
//Matricule: 000394700



#include "vector"
#include "string"
#include "Dictionary.hpp"
#ifndef VECTORDICO_HPP
#define VECTORDICO_HPP

class Dictionary;
class VectorDico {

    
private:
    std::vector<std::string> vector;
    
public:
    VectorDico()=default;
    ~VectorDico()=default;
    void insert(std::string);
    void erase(std::string);
    int search(std::string);
    void mergeDict(Dictionary &t)const;
    void print();
    
    std::vector<std::string> getVector()const;
    VectorDico(const VectorDico &other);    //Copy constructor

    
    
    
};
    
    
    
    
    
    
    
    
    
    
    
    














#endif /* VECTORDICO_HPP */

