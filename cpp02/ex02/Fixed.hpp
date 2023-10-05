#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					fixedVal;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &src);
	~Fixed();

	Fixed& operator=(const Fixed &src);
	bool operator>(const Fixed &comp) const;
	bool operator<(const Fixed &comp) const;
	bool operator<=(const Fixed &comp) const;
	bool operator>=(const Fixed &comp) const;
	bool operator==(const Fixed &comp) const;

	Fixed	operator*(const Fixed &mult) const;
	Fixed	operator/(const Fixed &div) const;
	Fixed	operator+(const Fixed &add) const;
	Fixed	operator-(const Fixed &subt) const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);


	int		getRawBits(void) const;
	void	setRawBits(int const set);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &ostr, const Fixed& obj);

#endif