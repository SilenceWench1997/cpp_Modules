#ifndef PML_HPP
#define PML_HPP

#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cmath>

class PMD{
private:
	std::deque<int> arrV;
	double duration;
public:
	void printResults();
	std::deque<int> &getArr();
	double &getDuration();
	std::deque<std::pair<int, int> > createPairs(const std::deque<int> &arrVt);
	std::deque<int> sort(const std::deque<int> &arrVt);
	void mergeSort(std::deque<std::pair<int, int> > &elems, size_t start, size_t end);
	void merge(std::deque<std::pair<int, int> > &elems, size_t start, size_t middle, size_t end);
	std::deque<int>::iterator binarySearch(std::deque<int> &elems, int num, size_t low, size_t high);
	std::deque<int>::iterator iterate(size_t pos, std::deque<int> &elems);
	void sortPairs(std::deque<std::pair<int, int> > &pairs);
	void orderSmallerElems(std::deque<int> &smallerElems);
};

#endif