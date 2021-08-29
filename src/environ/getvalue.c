/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:01:57 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/07 10:54:13 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getvalue(char *word)
{
	int	iter_1;
	int	res;

	if (!g_param->env)
		return (NULL);
	iter_1 = 0;
	while (TRUE)
	{
		res = ft_strncmp(word, g_param->env[iter_1], ft_strlen(word));
		if ((g_param->env[iter_1] && res)
			|| (g_param->env[iter_1]
				&& g_param->env[iter_1][ft_strlen(word)] != '='))
			iter_1++;
		else if (g_param->env[iter_1]
			&& g_param->env[iter_1][ft_strlen(word)] == '=')
			return (g_param->env[iter_1] + ft_strlen(word) + 1);
		else
			break ;
	}
	return (NULL);
}

char	*getval_local(char *word)
{
	int	iter_1;
	int	res;

	if (!g_param->locals)
		return (NULL);
	iter_1 = 0;
	while (TRUE)
	{
		res = ft_strncmp(word, g_param->locals[iter_1], ft_strlen(word));
		if ((g_param->locals[iter_1] && res)
			|| (g_param->locals[iter_1]
				&& g_param->locals[iter_1][ft_strlen(word)] != '='))
			iter_1++;
		else if (g_param->locals[iter_1]
			&& g_param->locals[iter_1][ft_strlen(word)] == '=')
			return (g_param->locals[iter_1] + ft_strlen(word) + 1);
		else
			break ;
	}
	return (NULL);
}

char	*getvalue_exprt(char *word)
{
	int	iter_1;
	int	res;

	if (!g_param->exprt)
		return (NULL);
	iter_1 = 0;
	while (TRUE)
	{
		res = ft_strncmp(word, g_param->exprt[iter_1], ft_strlen(word));
		if ((g_param->exprt[iter_1] && res)
			|| (g_param->exprt[iter_1]
				&& g_param->exprt[iter_1][ft_strlen(word)] != '='))
			iter_1++;
		else if (g_param->exprt[iter_1]
			&& g_param->exprt[iter_1][ft_strlen(word)] == '=')
			return (g_param->exprt[iter_1] + ft_strlen(word) + 1);
		else
			break ;
	}
	return (NULL);
}
