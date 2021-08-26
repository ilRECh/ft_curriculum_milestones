/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:21:44 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/26 15:11:22 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  0 = no free, 1 = s1 free, 2 = s2 free, 3 = s1 & s2 free;
char	*ft_strjoin_free(char *s1, char *s2, short fr)
{
	char	*res;

	res = NULL;
	if (s1 && s2)
		res = ft_strjoin(s1, s2);
	else if (s1)
		res = ft_strdup(s1);
	else if (s2)
		res = ft_strdup(s2);
	if ((s1 && fr == 1) || (fr == 3 && s1 && s2))
		free(s1);
	if ((s2 && fr == 2) || (fr == 3 && s1 && s2))
		free(s2);
	return (res);
}

_Bool	sub_sub_quote(char *str, int *i)
{
	if ((str[(*i)] == '\"' || str[(*i)] == '\'') && str[(*i) - 1] != '\\')
		ft_memmove(&str[(*i)], &str[(*i) + 1], ft_strlen(&str[(*i)]));
	while (str[++(*i)] && (!(str[(*i)] == '\"' || str[(*i)] == '\'')
			|| ((str[(*i)] == '\"' || str[(*i)] == '\'') && \
			str[(*i) - 1] == '\\')));
	if (str[(*i)])
		ft_memmove(&str[(*i)], &str[(*i) + 1], ft_strlen(&str[(*i)]));
	else if (!str[(*i)] || ft_isspace(str[(*i) + 2]))
		return (TRUE);
	return (FALSE);
}

_Bool	check_line_lst(t_list *lst)
{
	t_dlist	*tmp;
	_Bool	b_last_one;

	tmp = lst->head;
	b_last_one = FALSE;
	while (tmp && !b_last_one)
	{
		if (tmp->content && \
		((t_parse *)(tmp->content))->argv && \
		((t_parse *)(tmp->content))->argv[0])
			b_last_one++;
		tmp = tmp->next;
	}
	return (b_last_one);
}
