#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name), grade(ref.grade) {
	std::cout << "Bureaucrat copy constructor calledd" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name){
	std::cout << "Bureaucrat custom constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &ref){
	std::cout << "Bureaucrat '=' operator overload" << std::endl;
	name = ref.name;
	grade = ref.grade;
	return (*this);
}


const std::string Bureaucrat::getName() const{
	return (this->name);
}

int	Bureaucrat::getGrade() const{
	return (this->grade);
}

void Bureaucrat::incGrade(){
	setGrade(grade - 1);
}

void Bureaucrat::decGrade(){
	setGrade(grade + 1);
}

void Bureaucrat::setGrade(int grade){
	if (grade > 150)
		throw (gradeTooLowException());
	else if (grade < 1)
		throw (gradeTooHighException());
	this->grade = grade;
}

void Bureaucrat::signForm(Form &ref){
	std::cout << "Bureaucrat \"" << name << "\" is trying to sign the form \"" << ref.getName() << "\"" << std::endl;
	ref.beSigned(*this);
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat &ref){
	os << "name: " << ref.getName() << "\ngrade: " << ref.getGrade() << std::endl;
	return (os);
}
