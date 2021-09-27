/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:07:08 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:07:09 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_lstnewS(void *content)
{
	t_slist	*new_elem;

	new_elem = (t_slist *)ft_calloc(1, sizeof(t_slist));
	if (new_elem)
		new_elem->content = content;
	return (new_elem);
}
