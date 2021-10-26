/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plr_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:54:27 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 14:54:35 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_plrpos(t_all *all)
{
	t_point	i;

	i = pnt_s(-1);
	while (++i.y < all->map_size.y)
	{
		while (++i.x < all->map_size.x)
		{
			if (ft_strchr("EWSN", all->map[i.y][i.x]))
			{
				all->plrpos.direction = all->map[i.y][i.x];
				all->plrpos.x = i.x;
				all->plrpos.y = i.y;
				all->map[i.y][i.x] = '0';
				i.y = all->map_size.y;
				break ;
			}
		}
		i.x = -1;
	}
}

// Вызов должен быть осуществлен строго после ( set_plrpos(t_all, map_size); )
void	set_plr(t_all *all, float x, float y, float direction)
{
	all->plr = malloc(sizeof(t_plr));
	all->plr->x = x;
	all->plr->y = y;
	all->plr->dir = direction;
}
