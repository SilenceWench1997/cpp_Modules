#include "Harl.hpp"
#include <string>
#include <iostream>

int main()
{
	Harl test;
	
	test.complain("WARNING");
	test.complain("ERROR");
	test.complain("DEBUG");
	test.complain("INFO");
}