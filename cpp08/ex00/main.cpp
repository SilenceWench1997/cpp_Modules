#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(){
	std::vector<int> vt;
	vt.push_back(42);
	vt.push_back(31);
	vt.push_back(123);
	try{
		easyfind(vt, 321);
	}catch(const std::out_of_range &e){
		std::cout << e.what() << std::endl;
	}
}
