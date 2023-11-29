#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
private:
	const std::string name;
	bool isSigned;
	const int gradeSign;
	const int gradeExec;
public:
	AForm();
	AForm(const AForm &ref);
	AForm(std::string name, bool iS, const int gS, const int gE);
	AForm &operator=(const AForm &ref);
	virtual ~AForm();
	std::string	getName() const;
	bool	getIsSigned() const;
	int	getGradeSign() const;
	int	getGradeExec() const;
	void	beSigned(const Bureaucrat &ref);
	virtual void	execute(Bureaucrat const & executor) const = 0;
	class GradeTooHighException : std::exception{
	public:
		virtual const char *what() const noexcept{
			return "Grade too high!";
		}
	};
	class GradeTooLowException : std::exception{
	public:
		virtual const char *what() const noexcept{
			return "Grade too low!";
		}
	};
	class FormNotSignedException : std::exception{
	public:
		virtual const char *what() const noexcept{
			return "AForm is not signed!";
		}
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &ref);

#endif
