#include "fdf.h"

static inline void	usage(void)
{
	ft_printf("\n\tusage:\t" CYAN "./fdf <map_name.fdf>\n\n" RESET);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	else
		fdf(argv[1]);
	return (0);
}