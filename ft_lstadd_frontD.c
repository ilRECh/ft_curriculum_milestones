/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_frontD.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:28:48 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:30:00 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_frontD(t_dlist **lst, void *cont)
{
	t_dlist	*new;

	if (!lst)
		return ;
	new = ft_lstnewD(cont);
	if (!new)
		return ;
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}
