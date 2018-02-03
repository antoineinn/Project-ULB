//Antoine Innocent BA2 Informatique
//Matricule: 000394700

#include "Trie.hpp"
#include "VectorDico.hpp"
#include <iostream>  



///////Constructor////////

Trie:: Trie(const Trie &other){
    root=new Node();
    merge(other.getRoot());    
    
}  

Trie::Node:: Node(){
     brother=nullptr;
     son=nullptr;
     parent=nullptr;
     chaine=false;
     data=0;  
}

Trie::Node::Node(char& t,bool info){
    brother=nullptr;
    son=nullptr;
    parent=nullptr;
    chaine=info;
    data=t;
}

/////////Getters and Setters////////////////

Trie::Node* Trie::Node::getBrother(){
    return brother;   
}

Trie::Node* Trie::Node::getSon(){
    return son;   
}

Trie::Node* Trie::Node::getParent(){
    return parent;   
}

bool Trie::Node::getChaine(){
    return chaine;   
}

char Trie::Node::getData(){
    return data;   
}


void Trie::Node::setChaine(bool newChaine){
    chaine=newChaine;
}

void Trie::Node::setData(char newData){
    data=newData;
}

void Trie::Node::setBrother(Node* newBrother){
    brother=newBrother;
}

void Trie::Node::setBrother(char newBrother,int chaine){
    brother=new Node(newBrother,chaine);
}

void Trie::Node::setParent(Node* father){
    parent=father;
}

void Trie::Node::setSon(Node* newSon){
    son=newSon;
}

void Trie::Node::setSon(char newSon,int chaine){
    
    son=new Node(newSon,chaine);
}


Trie::Node* Trie::getRoot()const {return root;}
Trie::Node* Trie::getCurrent(){return current;}

void Trie::setRoot(Node*newRoot){
    root=newRoot;
    
}



///////operator///////

Trie &Trie::operator=(const Trie& other){
    
    rootExchange(*this,other);   
}


void Trie:: rootExchange(Trie current,Trie other){
    //////Will exchange the root of both trees
    
    Node* temp;
    temp=other.getRoot();
    current.setRoot(temp);
    
}



void Trie::merge(Node* curr,std::string s){
    //Will merge with the curr 
    if(!curr){
        curr=root;
    }
    if(curr->getChaine()==1){
        this->insert(s);
    }
    if(curr->getSon()){
        print(curr->getSon(), s + curr->getSon()->getData());
    }
    if(curr->getBrother()) {
        s.pop_back();
        print(curr->getBrother(), s+curr->getBrother()->getData());
    }
    
    
}
            



void Trie::deleteAll()
{   /////Will the delete all the tree

    Node *curr=root;
    Node *par;
    while (curr){
        if (curr->getSon()){
            curr=curr->getSon();
            continue;
        }
        
            par=curr->getParent();
            
            if (par!=nullptr){

                par->setSon(nullptr); 

                
                
                }
            delete(curr);

            curr=par; 
            if (curr==root){
                break;
            }

        
    }
    
}
    


Trie::Node* Trie::search(std::string s){
    ///Will search for string s in the tree
    ///Returns last node
    
    Node* current=root->getSon();
    bool found=false;
    
    if (current==nullptr){  // Empty tree
        std::cout<<"Nothing in the tree"<<std::endl;
        return nullptr;
        
        
    }
    
    for (int i=0;i<s.length();i++){ // For every letter in word
        
        while (current->getData()!=s[i]){   // Look for letter in node
            current=current->getBrother();
            if (current==nullptr){
                std::cout<<"Not in the tree"<<std::endl;

                return nullptr;
            }
        }
                
  
        if (current->getSon()==nullptr && s[i]!=s.back()){

            std::cout<<"Not in the tree"<<std::endl;

            return nullptr;}
        

        
        if (current->getData()==s[i] && s[i]==s.back() && current->getChaine()==1){ //Condition for successful search
                found=true;
                std::cout<<"Word found"<<std::endl;
                return current;
        }
        current=current->getSon();
    }
    std::cout<<"Not in the tree"<<std::endl;

    return nullptr;
    
}


