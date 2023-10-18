#include "Brain.hpp"

Brain::Brain(){
	this->ideas = new std::string[100];
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain & ref){
	std::cout << "Brain Copy constructor called" << std::endl;
	this->ideas = ref.ideas;
}

Brain::~Brain(){
	std::cout << "Brain Default destructor called" << std::endl;
	delete[] this->ideas;
}

Brain & Brain::operator=(const Brain & ref){
	this->ideas = ref.ideas;
	return (*this); 
}