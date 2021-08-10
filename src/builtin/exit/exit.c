#include "minishell.h"

int	ft_exit(char** args)
{
	if (args[2]
		&& error_str("exit: too many arguments"))
		return (1);
	if (args[1])
		exit(ft_atoi(args[1]));
	else
		exit(0);
	return (0);
}
