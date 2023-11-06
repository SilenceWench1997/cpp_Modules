#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name), grade(ref.grade) {
	std::cout << "Bureaucrat copy constructor calledd" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){
	std::cout << "Bureaucrat universal constructor called" << std::endl;
	if (grade < 1){
		throw gradeTooHighException();
	}
	else if (grade > 150){
		throw gradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor calledd" << std::endl;
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
	grade--;
}

void Bureaucrat::decGrade(){
	grade++;
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat &ref){
	os << "name: " << ref.getName() << "\ngrade: " << ref.getGrade() << std::endl;
	return (os);
}
