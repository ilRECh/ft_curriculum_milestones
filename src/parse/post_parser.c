/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:28:20 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/26 19:27:15 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static _Bool	check_cmp(t_dlist *dlst)
{
	if ((((t_parse *)dlst)->argv && !((t_parse *)dlst)->argv[0]) && \
	(!(t_parse *)dlst->prev || \
	!((t_parse *)dlst->prev)->argv || !((t_parse *)dlst->prev)->argv[0]) && \
	!((t_parse *)dlst)->oper)
		return (TRUE);
	return (FALSE);
}

// _Bool	must_be_next(t_dlist *el)
// {
// 	t_parse	**plst;
// 	uint8_t	x;

// 	x = 4;
// 	plst = ft_calloc(x, sizeof(t_parse *));
// 	while (x-- && el)
// 	{
// 		plst[3 - x] = ((t_parse *)el->content);
// 		el = el->next;
// 	}
// 	if ((!ft_strncmp(plst[0]->argv[0], CASE, ft_strlen(CASE))) && \
// 		plst[1] && plst[1]->argv && \
// 		((!plst[1]->argv[0] && plst[1]->argv[1]) || (plst[1]->argv[0] && plst[1]->oper))
// 	)
// 	{
// 		free(plst);
// 		return (TRUE);
// 	}
// 	free(plst);
// 	return(FALSE);
// }

_Bool	post_parser(t_list *lst)
{
	_Bool	is_was_file_redir;

	lst->cur = lst->head;
	is_was_file_redir = FALSE;
	while (lst->cur && !is_was_file_redir)
	{
		is_was_file_redir = check_cmp(lst->cur)/* | must_be_next(lst->cur)*/;
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
