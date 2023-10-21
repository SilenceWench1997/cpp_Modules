#include "Brain.hpp"

Brain::Brain(){
	this->ideas = new std::string[100];
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain & ref){
	std::cout << "Brain Copy constructor called" << std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++){
		this->ideas[i] = ref.ideas[i];
	}
}

Brain::~Brain(){
	std::cout << "Brain Default destructor called" << std::endl;
	delete[] this->ideas;
}

Brain & Brain::operator=(const Brain & ref){
	std::cout << "Brain '='operator overload" << std::endl;
	delete[] ideas;
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++){
		this->ideas[i] = ref.ideas[i];
	}
	return (*this); 
}