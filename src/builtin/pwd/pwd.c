#include "minishell.h"

int	ft_pwd(void)
{
	printf("%s\n", getvalue("PWD"));
	return (0);
}
