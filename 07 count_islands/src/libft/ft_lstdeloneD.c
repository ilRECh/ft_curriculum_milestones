/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeloneD.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:39:19 by name              #+#    #+#             */
/*   Updated: 2021/09/29 14:16:19 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeloneD(t_dlist *lst, void (*del)(void *))
{
	t_dlist	*prev;
	t_dlist	*next;

	if (lst)
	{
		if (del)
			(*del)(lst->content);
		prev = lst->prev;
		next = lst->next;
		if (next)
			next->prev = prev;
		if (prev)
			prev->next = next;
		free(lst);
	}
}
