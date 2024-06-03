/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skiper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:21:22 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/03 02:16:29 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotation(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = -1;
	tmp = lst;
	tmp->cur = tmp->head->next;
	while (tmp->cur)
	{
		while (((char *)(tmp->cur->content))[++i])
			if (ft_strchr("\'\"", ((char *)tmp->cur->content)[i]))
				ft_memmove(&tmp->cur->content[i],
					&tmp->cur->content[i + 1],
					ft_strlen(&tmp->cur->content[i]));
		i = -1;
		tmp->cur = tmp->cur->next;
	}
}

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

int	skip_quote(char *str, int *k, char quote)
{
	int	i;

	i = 0;
	if (k)
		i = (*k) + 1;
	if (quote == '\"')
	{
		while ((str[++i] && str[i] != quote)
			|| (str[i] == quote && str[i - 1] == '\\'))
			;
	}
	else
		while ((str[++i] && str[i] != quote))
			;
	if (k)
		return (*k = i + 1);
	else
		return (i + 1);
}
