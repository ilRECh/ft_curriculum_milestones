#include "replace.hpp"

void	usage()
{
	std::cout	<< "\n\tusage:\t./replace <filename> <s1> <s2>\n" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		return (replace(argv[1], argv[2], argv[3]));
	else
		usage();
	return (0);
}
