#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &ref){
	std::cout << "Intern copy constructor called" << std::endl;
	(void)ref;
}

Intern &Intern::operator=(const Intern &ref){
	std::cout << "Intern '=' operator overload" << std::endl;	
	(void)ref;
	return (*this);
}

AForm  *Intern::makeForm(std::string name, std::string target){
	std::string *nameArr = new std::string[3];
	AForm *(*functArr[3])(std::string) = {ShrubberyCreationForm::clone, RobotomyRequestForm::clone, PresidentialPardonForm::clone};
	nameArr[0] = "shrubbery creation";
	nameArr[1] = "robotomy request";
	nameArr[2] = "presidential pardon";
	for(int i = 0; i < 4; i++){
		if (nameArr[i] == name){
			std::cout << "Intern Creates " << name << std::endl;
			return(functArr[i](target));
		}
	}
	std::cout << "Error: Invalid name" << std::endl;
	return (NULL);
}
