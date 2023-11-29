#include "AForm.hpp"

AForm::AForm() : name("def"), isSigned(0), gradeSign(3), gradeExec(6){
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &ref) : name(ref.name), isSigned(ref.isSigned), gradeSign(ref.gradeSign), gradeExec(ref.gradeExec) {
	std::cout << "AForm copy constructor called" << std::endl;	
}

AForm &AForm::operator=(const AForm &ref){
	if (this != &ref)
		isSigned = ref.isSigned;
	return (*this);
}

AForm::AForm(const std::string name, bool iS, const int gS, const int gE) : name(name), isSigned(iS), gradeSign(gS), gradeExec(gE){
	std::cout << "AForm custom constructor called" << std::endl;
	if (gS > 150 || gE > 150){
		throw (AForm::GradeTooLowException());
	}
	else if (gS < 1 || gE < 1){
		throw(AForm::GradeTooHighException());
	}
}

AForm::~AForm(){
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const{
	return (name);
}

bool	AForm::getIsSigned() const{
	return (isSigned);
}

int AForm::getGradeSign() const{
	return (gradeSign);
}

int AForm::getGradeExec() const{
	return (gradeExec);
}

void	AForm::beSigned(const Bureaucrat &ref){
	if (ref.getGrade() > gradeSign){
		std::cout << "Could not sign, because grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	this->isSigned = 1;
	std::cout << "Signed successfully!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &ref){
	os << "AForm Name: " << ref.getName() << "Is signed: " << ref.getIsSigned() << "Grade to sign: " << ref.getGradeSign() << "Grade to execute" << ref.getGradeExec() << std::endl;
	return (os);
}
