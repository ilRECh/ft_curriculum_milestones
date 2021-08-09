#include "minishell.h"

int	setvalue(char *word, char *new_value)
{
	int		iter_1;
	char	*tmp;

	iter_1 = 0;
	while (g_env[iter_1])
	{
		if (!ft_strncmp(g_env[iter_1], word, ft_strlen(word))
			&& g_env[iter_1][ft_strlen(word)] == '=')
			break ;
		iter_1++;
	}
	printf("%p\n", g_env[iter_1]);
	if (!g_env[iter_1])
		return (1);
	tmp = ft_strjoin(word, "=");
	free(g_env[iter_1]);
	g_env[iter_1] = ft_strjoin(tmp, new_value);
	free(tmp);
	return (0);
}