#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
	int		size;
public:
	std::string	fixWidth(std::string str);
	void		printList();
	void		addContact();
	void		searchContact();
	Phonebook();
};

#endif
