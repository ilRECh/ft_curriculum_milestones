#include "count_islands.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (count(argv[1]));
	else
		usage();
	return (0);
}
