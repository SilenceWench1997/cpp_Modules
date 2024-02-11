#ifndef PML_HPP
#define PML_HPP

#include <list>
#include <iostream>

class PML {
private:
	std::list<int> arrL;
public:
	PML();
	~PML();
	std::list<int> &getArr();
	std::list<int> &sort(std::list<int> arrL);
};

#endif