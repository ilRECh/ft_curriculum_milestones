#include "minishell.h"

int	print_exp(void)
{
	int	iter_1;

	iter_1 = -1;
	while (g_param->exprt && g_param->exprt[++iter_1])
	{
		write(1, g_param->exprt[iter_1], ft_strlen(g_param->exprt[iter_1]));
		write(1, "\n", 1);
	}
	return (0);
}