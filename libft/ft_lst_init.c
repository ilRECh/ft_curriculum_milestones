/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:00 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:00:02 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_init(int args, ...)
{
	va_list	arg;
	t_list	*lst;

	va_start(arg, args);
	while (args-- > 0)
	{
		lst = va_arg(arg, t_list *);
		lst->head = NULL;
		lst->cur = NULL;
		lst->end = NULL;
	}
	va_end(arg);
}
