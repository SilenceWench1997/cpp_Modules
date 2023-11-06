#include "Form.hpp"

Form::Form() : name("def"), isSigned(0), gradeSign(3), gradeExec(6){
	std::cout << "Form defaultf constructor called" << std::endl;
}

Form::Form(const Form &ref) : name(ref.name), isSigned(ref.isSigned), gradeSign(ref.gradeSign), gradeExec(ref.gradeExec) {
	std::cout << "Form copy constructor called" << std::endl;	
}

Form &Form::operator=(const Form &ref){
	if (this != &ref)
		isSigned = ref.isSigned;
	return (*this);
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
		throw Form::GradeTooLowException();
	}
	else if (ref.getGrade() < gradeSign){
		throw Form::GradeTooHighException();
	}
}

std::ostream &operator<<(std::ostream &os, const Form &ref){
	os << "Form Name: " << ref.getName() << "Is signed: " << ref.getIsSigned() << "Grade to sign: " << ref.getGradeSign() << "Grade to execute" << ref.getGradeExec() << std::endl;
	return (os);
}