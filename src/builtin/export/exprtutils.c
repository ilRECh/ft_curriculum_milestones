/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprtutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:14:59 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/28 19:16:26 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	var_count(char **vars)
{
	int	iter_1;

	iter_1 = -1;
	while (vars && vars[++iter_1])
		;
	if (iter_1 < 0)
		return (0);
	return (iter_1);
}

int	check_var(char *var)
{
	while (var && *var)
		if (!ft_isalpha(*var++))
			return (0);
	return (1);
}

void	free_split(char **split)
{
	if (split)
	{
		free(split[0]);
		free(split[1]);
		free(split);
	}
}
