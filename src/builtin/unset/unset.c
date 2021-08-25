/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:55 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:55:35 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct s_var
{
	char	**env;
	char	**exprt;
};

static inline void	copy(char **environ_, char **vars)
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

static struct s_var	ft_index(char *word)
{
	struct s_var	var;
	char			*env;
	char			*exprt;

	var.env = NULL;
	var.exprt = NULL;
	env = getvalue(word);
	exprt = getvalue_exprt(word);
	if (env)
	{
		env = env - ft_strlen(word) - 1;
		var.env = g_param->env;
		while (var.env && *var.env && *var.env != env)
			var.env++;
	}
	if (exprt)
	{
		exprt = exprt - ft_strlen(word) - 1;
		var.exprt = g_param->exprt;
		while (var.exprt && *var.exprt && *var.exprt != exprt)
			var.exprt++;
	}
	return (var);
}

int	ft_unset(char **args)
{
	int				iter_1;
	struct s_var	var;

	iter_1 = -1;
	while (args && args[++iter_1])
		if (check_var(args[iter_1])
			&& error_str("unset: ")
			&& printf("%s", args[iter_1])
			&& printf(" :invalid parameter or name\n"))
			return (1);
	while (args && *args)
	{
		var = ft_index(*args++);
		if (var.env)
			copy(var.env, var.env + 1);
		if (var.exprt)
			copy(var.exprt, var.exprt + 1);
	}
	return (0);
}
