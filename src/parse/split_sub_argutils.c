/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sub_argutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:21:27 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/26 22:27:47 by csamuro          ###   ########.fr       */
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
	free(*(parse->argv));
	free((parse->argv));
	if (is_builtins(trimmer(((char *)lst->head->content), "\"\'")))
		beg = ft_strdup(trimmer(((char *)lst->head->content), "\"\'"));
	else
		beg = is_util_exists(trimmer(((char *)lst->head->content), "\"\'"));
	if (beg)
	{
		free(lst->head->content);
		lst->head->content = beg;
	}
	else
		ft_lstadd_front(lst, NULL);
	lst_trimmer(lst);
	parse->argv = list_to_char2(lst);
	ft_lstclear(lst, NULL);
	free(lst);
	return (parse);
}

void	sub_repetat(t_list *lst, char **str, int *i)
{
	ft_lstadd_back(lst, ft_strndup(*str, *i));
	(*str) += (*i);
	while (*(*str) && ft_isspace(*(*str)))
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
			while (str[i] && !ft_isspace(str[i]))
				if (sub_sub_quote(str, &i))
					break ;
			sub_repetat(lst, &str, &i);
		}
		else if (!str[i] || ft_isspace(str[i]))
			sub_repetat(lst, &str, &i);
	}
	return (to_separate_util_args(tosub_pars, lst));
}

t_list	*split_sub_argutils(t_list *lst)
{
	t_parse	*parse;

	lst->cur = lst->head;
	while (lst->cur)
	{
		parse = (t_parse *)lst->cur->content;
		if (!**parse->argv && parse->oper > 0 && parse->oper < 5)
			return ((t_list *)ret_perr("redirection from/to is empty"));
		if (parse->argv && *parse->argv \
		&& !(parse->oper > 4 && parse->oper < 9) \
		&& !ft_strncmp(CASE, *parse->argv, ft_strlen(CASE)))
		{
			if (!split_sub_argutils((\
			(t_list *)((t_parse *)lst->cur->content)->argv[1])))
				return (NULL);
		}
		else if (parse->argv && *parse->argv
			&& !(parse->oper > 4 && parse->oper < 9))
			lst->cur->content = sub_parse(parse);
		lst->cur = lst->cur->next;
	}
	if (!check_line_lst(lst))
		return (NULL);
	return (lst);
}
