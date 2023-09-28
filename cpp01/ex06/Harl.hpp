#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	Harl();
	~Harl();
	void	complain (std::string level);
	int		harlNum(std::string str);
	void	harlSwitch (int num);
};

#endif