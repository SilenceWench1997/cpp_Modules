#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
	Bureaucrat bur("bureau", 3);
	ShrubberyCreationForm scf("scrub");
	PresidentialPardonForm ppf("targ");
	RobotomyRequestForm rrf("smth");

	std::cout << "---------------Signing and execution-------------" << std::endl;
	std::cout << "\n------------Shrubbery Creation Form--------------" << std::endl;
	bur.signForm(scf);
	bur.executeForm(scf);
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "\n------------Presidential pardon form-------------" << std::endl;
	bur.signForm(ppf);
	bur.executeForm(ppf);
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "\n------------Robotomy Request form----------------" << std::endl;
	bur.signForm(rrf);
	bur.executeForm(rrf);
	bur.executeForm(rrf);
	bur.executeForm(rrf);
	std::cout << "-------------------------------------------------" << std::endl;
}
