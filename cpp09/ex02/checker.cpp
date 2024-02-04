#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>

int error(std::string str){
	std::cout << str << std::endl;
	return (1);
}

bool strncmp(std::string first, std::string second, size_t len){
	for (size_t i = 0; i < len; i++){
		if (i == first.size() || i == second.size())
			return (false);
		if (first[i] != second[i])
			return (false);
	}
	return (true);
}

int main(){
	std::string inp;
	std::string str;
	std::vector<int> arrVt;

	getline(std::cin, inp);
	if (!strncmp(inp, "Before:", 7))
		return (error("Invalid argument"));
	getline(std::cin, inp);
	if (!strncmp(inp, "After:", 6))
		return (error("Invalid argument"));
	
	std::istringstream conv(inp);
	while (getline(conv, str, ' ')){
		arrVt.push_back(std::atoi(str.c_str()));
	}
	for (size_t i = 0; i < arrVt.size() - 1; i++){
		if (arrVt[i] > arrVt[i + 1])
			return (error("The array was not sorted"));
	}
	std::cout << "The array was sorted" << std::endl;
	return (0);
}
