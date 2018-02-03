#ifndef FRIEND_HPP
#define FRIEND_HPP
#include <string>

class Friend{
public:
	// constructor
    Friend(int, std::string);
    ~Friend();
	// function
    void menuInit();

private:
    int sockfd;
    std::string username;
    bool exit = false;
	// functions
    int displayOptionChoice();
    void addFriend();
    void deleteFriend();
    void showFriend();
    bool isValid(int, int, int);
    void acceptAddFriendAsk();
};

#endif //FRIEND_HPP




