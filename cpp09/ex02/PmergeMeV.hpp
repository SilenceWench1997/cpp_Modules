#ifndef PMV_HPP
#define PMV_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cmath>

class PMV{
private:
	std::vector<int> arrV;
	clock_t start;
public:
	void setStart();
	void printResults();
	std::vector<int> &getArr();
	std::vector<std::pair<int, int> > createPairs(const std::vector<int> &arrVt);
	std::vector<int> sort(const std::vector<int> &arrVt);
	void mergeSort(std::vector<std::pair<int, int> > &elems, size_t start, size_t end);
	void merge(std::vector<std::pair<int, int> > &elems, size_t start, size_t middle, size_t end);
	std::vector<int>::iterator binarySearch(std::vector<int> &elems, int num, size_t low, size_t high);
	std::vector<int>::iterator iterate(size_t pos, std::vector<int> &elems);
	void sortPairs(std::vector<std::pair<int, int> > &pairs);
	void printResults(std::vector<int> &before, std::vector<int> after);
	void orderSmallerElems(std::vector<int> &smallerElems);
};
#endif
