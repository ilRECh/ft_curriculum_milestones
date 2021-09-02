/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 20:12:09 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/27 20:12:09 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setvalue(char *word, char *new_value)
{
	int		iter_1;
	char	*tmp;

	iter_1 = 0;
	while (g_param->env && g_param->env[iter_1])
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

int	setval_local(char *word, char *new_value)
{
	int		iter_1;

	iter_1 = 0;
	remove_local(word);
	if (!g_param->locals)
		g_param->locals = ft_calloc(sizeof(char *), 100);
	while (g_param->locals[iter_1])
		iter_1++;
	g_param->locals[iter_1] = \
	ft_strjoin_free(word, ft_strjoin_free("=", new_value, 2), 3);
	return (0);
}

int	setvalue_exprt(char *word, char *new_value)
{
	int		iter_1;
	char	*tmp;

	iter_1 = 0;
	while (g_param->exprt && g_param->exprt[iter_1])
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
