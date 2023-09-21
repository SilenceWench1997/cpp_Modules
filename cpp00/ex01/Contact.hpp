#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    char		index;
	std::string fixWidth(std::string str);
    std::string phone_number;
    std::string	fname;
    std::string	lname;
    std::string	nname;
    std::string	dark_sec;
public:
	void	init(int index);
	void	printContact();
	void	printInfo();
};

#endif
