#include "Dog.hpp"

Dog::Dog() : brain(new Brain){
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src) : brain(new Brain(*(src.brain))) {
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
	std::cout << "Dog '=' operator overload" << std::endl;
	this->type = ref.type;
	*brain = *ref.brain;
	return (*this);
}