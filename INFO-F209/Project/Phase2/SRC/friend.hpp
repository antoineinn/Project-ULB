#ifndef FRIEND_HPP
#define FRIEND_HPP
#include <string>
#include <list>

class Friend{
public:
	Friend(int, std::string);
	void menuInit();
	~Friend();

private:
	int sockfd;
	std::string username;
	bool exit = false;
	int displayOptionChoice();
	void addFriend();
	void deleteFriend();
	void showFriend();
	bool isValid(int, int, int);
	void acceptAddFriendAsk();
};

#endif //FRIEND_HPP
	
	
	


