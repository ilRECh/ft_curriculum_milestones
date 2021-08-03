#include "minishell.h"

static void	clean_(char **env)
{
	int	iter_1;

	iter_1 = 0;
	while (env[iter_1])
		free(env[iter_1++]);
	free(env);
}

static int	ft_count(char **vars)
{
	int	count;

	count = 0;
	while (vars && *vars++)
		count++;
	return (count);
}

static void	copy_to_env(char **environ_, char **vars, int iter_1)
{
	char	*tmp;

	tmp = environ_[iter_1 - 1];
	iter_1 -= 1;
	while (vars && *vars)
	{
		if (ft_strlen(*vars) == 1 && **vars == '='
			&& error_str("Bad assigment"))
			return ;
		environ_[iter_1++] = ft_strdup(*vars++);
	}
	environ_[iter_1] = tmp;
}

int	ft_export(char **vars)
{
	int		cur_vars;
	int		iter_1;
	char	**environ_;

	cur_vars = 0;
	iter_1 = 0;
	while (environ[iter_1++])
		cur_vars++;
	environ_ = ft_calloc(cur_vars + ft_count(vars) + 1, sizeof(char *));
	iter_1 = 0;
	while (environ[iter_1])
	{
		environ_[iter_1] = ft_strdup(environ[iter_1]);
		iter_1++;
	}
	copy_to_env(environ_, vars, iter_1);
	clean_(vars);
	clean_(environ);
	environ = environ_;
	return (0);
}
