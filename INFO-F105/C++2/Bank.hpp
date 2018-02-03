// Antoine Innocent Projet C++: ADT
#include <iostream>
#include <string>
using namespace std;

class Bank{
private:
		class _Account{
		public:
		
		_Account(string name, float value){
			_client=name;
			_balance= value;
			_next=nullptr;} // Initialise next as Null
		
		
		string get_client(){
			return _client;}

		
		void set_client(string newclient){
			_client=newclient;}

		float get_balance(){
			return _balance;}


		void set_balance(float newbalance){
			_balance=newbalance;}
		
		_Account* get_next(){	// Returns the next account in the chain list
			return _next;}

		void set_next(_Account *newnext){
			_next=newnext;}

		private:
		string _client;
		float _balance;
		_Account *_next;};
	
	_Account *_head;

public:
	Bank() : _head(nullptr) {}; // Initialise head as Null
	
	float withdraw(string _owner , float money ){
		
		_Account *curr=accountexist(_owner); 
		
		if (curr!=nullptr){	// If the account exists
			if (money<=curr->get_balance()){	// Case if the amount to withdraw is inferior to the balance (Correct)
				curr->set_balance(curr->get_balance()-money);
				
				 return money;}
			else{	
				std::cout<<"DENIED OPERATION! --> Not enough money to withdraw."<<std::endl;
				return -1;}}}
				

	

	void createAccount(string _client, float money){
		
		if (money<0){
			std::cout<< "ERROR: Can’t create account with balance<=0"<<std::endl;}
		
		
		else if(_client.length()==0){	// Check to see if the length of the given string is not 0
			std::cout<< "ERROR: Can’t create account without name"<<std::endl;}

		else if (_head!= nullptr){	// If list not empty
			bool stop= true;
			_Account *curr=_head;
			_Account *temp;
			
			while (curr!= nullptr and stop==true) {
				if (curr->get_client()==_client){
					std::cout<<"DENIED OPERATION! --> "+curr->get_client()+"’s account already exists."<<std::endl;
					stop=false;}

				
				else if (curr->get_next()== nullptr){
					temp=curr;}	// Saves the current element 

	
				curr=curr->get_next();}
			
			if (stop==true){
				
				temp->set_next(new _Account(_client,money));}}	// Create the new Account after the last element
		
		else{	// List empty
			
			_head=new _Account(_client,money);}}	// Create the new Account as head of list

	
	_Account* accountexist(string name){
		
		/**
			Checks in the list for the account corresponding to the given 
			name.
			If found , return it. If not return Null.
		*/

		if (_head==nullptr){
			return NULL;}
		else{
			_Account *curr=_head;
			while (curr!= nullptr) {
				if (curr->get_client()==name){ // If the account's name is the given string
					return curr;}
				
				curr=curr->get_next();}}
		
		return NULL;}
	

	float deleteAccount(string _client){
		bool stop= false;
		float res;
		_Account *curr=_head;
		_Account *previous;

		if (_head==nullptr){
			std::cout<<"ERROR: Account doesn't exist."<<std::endl;
			return -1;}
		
		else if (_head->get_client()==_client){	// If the head is the account to delete
					
					
					previous=nullptr;
					stop=true;
					res=_head->get_balance();}


		
		else{
			while (curr->get_next()!= nullptr and stop==false){
					
					
					if (curr->get_next()->get_client()==_client){
						
						previous=curr;
						stop=true;
						res=curr->get_next()->get_balance();}
		
				
				curr=curr->get_next();}}

		
		
		if (stop==true){
			
			if (previous!=nullptr){

				previous->set_next(curr->get_next());	
				delete curr;}	// Delete the object

			else{
				_head= curr->get_next();
				delete curr;}}	// Delete the object
		else{
			std::cout<<"ERROR: Account doesn't exist."<<std::endl;
			return -1;}
	return res;}


	



	float deposit(string owner, float money){
		_Account *curr=accountexist(owner);	// If the account exists
		
		if (curr!=nullptr){
			if (money>0){
				curr->set_balance(curr->get_balance()+money);
				
				 return curr->get_balance();}
			else{
				std::cout<<"ERROR : Not enough money on the account."<<std::endl;
				return -1 ;}}}


	
	void mergeAccounts(string _client1, string _client2 ){

		_Account *user1=accountexist(_client1);
		_Account *user2=accountexist(_client2);
		string newname;
		float newbalance;
		
		if (user1!=nullptr and user2!=nullptr){
			newname=user1->get_client()+" and "+user2->get_client();
			newbalance=user1->get_balance()+user2->get_balance();
			deleteAccount(_client1);
			deleteAccount(_client2);
			createAccount(newname,newbalance);}

		else{
			std::cout<<"ERROR : Non-existent account given."<<std::endl;}}
	
	void displayAccounts(){


		 if (_head!= nullptr){
			bool stop= true;
			_Account *curr=_head;
			while (curr!= nullptr){
					
				std::cout<<"Name : "<< curr->get_client();
				std::cout<<" | Balance : "<< curr->get_balance()<<std::endl;
					
				
				curr=curr->get_next();}}}
};
