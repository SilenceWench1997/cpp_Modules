#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src){
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = src.type;
}

Cat::~Cat(){
	std::cout << "Cat Destructor called" << std::endl;
}