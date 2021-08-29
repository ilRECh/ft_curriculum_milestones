/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 23:02:48 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/29 01:09:22 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	**create_new(int *iter_1)
{
	char	**new_env;

	*iter_1 = -1;
	new_env = ft_calloc(var_count(g_param->env) + 2, sizeof(char *));
	while (g_param->env && g_param->env[++*iter_1])
	{
		new_env[*iter_1] = ft_strdup(g_param->env[*iter_1]);
		free(g_param->env[*iter_1]);
	}
	free(g_param->env);
	return (new_env);
}

void	add_to_env(char **split)
{
	char	*tmp;
	char	**new_env;
	int		iter_1;

	if (!split[1])
		return ;
	if (getvalue(split[0]))
	{
		setvalue(split[0], split[1]);
		return ;
	}
	new_env = create_new(&iter_1);
	tmp = ft_strjoin(split[0], "=");
	if (iter_1 < 0)
		iter_1 = 0;
	if (tmp && iter_1 >= 0)
	{
		new_env[iter_1] = ft_strjoin(tmp, split[1]);
		free(tmp);
		g_param->env = new_env;
	}
	else
		ft_exit(NULL);
}
