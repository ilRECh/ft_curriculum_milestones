/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:18:12 by vcobbler          #+#    #+#             */
/*   Updated: 2021/02/18 20:35:19 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list *new_elem;

	new_elem = NULL;
	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem != NULL)
	{
		new_elem->data = data;
		new_elem->next = NULL;
	}
	return (new_elem);
}
