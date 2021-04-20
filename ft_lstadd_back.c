/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:08:06 by vcobbler          #+#    #+#             */
/*   Updated: 2021/02/18 20:43:54 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *tmp;

	tmp = *begin_list;
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break ;
	}
	tmp->next = ft_create_elem(data);
}
