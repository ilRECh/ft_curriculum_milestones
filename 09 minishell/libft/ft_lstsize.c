/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:47 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:00:49 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list lst)
{
	int	count;

	lst.cur = lst.head;
	count = 0;
	while (lst.cur)
	{
		count++;
		lst.cur = lst.cur->next;
	}
	return (count);
}
