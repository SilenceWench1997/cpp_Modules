#include "ScalarConverter.hpp"

int main(int argc, const char **argv){
	if (argc != 2){
		std::cout << "Wrong Number of Arguments" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
}
