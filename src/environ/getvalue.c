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

	iter_1 = 0;
	while (TRUE)
	{
		res = ft_strncmp(word, g_env[iter_1], ft_strlen(word));
		if ((g_env[iter_1] && res)
			|| (g_env[iter_1]
			&& g_env[iter_1][ft_strlen(word)] != '='))
			iter_1++;
		else if (g_env[iter_1]
			&& g_env[iter_1][ft_strlen(word)] == '=')
			return (g_env[iter_1] + ft_strlen(word) + 1);
		else
			break ;
	}
	return (NULL);
}
