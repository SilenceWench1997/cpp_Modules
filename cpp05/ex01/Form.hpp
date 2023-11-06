#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form{
private:
	const std::string name;
	bool isSigned;
	const int gradeSign;
	const int gradeExec;
public:
	Form();
	Form(const Form &ref);
	Form &operator=(const Form &ref);
	~Form();
	std::string	getName() const;
	bool	getIsSigned() const;
	int	getGradeSign() const;
	int	getGradeExec() const;
	void	beSigned(const Bureaucrat &ref);
	class GradeTooHighException{
	public:
		virtual const char *what() const _NOEXCEPT{
			return "Form: Grade too high!";
		}
	};
	class GradeTooLowException{
	public:
		virtual const char *what() const _NOEXCEPT{
			return "Form: Grade too low!";
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Form &ref);

#endif