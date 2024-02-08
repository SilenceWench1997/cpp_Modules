#include "PmergeMeV.hpp"

std::vector<int> &PMV::getArrV(){
	return (arrV);
}

std::vector<std::pair<int, int> > PMV::createPairs(const std::vector<int> &arrVt){
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

void PMV::merge(std::vector<std::pair<int, int> > &elems, size_t start, size_t middle, size_t end){
	size_t l = middle - start + 1;
	size_t r = end - middle;

	std::vector<int> left, right;
	for(size_t i = 0; i < l; i++)
		left.push_back(elems[start + i].first);
	for(size_t i = 0; i < r; i++)
		right.push_back(elems[middle + 1 + i].first);
		
	size_t i = 0, j = 0, k = start;
	while (i < l && j < r){
		if (left[i] <= right[j]) 
			elems[k].first = left[i++];
		else 
			elems[k].first = right[j++];
		k++;
	}	
	while (i < l)
		elems[k++].first = left[i++];
	while (j < r)
		elems[k++].first = right[j++];
}

void PMV::mergeSort(std::vector<std::pair<int, int> > &pairs, size_t start, size_t end){
	if (start < end){
		size_t middle = start + (end - start) / 2;
		mergeSort(pairs, start, middle);
		mergeSort(pairs, middle + 1, end);

		merge(pairs, start, middle, end);
	}
}

void PMV::sortPairs(std::vector<std::pair<int, int> > &pairs){
	int temp;
	for (size_t i = 0; i < pairs.size(); i++)
		if (pairs[i].first < pairs[i].second){
			temp = pairs[i].first;
			pairs[i].first = pairs[i].second;
			pairs[i].second = temp;
		}
}

std::vector<int>::iterator PMV::iterate(size_t pos, std::vector<int> &elems){
	std::vector<int>::iterator it = elems.begin();
	for(size_t i = 0; i < pos; i++)
		it++;
	return (it);
}

std::vector<int>::iterator PMV::binarySearch(std::vector<int> &elems, int num, size_t low, size_t high){
	size_t mid = low + (high - low)/2;

	if (high == low)
		return (iterate(high + (num > elems[mid]), elems));
	if (num > elems[mid])
		low = mid + 1;
	else if (num < elems[mid]){
		high = mid - (mid != 0 && mid != low);
	}
	else
		return (iterate(high, elems));
	return (binarySearch(elems, num, low, high));
}

std::vector<int> PMV::sortV(const std::vector<int> &arrVt){
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> sortedArr;
	std::vector<int> smallerElems;

	if (arrVt.size() == 1)
		return (arrVt);
	pairs = createPairs(arrVt);
	sortPairs(pairs);
	mergeSort(pairs, 0, pairs.size() - 1);
	sortedArr.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		sortedArr.push_back(pairs[i].first);
	for (size_t i = 1; i < pairs.size(); i++)
		smallerElems.push_back(pairs[i].second);
	for (size_t i = 0; i < smallerElems.size(); i++){
		sortedArr.insert(binarySearch(sortedArr, smallerElems[i], 0, sortedArr.size() - 1), smallerElems[i]);
	}
	if (sortedArr[0] == -1)
		sortedArr.pop_back();
	return (sortedArr);
}

void PMV::setStart(){
	start = clock();
}

void PMV::printResults(std::vector<int> &before, std::vector<int> after){
	double duration = (std::clock() - start)/(double)CLOCKS_PER_SEC;
	std::cout << "Before: ";
	for (size_t i = 0; i < before.size(); i++)
		std::cout << before[i] << " ";
	std::cout << "\nAfter: ";
	for (size_t i = 0; i < after.size(); i++)
		std::cout << after[i] << " ";
	std::cout << "\nTime to process a range of " << before.size() << " elements with std::vector : " << std::fixed << duration << " seconds" << std::endl;
}
