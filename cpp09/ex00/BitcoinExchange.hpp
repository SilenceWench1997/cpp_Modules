#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Btc{
private:
	std::string year;
	std::string month;
	std::string day;
	std::string line;
	std::string date;
	std::string value;
	std::string year;
	std::string month;
	std::string day;
	size_t pipePos;
	int monthNum;
	int dayNum;
	int yearNum;
	void splitData();
	void checkline();
	void parseDate();
	void parseValue();
	bool checkMonthDay();
public:
	void parse(std::string filename);
};

#endif
