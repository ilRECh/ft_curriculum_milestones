/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:54:59 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/03 22:23:22 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse	*to_separate_util_args(t_parse *parse, t_list *lst)
{
	char	*beg;

	free_tabs(parse->argv);
	parse->argv = NULL;
	if (!parse->oper)
	{
		if (is_builtins(((char *)lst->head->content)))
			beg = ft_strdup(((char *)lst->head->content));
		else
			beg = is_util_exists(((char *)lst->head->content));
		if (!beg && ft_lstsize(*lst) == 1)
		{
			free (parse);
			return ((void *)1);
		}
		free(lst->head->content);
		lst->head->content = beg;
	}
	else
		ft_lstadd_front(lst, NULL);
	parse->argv = list_to_char2(lst);
	if ((parse->argv[0] || parse->argv[1]))
		return (parse);
	free_parse(parse);
	return ((void *)1);
}

void	sub_repetat(t_list *lst, char **str, int *i)
{
	ft_lstadd_back(lst, ft_strndup(*str, *i));
	(*str) += (*i);
	while (*(*str) && (ft_isspace(*(*str))))
		(*str)++;
	(*i) = -1;
}

t_parse	*sub_parse(t_parse *tosub_pars)
{
	t_list	*lst;
	char	*str;
	int		i;

	i = -1;
	str = *(tosub_pars->argv);
	lst = (t_list *)ft_calloc(sizeof(t_list), 1);
	while (*str)
	{
		if (ft_strchr("\"\'", str[++i]) && (!i || str[i - 1] != '\\'))
		{
			while (str[i] && !ft_isspace(str[i]) && (!i || str[i - 1] != '\\'))
				if (sub_sub_quote(str, &i))
					break ;
			sub_repetat(lst, &str, &i);
		}
		else if (!str[i] || (ft_isspace(str[i]) && (!i || str[i - 1] != '\\')))
			sub_repetat(lst, &str, &i);
	}
	if (!lst->head)
		return (NULL);
	tosub_pars = to_separate_util_args(tosub_pars, lst);
	ft_lstclear(lst, free);
	free (lst);
	return (tosub_pars);
}

static _Bool	sub_split_args(t_list *l)
{
	ft_lstdelone(l, free_parse);
	if (l->cur && (((t_parse *)(l->cur->content))->oper != 5
		&& ((t_parse *)(l->cur->content))->oper != 0))
		return (TRUE);
	if (l->cur && !((t_parse *)(l->cur->content))->argv)
		ft_lstdelone(l, free_parse);
	return (FALSE);
}

t_list	*split_args(t_list *l)
{
	t_parse	*p;

	while (l->cur)
	{
		p = (t_parse *)l->cur->content;
		if (p->argv && *p->argv && !ft_strncmp(CASE, *p->argv, 13))
			if (!split_args(((t_list *)p->argv[1])))
				return (NULL);
		else if (p->argv && *p->argv)
		{
			if (dollr(p, l))
			{
				if (sub_split_args(l))
					return ((void *)2);
				if (!l || !l->head)
					return ((void *)1);
				continue ;
			}
			l->cur->content = sub_parse(p);
			if (l->cur->content == (void *)1 && l->cur->content--)
				return ((void *)2);
		}
		l->cur = l->cur->next;
	}
	return (check_line_lst(l));
}

	// if (l->head > (t_dlist *)2)
	// return ((void *)1);