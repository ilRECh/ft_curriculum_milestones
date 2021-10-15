/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:42:11 by name              #+#    #+#             */
/*   Updated: 2021/10/03 15:42:26 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// считаю габариты карты x & y
t_point		map_len(char **maps)
{
	t_point	point;

	point.x = (point.y = 0);
	while (maps[point.y][point.x])
		point.x++;
	while (maps[point.y])
		point.y++;
	return (point);
}

t_win	*mlx_create( int width, int height )
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, width, height, "default");
	return (win);
}

bool	game(t_all *all)
{
	t_image	img;

	all->map_size = map_len(all->map);
	all->win = mlx_create(all->screen_size.x, all->screen_size.y);
// Задаю задний фон
	set_background(all);
// Вставка стены 1
	img = xpm_to_image(all, all->textures[0]);
	image_to_window(all, &img, point_set(0, 0));
	image_free(all, &img, false);

	img = xpm_to_image(all, all->textures[1]);
	image_to_window(all, &img, point_set(img.size.x, 0));
	image_free(all, &img, false);

	draw_mini_map(all);
	return (false);
}