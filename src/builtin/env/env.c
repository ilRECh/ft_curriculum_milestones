#include "minishell.h"

int	ft_env(void)
{
	char	**tmp;

	tmp = g_env;
	while (tmp && *tmp)
		printf("%s\n", *tmp++);
	return (0);
}
