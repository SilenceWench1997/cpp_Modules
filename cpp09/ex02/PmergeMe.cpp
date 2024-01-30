#include "PmergeMe.hpp"

std::vector<int> &PM::getArrV(){
	return (arrV);
}

std::vector<std::pair<int, int> > PM::createPairs(const std::vector<int> &arrVt){
	std::vector<std::pair<int, int> > pair;
	std::vector<int> largeElems;
	
	for (size_t i = 0; i < arrVt.size(); i += 2){ //creating pairs
		if (i + 1 < arrVt.size())
			pair.push_back(std::pair<int, int>(arrVt[i], arrVt[i + 1]));
		else
			pair.push_back(std::pair<int, int>(arrVt[i], -1));
	}
	return (pair);
}

void PM::merge(std::vector<int> &elems, size_t start, size_t middle, size_t end){
	size_t l = middle - start + 1;
	size_t r = end - middle;

	std::vector<int> left, right;
	for(size_t i = 0; i < l; i++)
		left[i] = elems[start + i];
	for(size_t i = 0; i < r; i++)
		right[i] = elems[middle + 1 + i];
	
	int i = 0, j = 0, k = start;
	while (i < l && j < r){
		if (left[i] <= right[j]) elems[k] = left[i++];
		else elems[k] = right[j++];
		k++;
	}
}

void PM::mergeSort(std::vector<int> &elems, size_t start, size_t end){
	if (start < end){
		size_t middle = start + (end - start) / 2;
		mergeSort(elems, start, middle);
		mergeSort(elems, middle + 1, end);

		merge(elems, start, middle, end);
	}
}

std::vector<int> PM::sortV(const std::vector<int> &arrVt){
	std::vector<int> largeElems;
	std::vector<std::pair<int, int> > pair;
	size_t i = 0;
	std::vector<int> sortedArr;

	if (arrVt.size() == 1){
		return (arrVt);
	}
	pair = createPairs(arrVt);
	while(i < pair.size()){ //choosing the bigger elements from each pair
		largeElems.push_back(std::max(pair[i].first, pair[i].second));
		i++;
	}
	mergeSort(largeElems, 0, largeElems.size() - 1);
	return (sortedArr);
}

void PM::parse(std::string input){
	std::istringstream conv(input);
	int num;

	for (size_t i = 0; i < input.size(); i++){
		if (!isdigit(input[i]))
			throw (std::invalid_argument("Non Numeric Character"));
	}
	if (!(conv >> num))
		throw (std::invalid_argument("Enter a number between 0 and 2147483647"));
	arrV.push_back(num);
}