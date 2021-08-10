#include "minishell.h"

static void	clean_(char **env)
{
	int	iter_1;

	if (!env || !*env)
		return ;
	iter_1 = 0;
	while (env[iter_1])
		free(env[iter_1++]);
	free(env);
}

static int	check_var(char *var, bool set_to_exp)
{
	int	iter_1;

	iter_1 = -1;
	if (ft_strlen(var) == 0 || var[0] == '=')
		return (1);
	while (set_to_exp && var[++iter_1] && var[iter_1] != '=')
	{
		if (ft_isspace(var[iter_1])
			&& error_str("export: not valid in this context: ")
			&& printf("%s\n", var))
			return (1);
	}
	return (0);
}

static int	ft_count(char **var, bool set_to_exp)
{
	int	count;

	count = 0;
	while (var && *var)
	{
		if (check_var(*var, set_to_exp))
			break ;
		if (!(set_to_exp && !ft_strlen(ft_strchr(*var, '=') + 1))
			&& !getvalue(*var))
			count++;
		var++;
	}
	return (count);
}

static void	copy_to_env(char **environ_, char **vars,
		int iter_1, int vars_cnt)
{
	char	*tmp;

	while (vars && *vars && vars_cnt--)
	{
		tmp = ft_strndup(*vars, ft_strchr(*vars, '=') - *vars);
		if (getvalue(tmp))
		{
			setvalue(tmp, ft_strchr(*vars, '=') + 1);
			vars++;
		}
		else
			environ_[++iter_1] = ft_strdup(*vars++);
		free(tmp);
	}
}

static int	ft_export_proceed(char **args, char ***env, bool set_to_exp)
{
	int		vars_cnt;
	int		iter_1;
	char	**environ_;

	vars_cnt = ft_count(args, set_to_exp);
	iter_1 = -1;
	environ_ = ft_calloc(ft_count(*env, FALSE) + vars_cnt + 1, sizeof(char *));
	if (!environ_)
		return (1);
	while (env && *env && (*env)[++iter_1])
		environ_[iter_1] = ft_strdup((*env)[iter_1]);
	copy_to_env(environ_ , args, iter_1, vars_cnt);
	clean_(*env);
	*env = environ_;
	// if (set_to_exp)
	// 	ft_export(args, &g_param.exprt, FALSE);
	return (0);
}

int	ft_export(char **args)
{
	if (!args[0])
		return (print_exp());
	ft_export_proceed(args, &g_param.env, TRUE);
	ft_export_proceed(args, &g_param.exprt, FALSE);
	return (0);
}
