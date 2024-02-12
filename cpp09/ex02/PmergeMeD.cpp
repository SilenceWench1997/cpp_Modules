#include "PmergeMeD.hpp"

std::deque<int> &PMD::getArr(){
	return (arrV);
}

double &PMD::getDuration(){
	return (duration);
}

std::deque<std::pair<int, int> > PMD::createPairs(const std::deque<int> &arrVt){
	std::deque<std::pair<int, int> > pair;
	std::deque<int> largeElems;
	
	for (size_t i = 0; i < arrVt.size(); i += 2){
		if (i + 1 < arrVt.size())
			pair.push_back(std::pair<int, int>(arrVt[i], arrVt[i + 1]));
		else
			pair.push_back(std::pair<int, int>(arrVt[i], -1));
	}
	return (pair);
}

void PMD::merge(std::deque<std::pair<int, int> > &elems, size_t start, size_t middle, size_t end){
	size_t l = middle - start + 1;
	size_t r = end - middle;

	std::deque<std::pair<int, int> > left, right;
	for(size_t i = 0; i < l; i++)
		left.push_back(elems[start + i]);
	for(size_t i = 0; i < r; i++)
		right.push_back(elems[middle + 1 + i]);
		
	size_t i = 0, j = 0, k = start;
	while (i < l && j < r){
		if (left[i].first <= right[j].first) 
			elems[k] = left[i++];
		else 
			elems[k] = right[j++];
		k++;
	}
	while (i < l)
		elems[k++] = left[i++];
	while (j < r)
		elems[k++] = right[j++];
}

void PMD::mergeSort(std::deque<std::pair<int, int> > &pairs, size_t start, size_t end){
	if (start < end){
		size_t middle = start + (end - start) / 2;
		mergeSort(pairs, start, middle);
		mergeSort(pairs, middle + 1, end);

		merge(pairs, start, middle, end);
	}
}

void PMD::sortPairs(std::deque<std::pair<int, int> > &pairs){
	int temp;
	for (size_t i = 0; i < pairs.size(); i++)
		if (pairs[i].first < pairs[i].second){
			temp = pairs[i].first;
			pairs[i].first = pairs[i].second;
			pairs[i].second = temp;
		}
}

std::deque<int>::iterator PMD::iterate(size_t pos, std::deque<int> &elems){
	std::deque<int>::iterator it = elems.begin();
	for(size_t i = 0; i < pos; i++)
		it++;
	return (it);
}

std::deque<int>::iterator PMD::binarySearch(std::deque<int> &elems, int num, size_t low, size_t high){
	size_t mid = low + (high - low)/2;
	if (high == low)
		return (iterate(high + (num > elems[mid]), elems));
	if (num >= elems[mid])
		low = mid + 1;
	else if (num < elems[mid]){
		high = mid - (mid != 0 && mid != low);
	}
	else
		return (iterate(high, elems));
	return (binarySearch(elems, num, low, high));
}

void PMD::orderSmallerElems(std::deque<int> &smallerElems){
	std::deque<std::deque<int> > vecdeque;
	size_t sizeNew = 2;
	int posNew = 1;
	int posOld = -1;
	if (smallerElems.size() <= 1)
		return ;
	for(int i = 2; smallerElems.size() >= (size_t)posNew + 1; i++){
		std::deque<int> vt;
		for (int i = posNew; i > posOld; i--)
			vt.push_back(smallerElems[i]);
		vecdeque.push_back(vt);
		sizeNew = pow(2, i) - sizeNew;
		posOld = posNew;
		posNew += sizeNew;
	}
	if (smallerElems.size() - (posOld + 1) > 0){
		std::deque<int> vt;
		for (int i = smallerElems.size() - 1; i < posOld; i--)
			vt.push_back(smallerElems[i]);
		vecdeque.push_back(vt);
	}
	size_t k = 0;
	for (size_t i = 0; i < vecdeque.size(); i++){
		for (size_t j = 0; j < vecdeque[i].size(); j++){
			smallerElems[k] = vecdeque[i][j];
			k++;
		}
	}
}

std::deque<int> PMD::sort(const std::deque<int> &arrVt){
	clock_t start = clock();
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> sortedArr;
	std::deque<int> smallerElems;

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
	for (size_t i = 0; i < smallerElems.size(); i++)
		sortedArr.insert(binarySearch(sortedArr, smallerElems[i], 0, sortedArr.size() - 1), smallerElems[i]);
	if (sortedArr[0] == -1)
		sortedArr.erase(sortedArr.begin());
	duration = (std::clock() - start)/(double)CLOCKS_PER_SEC;
	return (sortedArr);
}
