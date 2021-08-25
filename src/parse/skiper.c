/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skiper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:21:22 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 22:33:32 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	case_skip(char **ln)
{
	int	cases;

	cases = 1;
	while (*(*ln) && *++(*ln) && cases)
	{
		if (*(*ln) == '(')
			cases++;
		if (*(*ln) == ')')
			cases--;
	}
}

void	skip_quotation(char **ln)
{
	if (**ln == '\"' && *(*ln - 1) != '\\')
	{
		while (*++(*ln) != '\"' || *(*ln - 1) == '\\')
			;
		++(*ln);
	}
	if (**ln == '\'' && *(*ln - 1) != '\\')
	{
		while (*++(*ln) != '\'' || *(*ln - 1) == '\\')
			;
		++(*ln);
	}
}

_Bool	skip_open_case(char **ln)
{
	int	cnt_case;

	cnt_case = 1;
	while (*++(*ln) && cnt_case)
	{
		skip_quotation(ln);
		if (**ln == ')')
			cnt_case--;
		else if (**ln == '(')
			cnt_case++;
	}
	if (cnt_case)
		return (FALSE);
	return (TRUE);
}

int	skip_quote(char *str, int *k, char quote, char is_slash)
{
	int	i;

	i = (*k) + 1;
	if (is_slash)
	{
		while ((str[++i] && str[i] != quote)
			|| (str[i] == quote && str[i - 1] == '\\'))
			;
	}
	else
		while ((str[++i] && str[i] != quote))
			;
	return (*k = i + 1);
}
