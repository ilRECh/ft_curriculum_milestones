/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:55 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/10 20:35:37 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_arg(char *arg)
{
	int	iter_1;

	iter_1 = -1;
	while (arg[++iter_1])
	{
		if (!isalpha(arg[iter_1])
			&& error_str("unset: not valid argument: ")
			&& printf("%s\n", arg))
			return (0);
	}
	return (1);
}

static void	unset_from_env(char *to_unset)
{
	char	*tmp;
	int		iter_1;

	iter_1 = -1;
	if (getvalue(to_unset))
	{
		tmp = getvalue(to_unset) - ft_strlen(to_unset) - 1;
		while (g_param->env && g_param->env[++iter_1]
			&& g_param->env[iter_1] != tmp)
			;
		free(g_param->env[iter_1]);
		while (g_param->env && g_param->env[iter_1])
		{
			g_param->env[iter_1] = g_param->env[iter_1 + 1];
			iter_1++;
		}
	}
}

static void	unset_from_exprt(char *to_unset)
{
	char	*tmp;
	int		iter_1;

	iter_1 = -1;
	if (getvalue_exprt(to_unset))
	{
		tmp = getvalue_exprt(to_unset) - ft_strlen(to_unset) - 1;
		while (g_param->exprt && g_param->exprt[++iter_1]
			&& g_param->exprt[iter_1] != tmp)
			;
		free(g_param->exprt[iter_1]);
		while (g_param->exprt && g_param->exprt[iter_1])
		{
			g_param->exprt[iter_1] = g_param->exprt[iter_1 + 1];
			iter_1++;
		}
	}
}

int	ft_unset(char **args)
{
	int	iter_1;

	if (!args[1])
		error_str("unset: not enough arguments\n");
	iter_1 = -1;
	while (args[++iter_1] && check_arg(args[iter_1]))
	{
		unset_from_env(args[iter_1]);
		unset_from_exprt(args[iter_1]);
	}
	return (0);
}
