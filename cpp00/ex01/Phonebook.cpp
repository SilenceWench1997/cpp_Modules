#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void	Phonebook::printList()
{
	std::cout << "\n-------------------Contacts------------------\n";
    std::cout << "|" << std::setw(10) << "Index" << std::flush;
    std::cout << "|" << std::setw(10) << "First Name" << std::flush;
    std::cout << "|" << std::setw(10) << "Last Name"<< std::flush;
    std::cout << "|" << std::setw(10) << "Nickname"<< std::flush;
    std::cout << "|" << std::endl;
	for(int i = 0; i <= this->size - 1; i++)
	{
		std::cout << "|-------------------------------------------|\n";
		this->contacts[i].printContact();

	}
	std::cout << "---------------------------------------------\n";
}

void	Phonebook::searchContact()
{
	std::string i = "1";
	if (this->size <= 0 || this->size > 8)
	{
		std::cout << "Phonebook is empty, add contact first\n";
		return ;	
	}
	while (1)
	{
		std::cout << "Enter index from 0 to " << this->size - 1 << ": ";
		std::cin >> i;
		if (std::cin.eof())
			exit(1);
		else if ((i.size() > 1) || (i[0] - 48) > this->size - 1 || (i[0] - 48) < 0)
		{
			std::cout << "Contact not found, try again\n";
			continue ;
		}
		this->contacts[i[0] - 48].printInfo();
		break ;
	}
}

void	Phonebook::addContact()
{
	static int i = 0;

	this->contacts[i % 8].init(i % 8);
	if (i < 8)
		this->size = i + 1;
	i++;
}