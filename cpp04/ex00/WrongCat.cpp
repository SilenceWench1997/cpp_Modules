#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "WrongCat Default Constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src){
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	this->type = src.type;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor called" << std::endl;
}