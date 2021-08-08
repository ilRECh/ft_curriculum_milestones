/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:43 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:00:45 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstnew(void *content)
{
	t_dlist	*new_elem;

	new_elem = (t_dlist *)ft_calloc(1, sizeof(t_dlist));
	if (new_elem)
		new_elem->content = content;
	return (new_elem);
}
