#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
private:
	std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &ref);
	std::ostream &operator<<(std::ostream &os);
	const std::string getName();
	int	getGrade();
	void incGrade();
	void decGrade();
	class	gradeTooHighException(std::string message){
	};
	class	gradeTooLowException(std::string message){
	};
};

#endif