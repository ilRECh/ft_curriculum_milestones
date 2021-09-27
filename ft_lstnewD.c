/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewD.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:07:08 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:28:01 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstnewD(void *content)
{
	t_dlist	*new_elem;

	new_elem = ft_calloc(1, sizeof(t_dlist));
	if (new_elem)
		new_elem->content = content;
	return (new_elem);
}
