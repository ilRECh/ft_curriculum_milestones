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

void	key_handler(int key_code, t_all *all)
{
	if (key_code == 126)
		all->plr->y -= 2;
	else if (key_code == 125)
		all->plr->y += 2;
	else if (key_code == 124)
		all->plr->x += 2;
	else if (key_code == 123)
		all->plr->x -= 2;
	else if (key_code == 0)
		all->plr->dir += 0.1f;
	else if (key_code == 2)
		all->plr->dir -= 0.1f;
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
}

int	key_hook(int key_code, t_all *all)
{
	printf("key = %d\n", key_code);
	key_handler(key_code, all);
// Инициализирую буффер если не инит, и закрашиваю землю и небо
	// image_to_image_cp(all->buff, &all->whalls[0], point_set(50, 50));
	// image_to_image_cp(all->buff, &all->whalls[1], point_set(all->whalls[0].size.x + 50, 50));
	set_background(all);
// Записываем стены в общий буфер
// Записываем карту в общий буфер (all->buff)
	draw_mini_map(all);
	player_in_map(all, all->img_map);
	image_to_image_cp_insert_clr(all->buff, all->img_map, point_set(0, 0), 0xFF000000);
// Выводим буфер в окно
	image_to_window(all, all->buff, point_set(0, 0));
	return (0);
}

bool	game(t_all *all)
{
	init(all);
	key_hook(-1, all);
	mlx_hook(all->win->win, 2, 1L<<1, key_hook, all);
	// mlx_key_hook(all->win->win, key_hook, all);
	return (false);
}