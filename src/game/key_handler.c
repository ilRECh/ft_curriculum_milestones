/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:54:44 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 15:43:04 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_in_radius(char **map, t_dpoint pnt, float radius)
{
	int			i;

	i = -1;
	while (++i < 360)
		if (map [(int)(pnt.y + (cos(degToRad(i)) * radius))] \
				[(int)(pnt.x + (sin(degToRad(i)) * radius))] == '1')
			return (false);
	return (true);
}

int	close_x( void )
{
	exit(EXIT_SUCCESS);
}

void	key_handler(int key_code, t_all *all)
{
	if (key_code == KEY_A)
		all->plr->dir += degToRad(5);
	else if (key_code == KEY_D)
		all->plr->dir -= degToRad(5);
	else if (key_code == KEY_W)
	{
		if (check_in_radius(all->map, dpnt_plus(conv_pltod(*all->plr), \
			dpnt_set(sinf(all->plr->dir) / 2, 0)), 0.3f))
			all->plr->x += sinf(all->plr->dir) * 0.33;
		if (check_in_radius(all->map, dpnt_plus(conv_pltod(*all->plr), \
			dpnt_set(0, cosf(all->plr->dir) / 2)), 0.3f))
			all->plr->y += cosf(all->plr->dir) * 0.33;
	}
	else if (key_code == KEY_S)
	{
		if (check_in_radius(all->map, dpnt_minus(conv_pltod(*all->plr), \
			dpnt_set(sinf(all->plr->dir) / 2, 0)), 0.3f))
			all->plr->x -= sinf(all->plr->dir) * 0.33;
		if (check_in_radius(all->map, dpnt_minus(conv_pltod(*all->plr), \
			dpnt_set(0, cosf(all->plr->dir) / 2)), 0.3f))
			all->plr->y -= cosf(all->plr->dir) * 0.33;
	}
	if (key_code == KEY_ESC)
		exit (0);
}
