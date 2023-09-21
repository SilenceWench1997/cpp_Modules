#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

void	Contact::init(int index)
{
	std::cout << "first name: " << std::flush;
	std::cin >> this->fname;
	std::cout << "last name: " << std::flush;
	std::cin >> this->lname;
	std::cout << "nickname: " << std::flush;
	std::cin >> this->nname;
	std::cout << "phone number: " << std::flush;
	std::cin >>	this->phone_number;
	std::cout << "darkest secret: " << std::flush;
	std::cin >> this->dark_sec;
	this->index = index + 48;
	if (this->fname.empty() || this->lname.empty() || this->nname.empty()
	|| this->phone_number.empty() || this->dark_sec.empty())
	{
		std::cout << "\nNo empty fields\n";
		return ;
	}
	std::cout << "Contact successfully added, index: " << index << "\n";
}

std::string	Contact::fixWidth(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return (str);
}

void	Contact::printInfo()
{
	std::cout << "First Name: " << this->fname << std::endl;
	std::cout << "Last Name: " << this->lname << std::endl;
	std::cout << "Nickname: " << this->nname << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->dark_sec << std::endl;
}

void	Contact::printContact()
{
    std::cout << "|" << std::setw(10) << this->index << std::flush;
    std::cout << "|" << std::setw(10) << fixWidth(this->fname) << std::flush;
    std::cout << "|" << std::setw(10) << fixWidth(this->lname) << std::flush;
    std::cout << "|" << std::setw(10) << fixWidth(this->nname) << std::flush;
    std::cout << "|" << std::endl;
}