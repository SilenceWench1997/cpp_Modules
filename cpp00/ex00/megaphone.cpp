#include <iostream>

void	print_arr(char **print, int ac)
{
	int j = 1;

	while (print[j])
	{
		std::cout << print[j];
		if (j <= ac)
			std::cout << ' ';
		j++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		for (int j = 0; argv[j]; j++)
		{
			for (int i = 0; argv[j][i]; i++)    
			{
				if (argv[j][i] >= 97 && argv[j][i] <= 122)
				argv[j][i] -= 32;
			}
		}
		print_arr(argv, argc);
		return (0);
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
