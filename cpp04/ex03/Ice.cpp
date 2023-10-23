#include "Ice.hpp"

Ice::Ice(){
	std::cout << "Ice default constructor called" << std::endl;
	this->type = "ice";
}

Ice::~Ice(){
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice &ref){
	std::cout << "Ice copy constructor called" << std::endl;
	type = ref.type;
}

Ice & Ice::operator=(const Ice &ref){
	std::cout << "Ice '=' operator overload" << std::endl;
	if (this == &ref)
	{
		std::cout << "Same Ice" << std::endl;
		return (*this);
	}
	type = ref.type;
	return (*this);
}