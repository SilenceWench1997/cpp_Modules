#ifndef PML_HPP
#define PML_HPP

#include <list>

class PML {
private:
	std::list<int> arrL;
public:
	PML();
	~PML();
	std::list<int> &getArrL();
	std::list<int> &sortL(std::list<int> arrL);
};

#endif