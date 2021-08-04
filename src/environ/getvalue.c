/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:01:57 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/04 19:38:59 by vcobbler         ###   ########.fr       */
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
		res = ft_strncmp(word, environment[iter_1], ft_strlen(word));
		if ((environment[iter_1] && res)
			|| (environment[iter_1]
			&& environment[iter_1][ft_strlen(word)] != '='))
			iter_1++;
		else if (environment[iter_1]
			&& environment[iter_1][ft_strlen(word)] == '=')
			return (environment[iter_1] + ft_strlen(word) + 1);
		else
			break ;
	}
	return (NULL);
}
