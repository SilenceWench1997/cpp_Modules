#include <PmergeMeL.hpp>

std::list<int> &PML::getArrL(){
	return (arrL);
}

std::list<std::pair<int, int> > createPairs(std::list<int> &arrL){
	
}

std::list<int> &PML::sortL(std::list<int> arrL){
	std::list<std::pair<int, int> > pairs;
	std::list<int> sortedArr;
	std::list<int> smallerElems;

	if (arrL.size() == 1)
		return (arrL);
	pairs = createPairs(arrL);
	// sortPairs(pairs);
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
