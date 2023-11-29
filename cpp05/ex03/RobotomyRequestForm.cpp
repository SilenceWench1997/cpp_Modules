#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 0, 72, 45), target("test"){
	std::cout << "Robotomy Request Form Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 0, 145, 137), target(target){
	std::cout << "Robotomy Request Form constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref){
	std::cout << "Robotomy Request Form copy constructor called" << std::endl;
	target = ref.target;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Robotomy Request Form destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &ref){
	std::cout << "Robotomy Request Form '=' overload" << std::endl;
	target = ref.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	static int i = 0;
	if (this->getIsSigned() == 0)
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExec())
		throw (GradeTooLowException());
	std::cout << "Brrrrrrrrrr *drilling noises and stuff* Brrrrrrrrr" << std::endl;	
	if (i % 2 == 0)
		std::cout << "Target " << executor.getName() << " has been robotomized successfully" << std::endl;
	else	
		std::cout << "Robotomization of the target " << executor.getName() << " was failed"<< std::endl;
	i++;
}

AForm *RobotomyRequestForm::clone(std::string target){
	std::cout << "Robotomy Request Form clone called" << std::endl;
	AForm *ptr = new RobotomyRequestForm(target);
	return (ptr);
}