#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>

class Btc{
private:
	std::string line;
	std::string date;
	std::string value;

	void checkline();
public:
	void parse(std::string filename);
};

#endif