#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class PM{
private:
	std::vector<int> arrV;
public:
	void parse(std::string input);
	std::vector<int> &getArrV();
	std::vector<std::pair<int, int> > createPairs(const std::vector<int> &arrVt);
	std::vector<int> sortV(const std::vector<int> &arrVt);
	void mergeSort(std::vector<std::pair<int, int> > &elems, size_t start, size_t end);
	void merge(std::vector<std::pair<int, int> > &elems, size_t start, size_t middle, size_t end);
	std::vector<int>::iterator binarySearch(std::vector<int> &elems, int num, size_t low, size_t high);
	std::vector<int>::iterator iterate(size_t pos, std::vector<int> &elems);
	void sortPairs(std::vector<std::pair<int, int> > &pairs);
};
#endif
