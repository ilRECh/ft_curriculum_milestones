/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:14:49 by vcobbler          #+#    #+#             */
/*   Updated: 2021/02/18 20:28:51 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *replace_elem;

	replace_elem = ft_create_elem(data);
	replace_elem->next = *begin_list;
	*begin_list = replace_elem;
}
