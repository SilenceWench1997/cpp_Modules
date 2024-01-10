#include "BitcoinExchange.hpp"

size_t Btc::countDashes(){
	size_t pos = 0;
	size_t count = 0;
	
	while (pos != std::string::npos || count <= 2){
		switch(count){
				case 0:
						year = date.substr(0, date.find('-'));
						break ;
				case 1:
						month = date.substr(pos + 1, date.find('-') + 1);
						break ;
				case 2:
						day = date.substr(pos + 1, date.size() - 1);
						break ;
		}
		pos = date.find('-', pos + 1);
		count++;
		std::cout << "Count:" << count << "\nPos:" << pos << "\n";
		std::cout << "Year:"  << year << "\n";
		std::cout << "Month:"  << month << "\n";
		std::cout << "Day:"  << day << "\n";
		std::cout <<  "\n";
	}
	return (count);
}

void Btc::parseValue(){
	
}

void Btc::parseDate(){
	std::string year;
	std::string month;
	std::string day;

	if (countDashes() != 2)
		throw std::invalid_argument("Wrong number of dashes");
	month = date.substr(0, date.find('-'));
	
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
			std::cout << e.what() << std::endl;
		}
		return ;
	}
	throw (std::invalid_argument("No pipe found"));
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
		}
	}
	
}
