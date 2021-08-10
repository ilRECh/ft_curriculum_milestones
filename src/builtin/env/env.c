#include "minishell.h"

int	ft_env(char	**args)
{
	char	**tmp;

	if (args[1]
		&& error_str("env: too many arguments"))
		return (1);
	tmp = g_param->env;
	while (tmp && *tmp)
		printf("%s\n", *tmp++);
	return (0);
}
