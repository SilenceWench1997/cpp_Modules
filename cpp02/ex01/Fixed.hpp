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
	Fixed& operator=(const Fixed &src);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const set);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &ostr, Fixed const& obj);

#endif