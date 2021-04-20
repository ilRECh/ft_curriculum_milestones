/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 22:11:41 by vcobbler          #+#    #+#             */
/*   Updated: 2021/02/18 22:18:54 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *tmp;

	if (begin_list == NULL)
		return ;
	while (begin_list != NULL)
	{
		(*free_fct)(begin_list->data);
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp);
	}
}
