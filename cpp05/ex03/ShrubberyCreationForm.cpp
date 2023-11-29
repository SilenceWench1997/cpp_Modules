#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", 0, 145, 137), target("test"){
	std::cout << "Shrubberry Creation Form Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 0, 145, 137), target(target){
	std::cout << "Shrubberry Creation Form constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref){
	std::cout << "Shrubberry Creation Form copy constructor called" << std::endl;
	target = ref.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Shrubberry Creation Form destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref){
	std::cout << "Shrubberry Creation Form '=' overload" << std::endl;
	target = ref.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (this->getIsSigned() == 0){
		throw (FormNotSignedException());
	}
	else if (executor.getGrade() > this->getGradeExec()){
		throw (GradeTooLowException());
	}
	else{
		std::ofstream oFile(target + "_shrubbery");
		if (oFile.is_open()) {
			oFile << "                   ,           ,                :;%  %;          " << std::endl;
			oFile << "                    :         ;                   :;%;'     .,   " << std::endl;
			oFile << "           ,.        %;     %;            ;        %;'    ,;     " << std::endl;
			oFile << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'      " << std::endl;
			oFile << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'       " << std::endl;
			oFile << "               ;%;      %;        ;%;        % ;%;  ,%;'         " << std::endl;
			oFile << "                `%;.     ;%;     %;'         `;%%;.%;'           " << std::endl;
			oFile << "                 `:;%.    ;%%. %@;        %; ;@%;%'              " << std::endl;
			oFile << "                    `:%;.  :;bd%;          %;@%;'                " << std::endl;
			oFile << "                      `@%:.  :;%.         ;@@%;'                 " << std::endl;
			oFile << "                        `@%.  `;@%.      ;@@%;                   " << std::endl;
			oFile << "                          `@%%. `@%%    ;@@%;                    " << std::endl;
			oFile << "                            ;@%. :@%%  %@@%;                     " << std::endl;
			oFile << "                              %@bd%%%bd%%:;                      " << std::endl;
			oFile << "                                #@%%%%%:;;                       " << std::endl;
			oFile << "                                %@@%%%::;                        " << std::endl;
			oFile << "                                %@@@%(o);  . '                   " << std::endl;
			oFile << "                                %@@@o%;:(.,'                     " << std::endl;
			oFile << "                            `.. %@@@o%::;                        " << std::endl;
			oFile << "                               `)@@@o%::;                        " << std::endl;
			oFile << "                                %@@(o)::;                        " << std::endl;
			oFile << "                               .%@@@@%::;                        " << std::endl;
			oFile << "                               ;%@@@@%::;.                       " << std::endl;
			oFile << "                              ;%@@@@%%:;;;.                      " << std::endl;
			oFile << "                          ...;%@@@@@%%:;;;;,..                   " << std::endl;
			oFile << "      ###########################################################" << std::endl;
		}
	}
}

AForm *ShrubberyCreationForm::clone(std::string target){
	std::cout << "Shrubbery Creation Form clone called" << std::endl;
	AForm *ptr = new ShrubberyCreationForm(target);
	return (ptr);
}