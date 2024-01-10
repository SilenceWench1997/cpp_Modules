#include "BitcoinExchange.hpp"

void Btc::parseValue(){
}

void Btc::parseDate(){

}

void Btc::checkline(){
	pipePos = line.find('|');
	if (pipePos != std::string::npos){
		date = line.substr(0, pipePos);
		value = line.substr(pipePos + 1, line.size() - pipePos);
		try{
			parseDate();
			parseValue();
		} catch (const std::exception &e){
			std::cout << e.what();
		}
		std::cout << "date: " << date << std::endl;
		std::cout << "value: " << value << std::endl;
		return ;
	}
	throw (std::invalid_argument("No | found"));
}

void Btc::parse(std::string filename){
	std::ifstream db;

	db.open(filename);
	if (db.is_open()){
		while (getline(db, line)){
			try{
				checkline();
			} catch (const std::invalid_argument &e){
				std::cout << e.what() << std::endl;
			}
			system("leaks btc");
		}
	}
	
}