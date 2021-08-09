#include "minishell.h"

int	ft_pwd(char **args)
{
	if (args[1]
		&& error_str("pwd: too many arguments"))
		return (1);
	printf("%s\n", getvalue("PWD"));
	return (0);
}
