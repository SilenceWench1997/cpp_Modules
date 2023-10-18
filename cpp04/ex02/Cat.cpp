#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Default Constructor called" << std::endl;
	this->brain = new Brain;
	this->type = "Cat";
}

Cat::Cat(const Cat &src){
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = src.type;
}

Cat::~Cat(){
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "*Cat noises*" << std::endl;
}

Cat & Cat::operator=(const Cat &ref){
	this->type = ref.type;
	return (*this);
}