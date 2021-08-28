/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:51:30 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/27 15:51:30 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setvalue(char *word, char *new_value)
{
	int		iter_1;
	char	*tmp;

	iter_1 = 0;
	while (g_param->env[iter_1])
	{
		if (!ft_strncmp(g_param->env[iter_1], word, ft_strlen(word))
			&& g_param->env[iter_1][ft_strlen(word)] == '=')
			break ;
		iter_1++;
	}
	if (!g_param->env[iter_1])
		return (1);
	tmp = ft_strjoin(word, "=");
	free(g_param->env[iter_1]);
	g_param->env[iter_1] = ft_strjoin(tmp, new_value);
	free(tmp);
	return (0);
}

int	setvalue_exprt(char *word, char *new_value)
{
	int		iter_1;
	char	*tmp;

	iter_1 = 0;
	while (g_param->exprt[iter_1])
	{
		if (!ft_strncmp(g_param->exprt[iter_1], word, ft_strlen(word))
			&& g_param->exprt[iter_1][ft_strlen(word)] == '=')
			break ;
		iter_1++;
	}
	if (!g_param->exprt[iter_1])
		return (1);
	tmp = ft_strjoin(word, "=");
	free(g_param->exprt[iter_1]);
	g_param->exprt[iter_1] = ft_strjoin(tmp, new_value);
	free(tmp);
	return (0);
}
