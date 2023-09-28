#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl test;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		test.harlSwitch(test.harlNum(argv[1]));
}