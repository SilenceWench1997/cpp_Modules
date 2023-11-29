#ifndef PR_PA_F_HPP
# define PR_PA_F_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
	void execute(Bureaucrat const & executor) const;
	static AForm *clone(std::string target);
};

#endif