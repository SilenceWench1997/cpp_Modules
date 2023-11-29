#ifndef RB_RE_F_HPP
# define RB_RE_F_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
	void execute(Bureaucrat const & executor) const;
	static	AForm *clone(std::string target);
};

#endif