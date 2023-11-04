#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat{
private:
	std::string name;
	int grade;
public:
	Bureaucrat::Bureaucrat();
	Bureaucrat::Bureaucrat(const Bureaucrat &ref);
	Bureaucrat::Bureaucrat(int grade);
	Bureaucrat::Bureaucrat(std::string name);
	Bureaucrat::Bureaucrat(std::string name, int grade);
	Bureaucrat::~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &ref);
	std::ostream &operator<<(std::ostream &os);
	const std::string Bureaucrat::getName();
	int	Bureaucrat::getGrade();
	void incGrade();
	void decGrade();
}

#endif