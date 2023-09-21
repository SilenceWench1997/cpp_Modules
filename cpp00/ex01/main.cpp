#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"


int main()
{
	Phonebook	book;
	std::string	user_input;

	while (user_input.compare("EXIT"))
	{
		std::cout << "\n_________________________" << std::endl;
		std::cout << "Write ADD, SEARCH or EXIT" << std::endl;
		std::cin >> user_input;
		if (std::cin.eof())
			break ;
		if (!user_input.compare("ADD"))
			book.addContact();
		else if (!user_input.compare("SEARCH"))
		{
			book.printList();
			book.searchContact();
		}
	}
	return (0);
}
