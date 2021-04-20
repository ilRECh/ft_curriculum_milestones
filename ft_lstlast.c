/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:36:34 by vcobbler          #+#    #+#             */
/*   Updated: 2021/02/18 20:00:45 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_last(t_list *begin_list)
{
	while (begin_list)
		if (begin_list->next != NULL)
			begin_list = begin_list->next;
		else
			break ;
	return (begin_list);
}
