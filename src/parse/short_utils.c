/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:30:23 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 22:33:34 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlenspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
		if (str[i] == '\"')
			skip_quote(str, &i, '\"', '\\');
		if (str[i] == '\'')
			skip_quote(str, &i, '\'', FALSE);
	}
	return (i);
}
