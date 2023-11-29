#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat bur("bureau", 3);
	AForm* rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "test");
	std::cout << "\n------------Signing Shrubbery Creation Form--------------" << std::endl;
	bur.signForm(*rrf);
	bur.executeForm(*rrf);
	std::cout << "-----------------------------------------------------------" << std::endl;
	delete rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "test");
	std::cout << "\n------------Signing Robotomy Request Form--------------" << std::endl;
	bur.signForm(*rrf);
	bur.executeForm(*rrf);
	std::cout << "-----------------------------------------------------------" << std::endl;
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "test");
	std::cout << "\n------------Signing Presidental Pardon form--------------" << std::endl;
	bur.signForm(*rrf);
	bur.executeForm(*rrf);
	std::cout << "-----------------------------------------------------------" << std::endl;	
	delete rrf;
}
