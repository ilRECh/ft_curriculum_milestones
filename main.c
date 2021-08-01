#include "minishell.h"

char	**environ;

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	free(__environ);
	return (0);
}