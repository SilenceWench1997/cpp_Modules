#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->fixedVal = 0;
}

Fixed::Fixed(const int n)
{
	this->fixedVal = n * (1 << this->bits);
}

Fixed::Fixed(const float fl)
{
	this->fixedVal = std::roundf(fl * (1 << this->bits));
}

Fixed::Fixed(const Fixed &src)
{
	this->fixedVal = src.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed &src)
{
	this->fixedVal = src.getRawBits();
	return (*this);
}

//---------------Convert---------------//

float	Fixed::toFloat(void) const
{
	return (static_cast<float>( this->getRawBits() ) / ( 1 << this->bits ));
}

int	Fixed::toInt(void) const
{
	return (this->fixedVal >> this->bits);
}

void	Fixed::setRawBits(int set)
{
	this->fixedVal = set;
}

int	Fixed::getRawBits() const
{
	return (this->fixedVal);
}

std::ostream& operator<<(std::ostream &ostr, const Fixed& obj)
{
	ostr << obj.toFloat();
	return (ostr);
}

//----------------- Comparison -----------------//

bool Fixed::operator>(const Fixed &comp) const
{
	return (this->getRawBits() > comp.getRawBits());
}

bool Fixed::operator<(const Fixed &comp) const
{
	return (this->getRawBits() < comp.getRawBits());	
}

bool Fixed::operator>=(const Fixed &comp) const
{
	return (this->getRawBits() >= comp.getRawBits());
}

bool Fixed::operator<=(const Fixed &comp) const
{
	return (this->getRawBits() <= comp.getRawBits());
}

bool Fixed::operator==(const Fixed &comp) const
{
	return (this->getRawBits() == comp.getRawBits());
}

//----------------- Multiply/Divide/Add/Subtract -----------------//

Fixed	Fixed::operator*(const Fixed &mult) const
{
	Fixed tmp(this->toFloat() * mult.toFloat());
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &div) const
{
	Fixed tmp(this->toFloat() / div.toFloat());
	return (tmp);
}

Fixed	Fixed::operator+(const Fixed &add) const
{
	Fixed tmp(this->toFloat() + add.toFloat());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &subt) const
{
	Fixed tmp(this->toFloat() - subt.toFloat());
	return (tmp);
}

//----------------- Increment/Decrement -----------------//

Fixed	&Fixed::operator++(void)
{
	this->fixedVal++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed copy(*this);
	this->fixedVal++;
	return (copy);
}

Fixed	&Fixed::operator--(void)
{
	this->fixedVal--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed copy(*this);
	this->fixedVal--;
	return (copy);
}
//----------------- Min/Max -----------------//

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}
