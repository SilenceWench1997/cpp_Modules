#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	
	if (argc != 2){
		std::cout << "Wrong Number of Arguments" << std::endl;
	}
	ScalarConverter::convert(argv[1]);
}
