#include "minishell.h"

static inline void	copy_to_env(char **environ_, char **vars)
{
	free(*environ_);
	while (vars && *vars)
		(*environ_ = ft_strdup(*vars++)), ++environ_;
	*environ_ = NULL;
}

static int	check_var(char *var)
{
	int	iter_1;

	iter_1 = -1;
	if (ft_strlen(var) == 0)
		return (1);
	while (var[++iter_1])
		if (!ft_isalpha(var[iter_1]))
			return (1);
	return (0);
}

static char	**ft_index(char *var)
{
	char	**tmp_env;
	char	*tmp;

	tmp = getvalue(var);
	if (tmp)
	{
		tmp = tmp - ft_strlen(var) - 1;
		tmp_env = g_param->env;
		while (tmp_env && *tmp_env && *tmp_env != tmp)
			tmp_env++;
		return (tmp_env);
	}
	return (NULL);	
}

int	ft_unset(char **vars)
{
	int		iter_1;
	char	**tmp;

	iter_1 = -1;
	while (vars && vars[++iter_1])
		if (check_var(vars[iter_1])
			&& error_str("unset: ")
			&& printf("%s", vars[iter_1])
			&& printf(" :invalid parameter or name\n"))
			return (1);
	while (vars && *vars)
	{
		tmp = ft_index(*vars++);
		if (tmp)
			copy_to_env(tmp, tmp + 1);
	}
	return (0);
}
