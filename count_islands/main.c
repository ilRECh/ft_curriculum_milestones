#include "count_islands.h"

static void	usage(void)
{
	printf(CYAN "\vusage:\t" RESET
		GREEN_BOLD "./count_islands map\v\n" RESET);
}

static int	count(char *map)
{
	t_islands	islands;

	if (parse(map, &islands))
	{
		printf(RED "Error\n" RESET
			"invalid map\n");
		return (1);
	}
	count_islands(&islands);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (count(argv[1]));
	else
		usage();
	return (0);
}
