#include "minishell.h"

int	ft_echo(char **argv)
{
	uint8_t	flag_nl;

	if (!ft_strncmp(argv[1], "-n", 2))
	{
		argv += 2;
		flag_nl = 0;
	}
	else
	{
		argv += 1;
		flag_nl = 1;
	}
	while (argv && *argv)
		printf("%s", *argv++);
	if (flag_nl)
		printf("\n");
	return (0);
}
