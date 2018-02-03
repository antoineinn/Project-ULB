//Antoine Innocent BA2 Informatique
//Matricule: 000394700



#include "VectorDico.hpp"
#include <iostream>  // cin, cout...




std::vector<std::string> VectorDico::getVector()const{
    return vector;   
}



VectorDico::VectorDico(const VectorDico &other){    
    //Used for merging vectors
    
    for (int i=0;i<other.vector.size();i++){
        
        insert(other.vector[i]);
        
        
        
    }
    
    
    
}



void VectorDico::insert(std::string s){
    // Insert string in lexicographical order

    if (vector.size()!=0){
        int i=0;
        while (i<vector.size() && s>vector[i]){
            i++;     
        }      
    
    
    vector.insert(vector.begin()+i,s);}
    
    else{
        vector.push_back(s); 
    }
}

void VectorDico::erase(std::string s){
    //Delete string from vector
    
    
    
    if (vector.size()!=0){
        int i=0;
        while (i<vector.size() && s!=vector[i]){    // Search for string
            i++;     
        }      
    
        if (i==vector.size()){ 
            
            std::cout<<"Word not in dictionary"<<std::endl;
        
        
        }
        else{
            vector.erase(vector.begin()+i); //delete element at index i
            
        }
    }
    
    else{
       std::cout<<"Dictionary empty"<<std::endl;
    }
    
    
}




int VectorDico::search(std::string s){
    // Search for string in vector
    // Returns index of word
    
    
    if (vector.size()!=0){
        int i=0;
        while (i<vector.size() && s!=vector[i]){
            i++;     
        }      
    
        if (i==vector.size()){ 
            
            std::cout<<"Word not in dictionary"<<std::endl;
        
        
        }
        else{
            std::cout<<"Word found at index "<<i<<std::endl;
            return i;
            
        }
    }
    
    else{
       std::cout<<"Dictionary empty"<<std::endl;
    }
    
    
    return 0;
    
    
}

void VectorDico::mergeDict(Dictionary& t) const{
    //merging with dictionary as left operand
    
    for (int i; i<vector.size();i++){
        t.insert(vector[i]);
        
        
    }
    
    
    
    
}

void VectorDico::print(){
    //Print vector 
    
    std::cout<<"[";
    for (int i=0;i<vector.size();i++){
        
        if (i==vector.size()-1){
            std::cout<<vector[i]<<"]"<<std::endl;;
            
        } 
        else{
            std::cout<<vector[i]<<",";
        }
    }
    
    
    
}



