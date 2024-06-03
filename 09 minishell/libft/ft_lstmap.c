/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:40 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:00:41 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	ft_lstmap(t_list lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	new_lst;

	ft_lst_init(1, &new_lst);
	if (!f)
		return (new_lst);
	lst.cur = lst.head;
	while (lst.cur)
	{
		ft_lstadd_back(&new_lst, (*f)(lst.cur->content));
		if (del)
			(*del)(lst.cur->content);
		lst.cur = lst.cur->next;
		new_lst.cur = new_lst.cur->next;
	}
	return (new_lst);
}
