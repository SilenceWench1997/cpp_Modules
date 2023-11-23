#include "Form.hpp"

Form::Form() : name("def"), isSigned(0), gradeSign(3), gradeExec(6){
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &ref) : name(ref.name), isSigned(ref.isSigned), gradeSign(ref.gradeSign), gradeExec(ref.gradeExec) {
	std::cout << "Form copy constructor called" << std::endl;	
}

Form &Form::operator=(const Form &ref){
	if (this != &ref)
		isSigned = ref.isSigned;
	return (*this);
}

Form::Form(const std::string name, bool iS, const int gS, const int gE) : name(name), isSigned(iS), gradeSign(gS), gradeExec(gE){
	std::cout << "Form custom constructor called" << std::endl;
}

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const{
	return (name);
}

bool	Form::getIsSigned() const{
	return (isSigned);
}

int Form::getGradeSign() const{
	return (gradeSign);
}

int Form::getGradeExec() const{
	return (gradeExec);
}

void	Form::beSigned(const Bureaucrat &ref){
	if (ref.getGrade() > gradeSign){
		std::cout << "Could not sign, because grade is too low" << std::endl;
		throw Form::GradeTooLowException();
	}
	this->isSigned = 1;
	std::cout << "Signed successfully!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &ref){
	os << "Form Name: " << ref.getName() << "Is signed: " << ref.getIsSigned() << "Grade to sign: " << ref.getGradeSign() << "Grade to execute" << ref.getGradeExec() << std::endl;
	return (os);
}