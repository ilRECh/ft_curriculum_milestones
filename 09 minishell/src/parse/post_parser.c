/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:28:20 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/02 07:11:35 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define CHECK_SUB_LST	0
#define GET_SUB	1

static _Bool	check_cmp(t_dlist *dlst)
{
	if ((((t_parse *)dlst)->argv && !((t_parse *)dlst)->argv[0]) && \
	(!(t_parse *)dlst->prev || \
	!((t_parse *)dlst->prev)->argv || !((t_parse *)dlst->prev)->argv[0]) && \
	!((t_parse *)dlst)->oper)
		return (TRUE);
	return (FALSE);
}

t_list	*sub_hand(t_dlist *dlst, short what_to_do)
{
	void	*l;

	l = ((t_parse *)dlst->content)->argv[what_to_do];
	if (what_to_do == GET_SUB)
	{
		if (dlst->prev && ((((t_parse *)dlst->prev->content)->oper == AND) || \
		(((t_parse *)dlst->prev->content)->oper == OR)))
			return ((((t_list *)l)));
		return (NULL);
	}
	if (what_to_do == CHECK_SUB_LST)
		if (l && !ft_strncmp(CASE, ((char *)l), 12))
			return ((t_list *)1);
	return (NULL);
}

_Bool	post_parser(t_list *lst)
{
	_Bool	is_was_file_redir;

	if (!lst || !lst->head || !lst->head->content)
		return (TRUE);
	lst->cur = lst->head;
	is_was_file_redir = FALSE;
	while (lst->cur && !is_was_file_redir)
	{
		is_was_file_redir = check_cmp(lst->cur);
		if (!is_was_file_redir && ((t_parse *)lst->cur->content)->argv)
			if (sub_hand(lst->cur, CHECK_SUB_LST))
				is_was_file_redir = post_parser(sub_hand(lst->cur, GET_SUB));
		lst->cur = lst->cur->next;
	}
	if (is_was_file_redir)
	{
		if (lst->cur)
			printf("Error: not found %s\n", ((t_parse *)lst->cur)->argv[1]);
		else
			printf("Error: not valid \n");
		ft_lstclear(lst, free_parse);
	}
	return (is_was_file_redir);
}
