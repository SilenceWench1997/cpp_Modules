#ifndef SH_CR_F_HPP
# define SH_CR_F_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);
	void execute(Bureaucrat const & executor) const;
	static	AForm *clone(std::string target);
};

#endif