#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	(void)rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "test");
	rrf = someRandomIntern.makeForm("robotomy request", "test");	
	rrf = someRandomIntern.makeForm("presidential pardon", "test");	

}
