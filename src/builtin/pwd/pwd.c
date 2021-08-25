#include "minishell.h"

int	ft_pwd(char **args)
{
	if (args[1])
	{
		printf("pwd: too many arguments\n");
		return (1);
	}
	else
		printf("%s\n", getvalue("PWD"));
	return (0);
}
