#include "minishell.h"

int	setvalue(char *word, char *new_value)
{
	int		iter_1;
	char	*tmp;

	iter_1 = 0;
	while (environment[iter_1])
	{
		if (!ft_strncmp(environment[iter_1], word, ft_strlen(word))
			&& environment[iter_1][ft_strlen(word)] == '=')
			break ;
		iter_1++;
	}
	printf("%p\n", environment[iter_1]);
	if (!environment[iter_1])
		return (1);
	tmp = ft_strjoin(word, "=");
	free(environment[iter_1]);
	environment[iter_1] = ft_strjoin(tmp, new_value);
	free(tmp);
	return (0);
}