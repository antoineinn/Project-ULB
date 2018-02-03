#ifndef RANKING_CPP
#define RANKING_CPP
#include <string>
#include <fstream>
#include <iostream>

class Ranking{
public:
	// constructors
	Ranking() = default;
	~Ranking();
	// getter
	const char* get_highscore();
	// functions
	void init(const std::string& filename);
	void update_ranking(const std::string& username, const int score);
	void update_file();

private:
	const int nbr_highscore = 10;
	const std::string _delimiter = " ";
	int* top_highscore;
	std::string _filename;
	std::string* top_username;
	// function
	void read_file();
};

#endif
