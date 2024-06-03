#include "Karen.hpp"

static void	usage()
{
	std::cout << "\n\tusage:\t./karenFilter <level>\n" << std::endl;
}

int	main(int argc, char **argv)
{
	Karen	karen;

	if (argc == 2)
	{
		switch (HashIt(argv[1]))
		{
			case 745:
				std::cout << "[ DEBUG ]" << "\n";
				karen.complain("DEBUG");
				std::cout << std::endl;
				__attribute__ ((fallthrough));
			case 459:
				std::cout << "[ INFO ]" << "\n";
				karen.complain("INFO");
				std::cout << std::endl;
				__attribute__ ((fallthrough));
			case 1578:
				std::cout << "[ WARNING ]" << "\n";
				karen.complain("WARNING");
				std::cout << std::endl;
				__attribute__ ((fallthrough));
			case 816:
				std::cout << "[ ERROR ]" << "\n";
				karen.complain("ERROR");
				std::cout << std::endl;
				break ;
			default:
				std::cout	<< "[ Probably complaining about "
							"insignificant problems ]" << std::endl;
		}
	}
	else
		usage();
	return (0);
}
