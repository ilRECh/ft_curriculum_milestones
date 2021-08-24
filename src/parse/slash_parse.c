/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slash_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 01:49:29 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/25 01:49:31 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static	void	set_char(char *str, char set)
{
	ft_memmove(str, &str[1], ft_strlen(str));
	*str = set;
}

static void	apply_slash_full(char *str)
{
	if (ft_strnstr(str, "\\t", 2))
		set_char(str, '\t');
	else if (ft_strnstr(str, "\\v", 2))
		set_char(str, '\v');
	else if (ft_strnstr(str, "\\n", 2))
		set_char(str, '\n');
	else if (ft_strnstr(str, "\\s", 2))
		set_char(str, ' ');
	else if (*str == '\\')
		ft_memmove(str, &str[1], ft_strlen(str));
}

static void	apply_slash_mini(char *str)
{
	ft_memmove(str, &str[1], ft_strlen(str));
}

char	*slash_parse(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			skip_quote(str, &i, '\'', 0);
		if (str[i] == '\"' && (!i || str[i - 1] != '\\'))
			while (str[++i] != '\"')
				apply_slash_full(&str[i]);
		if (str[i] == '\\')
			apply_slash_mini(&str[i]);
	}
	return (str);
}
