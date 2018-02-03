#ifndef RANKING_CPP
#define RANKING_CPP
#include<string>
#include<fstream>

class Ranking{
public:
	void init();
	void update_ranking(const std::string& username, const int score);
	void update_file();
	std::string get_highscore();
	~Ranking();
	
private:
	const int nbr_highscore = 10;
	const std::string _delimiter = " ";
	int* top_highscore;
	std::string* top_username;
	void read_file();
	bool search(const std::string& user);

};

#endif
