#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Default Constructor called" << std::endl;
	this->brain = new Brain;
	this->type = "Dog";
}

Dog::Dog(const Dog &src){
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->type = src.type;
}

Dog::~Dog(){
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "*Dog noises*" << std::endl;
}

Dog & Dog::operator=(const Dog &ref){
	this->type = ref.type;
	return (*this);
}