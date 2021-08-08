#include "minishell.h"

static void	clean_(char **env)
{
	int	iter_1;

	iter_1 = 0;
	while (env[iter_1])
		free(env[iter_1++]);
	free(env);
}

static int	check_var(char *var)
{
	int	iter_1;

	iter_1 = -1;
	if (ft_strlen(var) == 0 || var[0] == '=')
		return (1);
	while (var[++iter_1] && var[iter_1] != '=')
		if (var[iter_1 + 1] == 0 || ft_isspace(var[iter_1]))
			return (1);
	return (0);
}

static int	ft_count(char **vars)
{
	int	count;

	count = 0;
	while (vars && *vars)
	{
		if (check_var(*vars)
			&& error_str("export: not valid in this context: ")
			&& printf("%s\n", *vars))
			break ;
		count++;
		vars++;
	}
	return (count);
}

static void	copy_to_env(char **environ_, char **vars,
		int iter_1, int vars_cnt)
{
	char	*tmp;

	tmp = environ_[iter_1 - 1];
	iter_1 -= 1;
	while (vars && *vars && vars_cnt--)
		environ_[iter_1++] = ft_strdup(*vars++);
	environ_[iter_1] = tmp;
}

int	ft_export(char **vars)
{
	int		vars_cnt;
	int		iter_1;
	char	**environ_;

	vars_cnt = ft_count(vars);
	iter_1 = -1;
	environ_ = ft_calloc(ft_count(g_env) + vars_cnt + 1, sizeof(char *));
	if (!environ_)
		return (1);
	while (g_env[++iter_1])
		environ_[iter_1] = ft_strdup(g_env[iter_1]);
	copy_to_env(environ_ , vars, iter_1, vars_cnt);
	clean_(vars);
	clean_(g_env);
	g_env = environ_;
	return (0);
}
