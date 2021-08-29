/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:17 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:00:19 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	change_fields(t_list *lst)
{
	if (lst->cur == lst->head)
	{
		lst->head = lst->cur->next;
		lst->head->prev = NULL;
	}
	else if (lst->cur == lst->end)
	{
		lst->end = lst->cur->prev;
		lst->cur->prev->next = NULL;
	}
	else
	{
		lst->cur->prev->next = lst->cur->next;
		lst->cur->next->prev = lst->cur->prev;
	}
	lst->cur->prev = NULL;
	lst->cur->next = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	int		lst_size;
	t_dlist	*tmp;

	if (!lst || !lst->cur)
		return ;
	lst->head->prev = NULL;
	tmp = lst->cur->next;
	lst_size = ft_lstsize(*lst);
	if (lst_size > 1)
		change_fields(lst);
	if (del)
		(*del)(lst->cur->content);
	free(lst->cur);
	if (lst_size == 1)
	{
		lst->head = NULL;
		lst->end = NULL;
	}
	lst->cur = tmp;
	lst->end = NULL;
}
