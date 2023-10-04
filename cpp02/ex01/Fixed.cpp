#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->num = src.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = src.getRawBits();
	return (*this);
}

Fixed::Fixed(const int n)
{
	this->num = n * (1 << this->bits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fl)
{
	this->num = std::roundf(fl * (1 << this->bits));
	std::cout << this->num;
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
    return (static_cast<float>( this->getRawBits() ) / ( 1 << this->bits ));
}

int	Fixed::toInt(void) const
{
	return (this->num >> this->bits);
}

void	Fixed::setRawBits(int set)
{
	this->num = set;
}

int	Fixed::getRawBits() const
{
	return (this->num);
}


std::ostream& operator<<(std::ostream &ostr, const Fixed& obj)
{
	ostr << obj.toFloat();
	return (ostr);
}