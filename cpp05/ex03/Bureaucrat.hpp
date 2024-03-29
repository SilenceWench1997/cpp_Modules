#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

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
	const std::string getName() const;
	int	getGrade() const;
	void incGrade();
	void decGrade();
	void setGrade(int grade);
	void signForm(AForm &ref);
	void executeForm(AForm &ref);
	class	gradeTooHighException : public std::exception{
	public:
		virtual const char *what() const throw(){
			return "Bureaucrat : Grade too high!";
		}
	};
	class	gradeTooLowException :  public std::exception{
	public:
		virtual const char *what() const throw(){
			return "Bureaucrat : Grade too low!";
		}
	};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bur);

#endif
