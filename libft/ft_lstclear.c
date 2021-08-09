/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:13 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:00:15 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *lst, void (*del)(void *))
{
	if (!lst || !del || !lst->head || !lst->end)
		return ;
	lst->cur = lst->head;
	lst->end->next = NULL;
	while (lst->cur)
	{
		(*del)(lst->cur->content);
		lst->cur = lst->cur->next;
		free(lst->head);
		lst->head = lst->cur;
	}
	lst->head = NULL;
	lst->cur = NULL;
	lst->end = NULL;
}
