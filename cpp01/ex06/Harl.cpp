#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	if (!level.empty())
	{
		std::string	levels[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};
		void (Harl::*fctArr[4])(void) = { 
			&Harl::debug, 
			&Harl::info, 
			&Harl::warning, 
			&Harl::error 
		};
		for (int i = 0; i <= 3; i++){
			if (level == levels[i])
				(this->*(fctArr[i]))();
		}
	}
}

int	Harl::harlNum(std::string str)
{
	std::string	levels[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
	};
	for (int i = 0; i <= 3; i++){
		if (levels[i] == str)
			return (i);
	}
	return (42);
}

void	Harl::harlSwitch(int num)
{
	switch (num)
	{
		case 0:
			this->complain("DEBUG");
			break ;
		case 1:
			this->complain("INFO");
			break ;
		case 2:
			this->complain("WARNING");
			break ;
		case 3:
			this->complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}