/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_frontS.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:47:45 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:02:37 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_frontS(t_slist **lst, void *cont)
{
	t_slist	*new;

	if (!lst)
		return ;
	new = ft_lstnewS(cont);
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
