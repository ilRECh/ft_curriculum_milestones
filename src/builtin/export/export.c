#include "minishell.h"

struct s_counters
{
	int	iter_1;
	int	vars_cnt;
};

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
		struct s_counters cnt, bool set_to_exp)
{
	char	*tmp;

	if (cnt.iter_1 < 0)
		++cnt.iter_1;
	while (vars && *vars && cnt.vars_cnt--)
	{
		tmp = ft_strndup(*vars, ft_strchr(*vars, '=') - *vars);
		if (set_to_exp && g_param->env && getvalue(tmp))
		{
			setvalue(tmp, ft_strchr(*vars, '=') + 1);
			vars++;
		}
		else if (!set_to_exp && g_param->exprt && getvalue_exprt(tmp))
		{
			setvalue_exprt(tmp, ft_strchr(*vars, '=') + 1);
			vars++;
		}
		else
			environ_[cnt.iter_1++] = ft_strdup(*vars++);
		free(tmp);
	}
}

int	ft_export(char **args, char ***env, bool set_to_exp)
{
	struct s_counters	cnt;
	char				**environ_;

	if (!args[0])
		return (print_exp());
	cnt.vars_cnt = ft_count(args, set_to_exp);
	cnt.iter_1 = -1;
	environ_ = ft_calloc(ft_count(*env, FALSE) + cnt.vars_cnt + 1, sizeof(char *));
	if (!environ_)
		return (1);
	while (env && *env && (*env)[++cnt.iter_1])
		environ_[cnt.iter_1] = ft_strdup((*env)[cnt.iter_1]);
	copy_to_env(environ_ , args, cnt, set_to_exp);
	clean_(*env);
	*env = environ_;
	if (set_to_exp)
		ft_export(args, &g_param->exprt, FALSE);
	return (0);
}
