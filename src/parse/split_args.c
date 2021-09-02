/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:21:27 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/29 20:00:08 by csamuro          ###   ########.fr       */
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

t_parse	*to_separate_util_args(t_parse *parse, t_list *lst)
{
	char	*beg;
	int		i;

	i = 0;
	beg = NULL;
	free(*(parse->argv));
	free((parse->argv));
	if (!parse->oper)
	{
		if (is_builtins(((char *)lst->head->content)))
			beg = ft_strdup(((char *)lst->head->content));
		else
			beg = is_util_exists(((char *)lst->head->content));
		free(lst->head->content);
		lst->head->content = beg;
	}
	else
		ft_lstadd_front(lst, NULL);
	parse->argv = list_to_char2(lst);
	while (parse->argv && (parse->argv[i] || (!i && parse->argv[++i])))
	{
		trimmer(parse->argv[i], "\"\'");
		i++;
	}
	// trimmer(lst->head->content, "\"\'");
	ft_lstclear(lst, NULL);
	free(lst);
	return (parse);
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
	_Bool	chk;
	int		i;

	i = -1;
	chk = FALSE;
	str = *(tosub_pars->argv);
	lst = (t_list *)ft_calloc(sizeof(t_list), 1);
	while (*str)
	{
		if (ft_strchr("\"\'", str[++i]) && (!i || str[i - 1] != '\\'))
		{
			while (str[i] && !ft_isspace(str[i])
				&& (&str[i] == *(tosub_pars->argv) || str[i - 1] != '\\'))
				if (sub_sub_quote(str, &i))
					break ;
			sub_repetat(lst, &str, &i);
		}
		else if (!str[i] || (ft_isspace(str[i])
				&& (&str[i] == *(tosub_pars->argv) || str[i - 1] != '\\')))
			sub_repetat(lst, &str, &i);
	}
	return (to_separate_util_args(tosub_pars, lst));
}

t_list	*split_args(t_list *l)
{
	t_parse	*p;

	l->cur = l->head;
	while (l->cur)
	{
		p = (t_parse *)l->cur->content;
		if (p->argv && *p->argv && !ft_strncmp(CASE, *p->argv, 13))
			if (!split_args(((t_list *)((t_parse *)l->cur->content)->argv[1])))
				return (NULL);
		if (p->argv && *p->argv && ft_strncmp(CASE, *p->argv, 13))
		{
			if (dollr(p))
			{
				ft_lstdelone(l, free_parse);
				if (l->cur && l->cur->content
					&& !((t_parse *)(l->cur->content))->argv)
					ft_lstdelone(l, free_parse);
				continue ;
			}
			l->cur->content = sub_parse(p);
		}
		l->cur = l->cur->next;
	}
	if (!l->head)
	{
		free(l);
		return ((void *)1);
	}
	return (check_line_lst(l));
}
