/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:42:11 by name              #+#    #+#             */
/*   Updated: 2021/10/27 14:29:05 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	align_to_screen(t_point screen, t_point image, int8_t mode)
{
	t_point	position;

	position = pnt_s(0);
	if (mode & CENTER)
	{
		position.x = (screen.x - image.x) / 2;
		position.y = (screen.y - image.y) / 2;
	}
	if (mode & LEFT)
		position.x = 0;
	if (mode & RIGHT)
		position.x = screen.x - image.x;
	if (mode & UP)
		position.y = 0;
	if (mode & DOWN)
		position.y = screen.y - image.y;
	return (position);
}

int	key_hook(int key_code, t_all *all)
{
	printf("key = %d\n", key_code);
	key_handler(key_code, all);
	set_background(all);
	draw_mini_map(all);
	player_in_map(all, all->img_map);
	draw_raycast(all);
	image_to_image_cp_insert_clr(all->buff, all->img_map, \
		align_to_screen(all->buff->size, all->img_map->size, \
		CENTER | DOWN), 0xFF000000);
	image_to_window(all, all->buff, pnt_set(0, 0));
	return (0);
}

bool	game(t_all *all)
{
	init(all);
	key_hook(-1, all);
	mlx_hook(all->win->win, 17, 0, &close_x, NULL);
	mlx_hook(all->win->win, 2, 1L << 1, key_hook, all);
	return (false);
}
