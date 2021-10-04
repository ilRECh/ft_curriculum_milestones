#include <iostream>

#define RED		"\033[0;31m"
#define CYAN	"\033[0;36m"
#define RESET	"\033[0m"

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << RED << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::cout << CYAN;
			for (int j = 0; argv[i][j]; ++j)
			{
				std::cout  << (char)toupper(argv[i][j]);
			}
			std::cout << RESET;
		}
		std::cout << std::endl;
	}
}
