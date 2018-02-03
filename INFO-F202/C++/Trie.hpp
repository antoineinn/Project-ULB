//Antoine Innocent BA2 Informatique
//Matricule: 000394700


#ifndef TRIE_H
#define TRIE_H
#include "string"
class Trie {
    
    
protected:
        class Node {
        private:
            Node *brother;
            Node *son;
            Node *parent;
            bool chaine;
            char data;
        public: 
            Node();
            Node(char& t,bool info);

            Node* getBrother();
            Node* getSon();
            Node* getParent();
            bool getChaine();
            char getData();
            void setChaine(bool newChaine);
            void setData (char newData);
            
            
            void setBrother(Node* newBrother);
            void setBrother(char newBrother, int chaine );


            void setParent(Node* father);
            void setSon(Node* newSon);
            void setSon(char newSon, int chaine ); 
        };
        Node *root;
        Node *current;
    public:
        
        
        
        
        
        Node* getRoot()const;
        Node* getCurrent();
        void setRoot(Node*);
        void insert(std::string);
        void printTree(Node* );
        void rootExchange(Trie,Trie);
        void merge(Node*,std::string="");
        Node* search(std::string);
        void erase(std::string);
        void deleteAll();
        
        void levelTraversal();
        void remove(std::string);
        void print(Node*ptr=nullptr,std::string="");

       
        
        
        Trie(){root=new Node();}
        ~Trie(){deleteAll(); delete root;}
        Trie(const Trie &tree);
        Trie& operator=(const Trie &tree);

        
        
        
      
};
 
    

       

#endif /* TRIE_H */