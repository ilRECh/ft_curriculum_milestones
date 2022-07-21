/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_on_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:42:43 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:28:24 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	in_circle(t_player *plr, float radius, t_dpoint i)
{
	float	distance;
	float	pow1;
	float	pow2;

	pow1 = powf(plr->x - i.x, 2.);
	pow2 = powf(plr->y - i.y, 2.);
	distance = sqrtf(pow1 + pow2);
	if (distance <= radius)
	{
		if ((radius - distance) < 0.05)
			return (2);
		return (1);
	}
	return (0);
}

void	player_in_map(t_all *all, t_image *img)
{
	t_dpoint	i;
	t_dpoint	to;
	int			ret;

	i.x = all->plr->x - 0.5f;
	i.y = all->plr->y - 0.5f;
	to.x = all->plr->x + 0.5f;
	to.y = all->plr->y + 0.5f;
	while (i.y <= to.y)
	{
		while (i.x <= to.x)
		{
			ret = in_circle(all->plr, 0.5f, i);
			if (ret == 2)
				pixel_put(img, conv_dtop(\
					dpnt_multiple(i, dpnt_s(all->scale))), 0xFF0000);
			i.x += 0.05;
		}
		i.y += 0.05;
		i.x = all->plr->x - 0.5f;
	}
}
