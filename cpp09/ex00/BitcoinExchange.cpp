#include "BitcoinExchange.hpp"

void Btc::parseValue(){
	std::istringstream conv(value);
	int valI;
	float valF;
	if (conv >> valI){
		if (valI >= 0 && valI <= 1000)
			return ;
		else
			throw (std::invalid_argument("Invalid Value"));
	}	else if (conv >> valF){
		if (valF >= 0 && valF <= 1000)
			return ;
		else
			throw (std::invalid_argument("Invalid Value"));
	}
	throw (std::invalid_argument("Invalid Value"));
}

void Btc::splitData(){
	size_t dashPos = 0;
	size_t dashOld = 0;
	size_t count = 0;

	if (date.find('-') == std::string::npos)
		throw (std::invalid_argument("Invalid Date"));
	while (true){
		dashOld = dashPos;
		dashPos = date.find('-', dashPos + (dashPos != 0));
		switch (count){
			case 0:
			year = date.substr(0, dashPos);
			break ;
			case 1:
			month = date.substr(dashOld + 1, dashPos - (dashOld + 1));
			break ;
			case 2:
			day = date.substr(dashOld + 1, date.size() - 1);
		}
		if (count == 2)
			break ;
		count++;
	}
	if (count != 2 || day.find('-') != std::string::npos)
		throw (std::invalid_argument("Invalid Date"));
}

bool Btc::checkMonthDay(){
	switch (monthNum){
		case 1:
		if (dayNum >= 1 && dayNum <= 31)
			return (true);
		break ;
		case 2: //february
			switch (yearNum % 4){
			case 0:
			if (dayNum >= 1 && dayNum <= 29)
				return (true);
			break ;

			default:
			if (dayNum >= 1 && dayNum <= 28)
				return (true);
			break ;
			}
			break ;
		case 3:
		if (dayNum >= 1 && dayNum <= 31)
			return (true);
		break ;
		case 4:
		if (dayNum >= 1 && dayNum <= 30)
			return (true);
		break ;
		case 5:
		if (dayNum >= 1 && dayNum <= 31)
			return (true);
		break ;
		case 6:
		if (dayNum >= 1 && dayNum <= 30)
			return (true);
		break ;
		case 7:
		if (dayNum >= 1 && dayNum <= 31)
			return (true);
		break ;
		case 8:
		if (dayNum >= 1 && dayNum <= 31)
			return (true);
		break ;
		case 9:
		if (dayNum >= 1 && dayNum <= 30)
			return (true);
		break ;
		case 10:
		if (dayNum >= 1 && dayNum <= 31)
			return (true);
		break ;
		case 11:
		if (dayNum >= 1 && dayNum <= 30)
			return (true);
		break ;
		case 12:
		if (dayNum >= 1 && dayNum <= 31)
			return (true);
		break ;
	}
	return (false);
}

void Btc::parseDate(){
 	splitData();
	std::istringstream convY(year);
	std::istringstream convM(month);
	std::istringstream convD(day);

	if (year.size() != 4 || !(convY >> yearNum) ||
	month.size() != 2 || !(convM >> monthNum) ||
	day.size() != 2 || !(convD >> dayNum) || !checkMonthDay())
		throw (std::invalid_argument("Invalid Date"));
}

void Btc::checkline(){
	pipePos = line.find('|');
	if (pipePos != std::string::npos){
		date = line.substr(0, pipePos);
		value = line.substr(pipePos + 1, line.size() - pipePos);
		try{
			parseDate();
			parseValue();
		} catch (const std::invalid_argument &e){
			std::cout << e.what() << std::endl;
		}
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
		}
	}
	
}
