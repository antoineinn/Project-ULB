// Antoine INNOCENT Projet C++ : ADT
#include "Bank.hpp"
int main(){
	Bank b;
	float balance;
	std::cout << "Create Tom’s account with 10.000$"<<std::endl;
	b.createAccount("Tom", 10000);
	std::cout << "Create Dick’s account with 20.000$"<<std::endl;
	b.createAccount("Dick", 20000);
	std::cout << "Create Harry’s account with 30.000$"<<std::endl;
	b.createAccount("Harry", 30000);
	std::cout << "Create Tom’s account with 15.000$"<<std::endl;
	b.createAccount("Tom",15000);
	std::cout << "Create Bill’s account with -20000$"<<std::endl;
	b.createAccount("Bill",-20000);
	std::cout << "Print list of accounts:"<<std::endl;
	b.displayAccounts();
	std::cout << "withdraw 5.000$ from Tom’s account."<<std::endl;
	b.withdraw("Tom",5000);
	std::cout << "withdraw 11.000$ from Dick’s account."<<std::endl;
	b.withdraw("Dick",11000);
	std::cout << "withdraw 21.300$ from Dick’s account."<<std::endl;
	b.withdraw("Dick",21300);
	std::cout << "Print list of accounts:"<<std::endl;
	b.displayAccounts();
	std::cout << "Close Dick’s account."<<std::endl;
	balance=b.deleteAccount("Dick");
	std::cout << "Dick’s account closed. He took "<<balance<< "$."<<std::endl;
	std::cout << "Merge Tom and Harry’s accounts"<<std::endl;
	b.mergeAccounts("Tom","Harry");
	std::cout << "Print list of accounts:"<<std::endl;
	b.displayAccounts();
	return 0;
}
