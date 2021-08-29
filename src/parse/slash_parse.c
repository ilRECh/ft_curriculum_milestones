/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slash_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 01:49:29 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/29 15:46:02 by csamuro          ###   ########.fr       */
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
	if (*str == '\\')
	{
		if (*++str == 'f')
			set_char(str - 1, '\f');
		else if (*str == '0')
			set_char(str - 1, '\0');
		else if (*str == 'a')
			set_char(str - 1, '\a');
		else if (*str == 'b')
			set_char(str - 1, '\b');
		else if (*str == 'r')
			set_char(str - 1, '\r');
		else if (*str == 'v')
			set_char(str - 1, '\v');
		else if (*str == 'n')
			set_char(str - 1, '\n');
		else if (*str == 't')
			set_char(str - 1, '\t');
		else if (*str == 's')
			set_char(str - 1, ' ');
		else if (*str == '\\')
			ft_memmove(str - 1, str, ft_strlen(str - 1));
	}
}

char	*slash_parse(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			skip_quote(str, &i, '\'');
		if (str[i] == '\"' && (!i || str[i - 1] != '\\'))
			while (str[++i] != '\"')
				apply_slash_full(&str[i]);
		if (str[i] == '\\')
			ft_memmove(&str[i], &str[i + 1], ft_strlen(&str[i]));
	}
	return (str);
}
