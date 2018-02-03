#include "ranking.hpp"

/* PUBLIC */

// Constructor

Ranking::~Ranking(){
	delete[] top_highscore;
	delete[] top_username;
}

// Functions

const char* Ranking::get_highscore(){
	std::string res = "";
	
	for(int i=0; i<this->nbr_highscore && this->top_username[i] != ""; ++i){
		res += std::to_string(this->top_highscore[i]) + this->_delimiter + this->top_username[i] + "\n";
	}
	return res.c_str();
}

void Ranking::init(const std::string& filename){
	_filename = filename;
	this->top_highscore = new int[nbr_highscore];
	this->top_username = new std::string[nbr_highscore];
	this->read_file();
}

void Ranking::update_ranking(const std::string& username, const int score){
	int swap_score = score;
	std::string swap_username = username;
	bool found= false;
	for(int i=0; i < this->nbr_highscore; ++i){
		if(this->top_highscore[i] < score || found){	//better highscore
			found = true;
			int tmp_score = this->top_highscore[i];
			std::string tmp_username = this->top_username[i];
			this->top_highscore[i] = swap_score;
			this->top_username[i] = swap_username;
			swap_score = tmp_score;
			swap_username = tmp_username;
		}
	}
}

void Ranking::update_file(){
	remove(_filename.c_str());	//erase old ranking
	std::ofstream tmp("tmp.txt");	//create new ranking
	std::string writing = "";
	if(tmp.is_open()){
		for(int i=0; i<this->nbr_highscore && this->top_username[i] != ""; ++i){
			writing = std::to_string(this->top_highscore[i]) + this->_delimiter + this->top_username[i] + "\n";
			tmp << writing;
		}
		tmp.close();
	}
	std::rename("tmp.txt", _filename.c_str());
}

/* PRIVATE */

// Function

void Ranking::read_file(){
	int i=0;
	std::string line;
	std::ifstream rank;	//read mode
	rank.open(_filename);
	if(rank.is_open()){
		while(std::getline(rank, line) && i<this->nbr_highscore){
			size_t pos=0;
			std::string token;	//substring of line
			pos = line.find(_delimiter);	//find end of substring
    		token = line.substr(0, pos);
			this->top_highscore[i] = std::stoi(token);	//string to int
    		line.erase(0, pos + this->_delimiter.length());
			pos = line.find(this->_delimiter);
    		token = line.substr(0, pos);
			this->top_username[i++] = token;
		}
		rank.close();
	}
}
