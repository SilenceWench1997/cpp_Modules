#include "RPN.hpp"

int main(int argc, char **argv){
	switch (argc){
		case 2:
			Rpn::parser(argv[1]);
			break ;
		default:
			std::cout << "Wrong Number of Arguments" << std::endl;
	}
	return (0);
}
