//Antoine Innocent BA2 Informatique
//Matricule: 000394700


#include "ListDico.hpp"
#include "TrieDico.hpp"
#include "VectorDico.hpp"

int main()
{
    ListDico myList;
    myList.insert("Hello");
    myList.insert("Goodbye");
    myList.insert("Sunset");
    
    std::cout<<"Dictionary in linked list format: "<<std::endl;
    print(myList);
    std::cout<<"//////////////////////"<<std::endl;
    
    myList.erase("Sunset");
    
    std::cout<<"Linked list after erase: "<<std::endl;
    print(myList);;
    std::cout<<"//////////////////////"<<std::endl;
    
    
    
    TrieDico myTree;
    myTree.insert("Lord");
    myTree.insert("of");
    myTree.insert("the");
    myTree.insert("rings");
    
    
    std::cout<<"Dictionary in Tree format: "<<std::endl;
    myTree.print();
    std::cout<<"//////////////////////"<<std::endl;
   
    myTree.erase("ringo");
    myTree.erase("rings");
    
    std::cout<<"Tree after erase "<<std::endl;
    myTree.print();
    std::cout<<"//////////////////////"<<std::endl;
    
    
    
    VectorDico myVector;
    myVector.insert("Harry");
    myVector.insert("Ron");
    myVector.insert("Hermione");
    myVector.insert("Frodo");
    
    std::cout<<"Dictionary in Vector format: "<<std::endl;
    myVector.print();
    std::cout<<"//////////////////////"<<std::endl;
    
    myVector.erase("Frodo");
    
    std::cout<<"Vector after erase: "<<std::endl;
    myVector.print();
    std::cout<<"//////////////////////"<<std::endl;
    
    
    
    myList+=myTree;
    std::cout<<"myList+=myTree: "<<std::endl;
    print(myList);;
    std::cout<<"//////////////////////"<<std::endl;
    
    myTree+=myVector;
    std::cout<<"myTree+=myVector: "<<std::endl;
    myTree.print();
    std::cout<<"//////////////////////"<<std::endl;
    
    
    
    TrieDico myTree2;
    myTree2.insert("cooool");
    
    std::cout<<"myTree2: "<<std::endl;
    myTree2.print();
    std::cout<<"//////////////////////"<<std::endl;
    
    
    
    
    myVector+=myTree2;  
    std::cout<<"myVector+=myTree2: "<<std::endl;
    myVector.print();
    std::cout<<"//////////////////////"<<std::endl;
    
    }

   