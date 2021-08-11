#include "minishell.h"

int	print_exp(void)
{
	int	iter_1;

	iter_1 = -1;
	while (g_param->exprt && g_param->exprt[++iter_1])
		printf("%s\n", g_param->exprt[iter_1]);
	return (0);
}