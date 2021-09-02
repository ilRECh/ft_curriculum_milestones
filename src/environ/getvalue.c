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

void	remove_local(char *str)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	len_local;

	i = 0;
	l = 0;
	len_local = 0;
	while (g_param->locals && g_param->locals[len_local])
		len_local++;
	if (!len_local)
		return ;
	while (str[l] && !ft_isspace(str[l]))
		l++;
	while (g_param->locals && g_param->locals[i]
		&& (ft_strncmp(g_param->locals[i], str, l) && g_param->locals[i][l] != '='))
		i++;
	if (g_param->locals && g_param->locals[i] && !ft_strncmp(g_param->locals[i], str, l) && g_param->locals[i][l] == '=')
	{
		free (g_param->locals[i]);
		if (i < len_local)
			ft_memmove(&g_param->locals[i], \
			&g_param->locals[i + 1], sizeof(char **) * (len_local - i));
	}
		
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
