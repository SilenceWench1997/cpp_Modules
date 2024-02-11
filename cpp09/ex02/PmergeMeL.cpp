#include <PmergeMeL.hpp>

std::list<int> &PML::getArr(){
	return (arrL);
}

void	PML::sortPairs(std::list<std::pair<int, int> > &pairs){
	int temp;

	for (size_t i = 0; i < pairs.size(); i++)
	if (pairs[i].first < pairs[i].second){
		temp = pairs[i].first;
		pairs[i].first = pairs[i].second;
		pairs[i].second = temp;
	}
}

std::list<std::pair<int, int> > PML::createPairs(std::list<int> &arrL){
	std::list<std::pair<int, int> > pair;
	std::list<int> largeElems;
	
	for (std::list<int>::iterator it = arrL.begin(); it != arrL.end(); it++){
		if (it + 1 < arrL.size())
			pair.push_back(std::pair<int, int>(arrL[i], arrL[i + 1]));
		else
			pair.push_back(std::pair<int, int>(arrL[i], -1));
	}
	return (pair);
}

std::list<int> &PML::sort(std::list<int> arrL){
	std::list<std::pair<int, int> > pairs;
	std::list<int> sortedArr;
	std::list<int> smallerElems;

	if (arrL.size() == 1)
		return (arrL);
	pairs = createPairs(arrL);
	sortPairs(pairs);
	// mergeSort(pairs, 0, pairs.size() - 1); //sorting the bigger elements
	// for (size_t i = 0; i < pairs.size(); i++)
	// 	sortedArr.push_back(pairs[i].first);
	// for (size_t i = 0; i < pairs.size(); i++)
	// 	smallerElems.push_back(pairs[i].second);
	// for (size_t i = 0; i < smallerElems.size(); i++){
	// 	sortedArr.insert(binarySearch(sortedArr, smallerElems[i], 0, sortedArr.size() - 1), smallerElems[i]);
	// }
	// if (sortedArr[0] == -1)
	// 	sortedArr.pop_back();
	// return (sortedArr);
}
