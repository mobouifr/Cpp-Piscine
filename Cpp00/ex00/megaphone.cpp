#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	int	j = 1;
	while (j < argc)
	{
		std::string arg = argv[j];
		int	i = 0;
		while (i < (int)arg.length())
		{
			std::cout << (char)std::toupper(arg[i]);  
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return (0); 
}