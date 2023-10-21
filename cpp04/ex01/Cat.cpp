#include "Cat.hpp"

Cat::Cat() : brain(new Brain){
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
}


Cat::Cat(const Cat &src) : brain(new Brain(*(src.brain))) {
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
	std::cout << "Cat '=' operator overload" << std::endl;
	this->type = ref.type;
	*brain = *ref.brain;
	return (*this);
}