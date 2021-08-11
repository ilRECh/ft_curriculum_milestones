#include "minishell.h"

struct s_counters
{
	int	iter_env;
	int	iter_exprt;
	int	env;
	int	exprt;
};

static int	clean_(char **env)
{
	int	iter_1;

	if (!env || !*env)
		return (1);
	iter_1 = 0;
	while (env[iter_1])
		free(env[iter_1++]);
	free(env);
	return (1);
}

static int	check_var(char *var)
{
	int	iter_1;

	iter_1 = -1;
	if (ft_strlen(var) == 0 || var[0] == '=')
		return (1);
	while (var[++iter_1] && var[iter_1] != '=')
	{
		if (ft_isspace(var[iter_1])
			&& error_str("export: not valid in this context: ")
			&& printf("%s\n", var))
			return (1);
	}
	return (0);
}

static struct s_counters	ft_count(char **var)
{
	struct s_counters	cnt;

	cnt.env = 0;
	cnt.exprt = 0;
	while (var && *var)
	{
		if (check_var(*var))
			break ;
		if (ft_strchr(*var, '=') && ft_strlen(ft_strchr(*var, '=') + 1))
		{
			if (!getvalue_exprt(*var))
				++cnt.exprt;
			if (!getvalue(*var))
				++cnt.env;
		}
		else
			if (!getvalue_exprt(*var))
				++cnt.exprt;
		var++;
	}
	return (cnt);
}

static void	copy(char **env, char **exprt,
		char **vars, struct s_counters cnt)
{
	char	*tmp;

	if (cnt.iter_env < 0)
		cnt.iter_env = 0;
	if (cnt.iter_exprt < 0)
		cnt.iter_exprt = 0;
	while (vars && *vars)
	{
		if (ft_strchr(*vars, '='))
			tmp = ft_strndup(*vars, ft_strchr(*vars, '=') - *vars);
		else
			tmp = NULL;
		if (tmp && g_param->env && getvalue(tmp))
			setvalue(tmp, ft_strchr(*vars, '=') + 1);
		else if (tmp && ft_strlen(tmp + 1))
			env[cnt.iter_env++] = ft_strdup(*vars);
		if (tmp && g_param->exprt && getvalue_exprt(tmp))
			setvalue_exprt(tmp, ft_strchr(*vars, '=') + 1);
		else
			exprt[cnt.iter_exprt++] = ft_strdup(*vars);
		vars++;
		free(tmp);
	}
}

int	ft_export(char **args)
{
	struct s_counters	cnt;
	char				**environ_;
	char				**exprt;

	if (!args[0])
		return (print_exp());
	cnt = ft_count(args);
	cnt.iter_env = -1;
	cnt.iter_exprt = -1;
	environ_ = ft_calloc(ft_count(g_param->env).env
		+ cnt.env + 1, sizeof(char *));
	exprt = ft_calloc(ft_count(g_param->exprt).exprt + ft_count(g_param->exprt).env
		+ cnt.exprt + 1, sizeof(char *));
	if ((!environ_ || !exprt) && clean_(environ_) && clean_(exprt))
		return (1);
	while (g_param->env && g_param->env[++cnt.iter_env])
		environ_[cnt.iter_env] = ft_strdup(g_param->env[cnt.iter_env]);
	while (g_param->exprt && g_param->exprt[++cnt.iter_exprt])
		exprt[cnt.iter_exprt] = ft_strdup(g_param->exprt[cnt.iter_exprt]);
	copy(environ_, exprt, args, cnt);
	clean_(g_param->env), clean_(g_param->exprt);
	g_param->env = environ_;
	g_param->exprt = exprt;
	return (0);
}
