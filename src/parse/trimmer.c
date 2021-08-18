/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimmer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:21:38 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/18 06:21:39 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*trimmer(char *str, char *c)
{
	short	x;

	if (!str)
		return (str);
	while (*str && ft_strchr(c, *str))
		ft_memmove(str, &str[1], ft_strlen(str));
	x = ft_strlen(str) - 1;
	while (str[x] && ft_strchr(c, str[x]))
	{
		str[x] = 0;
		x = ft_strlen(str) - 1;
	}
	return (str);
}
