/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_from_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:43:57 by name              #+#    #+#             */
/*   Updated: 2021/09/30 09:48:47 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_for_empty_lines(t_all *all, t_list *lst)
{
	
}

bool	make_map_from_lst(t_all *all, t_list *lst)
{
	if (check_for_empty_lines(all, lst))
		return ((all->err
			= ft_strdup("map contains empty lines. Unforgivable.")), true);
	return (false);
}
