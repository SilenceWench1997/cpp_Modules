#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Btc{
private:
	enum Errors{
		NEGVAL,
		HUGEVAL,
		INVVAL,
		FORMAT,
		MD,
		YEAR,
		MONTH,
		DAY,
		INVLINE,
	};
	std::string line;
	std::string date;
	std::string value;
	std::string year;
	std::string month;
	std::string day;
	std::string errorMessage;
	size_t pipePos;
	int monthNum;
	int dayNum;
	int yearNum;
	void splitData();
	void checkline();
	void parseDate();
	void parseValue();
	void throwError(Errors cause, std::string str);
	void checkMonthDay();
public:
	void parse(std::string filename);
	void displayBtc();
};

#endif
