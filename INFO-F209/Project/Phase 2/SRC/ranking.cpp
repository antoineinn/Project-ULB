#include "ranking.hpp"

Ranking::~Ranking(){
	delete[] top_highscore;
	delete[] top_username;
}
void Ranking::init(){
	top_highscore = new int[nbr_highscore];
	top_username = new std::string[nbr_highscore];
	read_file();
}

void Ranking::read_file(){
	int i=0;
	std::string line;
	std::ifstream rank;	//read mode
	rank.open("ranking.txt");
	if(rank.is_open()){
		while(std::getline(rank, line)){
			size_t pos=0;
			std::string token;	//substring of line
			pos = line.find(_delimiter);	//find end of substring
    		token = line.substr(0, pos);
			top_highscore[i] = std::stoi (token);	//string to int
    		line.erase(0, pos + _delimiter.length());
			pos = line.find(_delimiter);
    		token = line.substr(0, pos);
			top_username[i++] = token;
		}
		rank.close();
	}
}

void Ranking::update_ranking(const std::string& username, const int score){
	if(!search(username)){
		int swap_score = score;
		std::string swap_username = username;
		for(int i=0; i < nbr_highscore; ++i){
			if(top_highscore[i] < score){	//better highscore
				int tmp_score = top_highscore[i];
				std::string tmp_username = top_username[i];
				top_highscore[i] = swap_score;
				top_username[i] = swap_username;
				swap_score = tmp_score;
				swap_username = tmp_username;
			}
		}
	}
}

void Ranking::update_file(){
	remove("ranking.txt");	//erase old ranking
	std::ofstream tmp("tmp.txt");	//create new ranking
	std::string writing = "";
	if(tmp.is_open()){
		for(int i=0; i<nbr_highscore && top_username[i] != ""; ++i){
			writing = std::to_string(top_highscore[i]) +" "+ top_username[i] + "\n";
			tmp << writing;
		}
		tmp.close();
	}
	std::rename("tmp.txt", "ranking.txt");
}

std::string Ranking::get_highscore(){
	std::string res = "";
	for(int i=0; i<nbr_highscore && top_username[i] != ""; ++i){
		res += std::to_string(top_highscore[i]) +" "+ top_username[i] + "\n";
	}
	return res;
}

bool Ranking::search(const std::string& username){
	for(int i=0; i<nbr_highscore; ++i){
		if( top_username[i] == username)return true;
	}
	return false;
}
