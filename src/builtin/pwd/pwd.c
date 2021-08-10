#include "minishell.h"

int	ft_pwd(char **args)
{
	if (args[2])
		printf("pwd: too many arguments\n");
	else
		printf("%s\n", getvalue("PWD"));
	return (0);
}
