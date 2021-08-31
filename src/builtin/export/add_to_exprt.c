/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_exprt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 23:06:40 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/31 19:02:32 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**create_new(int *iter_1)
{
	char	**new_exprt;

	*iter_1 = -1;
	new_exprt = ft_calloc(var_count(g_param->exprt) + 2, sizeof(char *));
	while (g_param->exprt && g_param->exprt[++*iter_1])
	{
		new_exprt[*iter_1] = ft_strdup(g_param->exprt[*iter_1]);
		free(g_param->exprt[*iter_1]);
	}
	free(g_param->exprt);
	return (new_exprt);
}

void	add_to_exprt(char **split)
{
	char	*tmp;
	char	**new_exprt;
	int		iter_1;

	if (getvalue_exprt(split[0]) && split[1])
	{
		setvalue_exprt(split[0], split[1]);
		return ;
	}
	else if (getvalue_exprt(split[0]))
		return ;
	new_exprt = create_new(&iter_1);
	tmp = ft_strjoin(split[0], "=");
	if (iter_1 < 0)
		iter_1 = 0;
	if (tmp && iter_1 >= 0)
	{
		if (split[1])
			new_exprt[iter_1] = ft_strjoin(tmp, split[1]);
		else
			new_exprt[iter_1] = ft_strdup(tmp);
		free(tmp), (g_param->exprt = new_exprt);
	}
	else
		ft_exit(NULL);
}