void Trie::erase(std::string strToDel){
    
    // Will erase the string in the tree
    // Uses the search function
    
    Node* toDel=search(strToDel); //node of last letter of word
    if (toDel!=nullptr){
        Node* temp;
        Node* temp2;  
        if (toDel->getSon()==nullptr){ 
            toDel->setChaine(0);
            temp=toDel->getParent();
            
            if (toDel->getBrother()!=nullptr){
                    temp->setSon(toDel->getBrother()); 
                }
                else{
                    
                    temp->setSon(nullptr);
                }
            
            delete toDel;
            // delete all unused letters from word 
            while (temp->getBrother()==nullptr and temp->getChaine()==0 and temp!=root){
                temp2=temp->getParent();
                if (temp->getBrother()!=nullptr){
                    temp2->setSon(temp->getBrother()); 
                }
                else{
                    
                    temp2->setSon(nullptr);
                }
                delete temp;


            } 
        }
        else{ //If is part of a word
            toDel->setChaine(0);

        }
        std::cout<<"Word erased"<<std::endl;
       
    }
    else{
        std::cout<<"Node not erased"<<std::endl;
    }



}







void Trie::insert(std::string s){
    //Insert string in tree
    

    Node *curr=root;
    Node *curr2=new Node(); // empty node
    for(int i=0;i<s.length();i++){
        // current has no child 

        if (curr->getSon()==nullptr){
 

            if (i==s.length()-1){
                curr2=new Node(s[i],1);    

            }
            else{
                curr2=new Node(s[i],0);   
            }
            curr2->setParent(curr);
            curr->setSon(curr2);
            curr=curr2;
        }
        
        else{

               if (curr->getSon()->getData()>s[i]){ //Curr is Youngerbrother                  
                   curr2=curr->getSon();
                   curr=new Node(s[i],0);
                  
                   
                   curr->setParent(curr2->getParent());
                   curr2->getParent()->setSon(curr);
                   curr->setBrother(curr2);
               }
               else if (curr->getSon()->getData()==s[i]){ //same letter
                   curr=curr->getSon();
                   if (s[i]==s.back()){    //last letter?

                       curr->getSon()->setChaine(1);
                       
                   }
               }
               
               else {   //Curr is older brother
                   bool flag=false;
                   if (curr->getSon()->getBrother()==nullptr){ //if no older brother

                       curr2=curr->getSon();
                       curr=new Node(s[i],0);
                       curr2->setBrother(curr);
                       curr->setParent(curr2->getParent());
                   }
                   else{ //already an older brother in place
                       curr2=curr->getSon();
                       while(flag!=true){ //iterate in tree
                           

                           if(curr2->getBrother()==nullptr){

                               curr=new Node(s[i],0);
                               curr2->setBrother(curr);
                               flag=true;          
                           }
                           else if (curr2->getBrother()->getData()>s[i]){

                               curr=new Node(s[i],0);
                               curr->setBrother(curr2->getBrother());//curr's brother is curr2's brother
                               curr2->setBrother(curr);
                               flag=true;              
                           }
                           else if (curr2->getBrother()->getData()==s[i]){
                               curr=curr2->getBrother();
                               flag=true;
                               
                           }
                           
                           curr2=curr2->getBrother(); // iterate      
                       }
                       
                       }
                   
                   
                   
                   }
                   
                   
               }
            if (i==s.length()-1){ // i is index of last letter
                curr->setChaine(1);
                
            }   
            
            
        }
}




void Trie::print(Node* curr, std::string s) {
    // Recursive print function
    
    if(!curr){
        curr=root;
    }
    if(curr->getChaine()==1){
        std::cout << s << std::endl;
    }
    if(curr->getSon()){
        print(curr->getSon(), s + curr->getSon()->getData());
    }
    if(curr->getBrother()) {
        s.pop_back();
        print(curr->getBrother(), s+curr->getBrother()->getData());
    }
}
    