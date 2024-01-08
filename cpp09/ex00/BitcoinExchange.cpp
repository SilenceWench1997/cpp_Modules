#include "BitcoinExchange.hpp"

void Btc::checkline(){
	
}

void Btc::parse(std::string filename){
	std::ifstream db;

	db.open(filename);
	if (db.is_open()){
		while (getline(db, line)){
			checkline();
		}
	}
}