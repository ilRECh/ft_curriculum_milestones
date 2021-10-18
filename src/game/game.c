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

int	key_hook(int key_code, t_all *all)
{

	printf("key = %d\n", key_code);
// Инициализирую буффер если не инит, и закрашиваю землю и небо
	set_background(all);
// Записываем стены в общий буфер
	// image_to_image_cp(all->buff, &all->whalls[0], point_set(50, 50));
	// image_to_image_cp(all->buff, &all->whalls[1], point_set(all->whalls[0].size.x + 50, 50));
// Записываем карту в общий буфер (all->buff)
	draw_mini_map(all);
	player_in_map(all, all->img_map);
	image_to_image_cp_insert_clr(all->buff, all->img_map, point_set(321, 123), 0xFF000000);
// Выводим буфер в окно
	image_to_window(all, all->buff, point_set(0, 0));
	if (key_code == 126)
		all->plr->y -= 2;
	else if (key_code == 125)
		all->plr->y += 2;
	else if (key_code == 124)
		all->plr->x += 2;
	else if (key_code == 123)
		all->plr->x -= 2;
	else if (key_code == 0)
		all->plr->dir += 0.2f;
	else if (key_code == 2)
		all->plr->dir -= 0.2f;
	else if (key_code == 13)
	{
		all->plr->x += sinf(all->plr->dir) * 2;
		all->plr->y += cosf(all->plr->dir) * 2;
	}
	else if (key_code == 1)
	{
		all->plr->x -= sinf(all->plr->dir) * 2;
		all->plr->y -= cosf(all->plr->dir) * 2;
	}

	if (key_code == 53)
	{
		// // фришим карту
		// printf("-----%%p-----\n");
		// image_free(all, all->img_map, true);
		// // фришим стены
		// printf("-----%%p-----\n");
		// image_free(all, &all->whalls[0], false);
		// printf("-----%%p-----\n");
		// image_free(all, &all->whalls[1], false);
		// // Фришим буфер
		// printf("-----%%p-----\n");
		// image_free(all, all->buff, true);
		exit (0);
	}
	return (0);
}

bool	game(t_all *all)
{
	all->map_size = map_len(all->map);
	all->win = mlx_create(all->screen_size.x, all->screen_size.y);

// Задаю стартовые позиции игрока
	set_plrpos(all);
	set_plr(all, all->plrpos.x - 0.5f, all->plrpos.y - 0.5f, 0.5f);
// стены
	all->whalls[0] = xpm_to_image(all, all->textures[0]);
	all->whalls[1] = xpm_to_image(all, all->textures[1]);
	key_hook(-1, all);
	all->plr->x *= all->img_map->size.x / all->map_size.x;
	all->plr->y *= all->img_map->size.y / all->map_size.y;
	mlx_hook(all->win->win, 2, 1L<<1, key_hook, all);
	// mlx_key_hook(all->win->win, key_hook, all);
	return (false);
}