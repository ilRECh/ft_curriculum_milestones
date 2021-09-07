/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimmer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:21:38 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 22:33:23 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trimmer(char *str, char *c)
{
	short	x;

	if (!str)
		return (str);
	if (*str && ft_strchr(c, *str))
		ft_memmove(str, &str[1], ft_strlen(str));
	x = ft_strlen(str) - 1;
	if (str[x] && ft_strchr(c, str[x]))
	{
		str[x] = 0;
		x = ft_strlen(str) - 1;
	}
	return (str);
}
