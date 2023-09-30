#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					num;
	static const int	bits;
public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed& operator=(const Fixed &src);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const set);
};

#endif