/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:01:57 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/03 23:00:12 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getvalue(char *word)
{
	int	iter_1;

	iter_1 = 0;
	while (TRUE)
	{
		if (environment[iter_1]
			&& ft_strncmp(word, environment[iter_1], ft_strlen(word)))
			iter_1++;
		else if (environment[iter_1])
			return (environment[iter_1] + ft_strlen(word) + 1);
		else
			break ;
	}
	return (NULL);
}
