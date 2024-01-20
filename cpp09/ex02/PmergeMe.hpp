#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>

class PM{
private:
	std::vector<int> arrV;
public:
	void parse(std::string input);
	void sortV();
};

#endif