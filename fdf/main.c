#include "fdf.h"
#include <stdio.h>

static inline int	check_name(char *name)
{
	name += ft_strlen(name) - 4;
	if (!ft_strncmp(name, ".fdf", 4))
		return (1);
	errno = EPERM;
	return (0);
}

static inline void	usage(void)
{
	write(1, "\n\tusage:\t" CYAN "./fdf <map_name.fdf>\n\n" RESET, 43);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	else if (check_name(argv[1]))
		fdf(argv[1]);
	else
		error();
	return (0);
}
