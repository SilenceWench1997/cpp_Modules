#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv){
	switch (argc){
		case 1: {
			Btc btc;
			btc.parse(argv[0]);
			return (0);
		}
		default:
			std::cout << "Wrong number of arguments" << std::endl;
	}
}