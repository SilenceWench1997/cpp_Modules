#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
private:
	const std::string name;
	bool isSigned;
	const int gradeSign;
	const int gradeExec;
public:
	Form();
	Form(const Form &ref);
	Form(std::string name, bool iS, const int gS, const int gE);
	Form &operator=(const Form &ref);
	~Form();
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;
	void		beSigned(const Bureaucrat &ref);
	class GradeTooHighException : std::exception{
	public:
		virtual const char *what() const noexcept{
			return "Form: Grade too high!";
		}
	};
	class GradeTooLowException : std::exception{
	public:
		virtual const char *what() const noexcept{
			return "Form: Grade too low!";
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Form &ref);

#endif