#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedVal = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedVal = src.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//-----------Int and Float constructors------------//

Fixed::Fixed(const float fl)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedVal = std::roundf(fl * (1 << this->bits));
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedVal = n * (1 << this->bits);
}

//-----------------------------------------------//

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedVal = src.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int set)
{
	this->fixedVal = set;
}

int	Fixed::getRawBits() const
{
	return (this->fixedVal);
}

//-------------------toFloat and toInt-----------------//

float	Fixed::toFloat(void) const
{
	return (static_cast<float>( this->getRawBits() ) / ( 1 << this->bits ));
}

int	Fixed::toInt(void) const
{
	return (this->fixedVal >> this->bits);
}

//------------------------------------------------------//

//-------------------"<<" operator-----------------//

std::ostream& operator<<(std::ostream &ostr, Fixed const& obj)
{
	ostr << obj.toFloat();
	return (ostr);
}

//-------------------------------------------------//