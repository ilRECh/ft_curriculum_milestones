/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:23 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:00:25 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstindex(t_list lst)
{
	int	index;

	index = 0;
	while (lst.head && lst.head != lst.cur)
	{
		lst.head = lst.head->next;
		index++;
	}
	if (!lst.head)
		return (-1);
	return (index);
}
