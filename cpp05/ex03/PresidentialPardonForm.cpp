#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 0, 25, 5), target("test"){
	std::cout << "Presidential Pardon Form Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 0, 25, 5), target(target){
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref){
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
	target = ref.target;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &ref){
	std::cout << "Presidential Pardon Form '=' overload" << std::endl;
	target = ref.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (this->getIsSigned() == 0)
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExec())
		throw (GradeTooLowException());
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;	
}

AForm *PresidentialPardonForm::clone(std::string target){
	std::cout << "Presidential Pardon Form clone called" << std::endl;
	AForm *ptr = new PresidentialPardonForm(target);
	return (ptr);
}
