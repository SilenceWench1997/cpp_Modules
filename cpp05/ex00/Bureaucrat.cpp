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
		throw gradeException("Grade too low");
	}
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor calledd" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &ref){
	std::cout << "Bureaucrat '=' operator overload" << std::endl;
	this->name = ref.name;
	this->grade = ref.grade;
}

std::ostream & Bureaucrat::operator<<(std::ostream &os){
	os << "name: " << this->name << "\ngrade: " << this->grade << std::endl;
}

const std::string Bureaucrat::getName(){
	return (this->name);
}

int	Bureaucrat::getGrade(){
	return (this->grade);
}

void Bureaucrat::incGrade(){
	grade--;
}

void Bureaucrat::decGrade(){
	grade++;
}