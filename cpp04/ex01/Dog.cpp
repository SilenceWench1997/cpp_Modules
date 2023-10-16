#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src){
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->type = src.type;
}

Dog::~Dog(){
	std::cout << "Dog Destructor called" << std::endl;
}