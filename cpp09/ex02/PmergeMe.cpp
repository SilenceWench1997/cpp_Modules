#include "PmergeMe.hpp"

std::vector<int> PM::sortV(){
	std::vector<std::pair<int, int>> pair;
	std::vector<int> largeElems;
	if (arrV.size() % 2 == 1){
		//Odd argument
	}
	for (size_t i = 0; i < arrV.size(); i += 2){
		if (i + 1 < arrV.size()){
			pair.push_back(std::pair<int, int>(arrV[i], arrV[i + 1]));
		}
	}
	for (size_t i = 0; i < pair.size(); i++){
		(pair[i].first > pair[i].second) ? 
		largeElems.push_back(pair[i].first):
		largeElems.push_back(pair[i].first);
	}
	
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