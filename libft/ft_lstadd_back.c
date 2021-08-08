/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:04 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:00:06 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	error(t_dlist *new, t_list *lst)
{
	if (!new && write(1, RED "ERROR: " RESET "FT_LSTADD_BACK.\n", 34))
	{
		ft_lstclear(lst, free);
		exit(1);
	}
}

void	ft_lstadd_back(t_list *lst, void *content)
{
	t_dlist	*new;

	if (!lst)
		return ;
	new = ft_lstnew(content);
	error(new, lst);
	if (ft_lstsize(*lst) > 0)
	{
		lst->end->next = lst->head;
		new->next = lst->head;
		new->prev = lst->end;
		lst->end->next = new;
		lst->head->prev = new;
		lst->end = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		lst->head = new;
		lst->end = new;
	}
	lst->end->next = NULL;
}
