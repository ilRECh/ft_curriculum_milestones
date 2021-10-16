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
	t_image	img_whall[2];
	t_image	*img_map;

	all->map_size = map_len(all->map);
	all->win = mlx_create(all->screen_size.x, all->screen_size.y);

// Задаю задний фон и стартовые позиции игрока
	set_background(all);
	set_plrpos(all);
	set_plr(all, all->plrpos.x, all->plrpos.y, 0.5f);
// стены
	img_whall[0] = xpm_to_image(all, all->textures[0]);
	img_whall[1] = xpm_to_image(all, all->textures[1]);

// Записываем стены в общий буфер
	image_to_image_cp(all->buff, &img_whall[0], point_set(50, 50));
	image_to_image_cp(all->buff, &img_whall[1], point_set(img_whall[0].size.x + 50, 50));

// Записываем карту в общий буфер (all->buff)
	img_map = draw_mini_map(all);
	image_to_image_cp_insert_clr(all->buff, img_map, point_set(321, 123), 0xFF000000);
	image_free(all, img_map, true);

// фришим стены
	image_free(all, &img_whall[0], false);
	image_free(all, &img_whall[1], false);


// Выводим буфер в окно
	image_to_window(all, all->buff, point_set(0, 0));

// Фришим буфер
	image_free(all, all->buff, true);
	return (false);
}