#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &ref);
	~Intern();
	Intern &operator=(const Intern &ref);
	AForm *makeForm(std::string name, std::string target);
};

#endif