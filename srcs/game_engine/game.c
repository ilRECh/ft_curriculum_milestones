/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:42:11 by name              #+#    #+#             */
/*   Updated: 2022/07/22 09:42:03 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point    align_to_screen(t_point screen, t_point image, int8_t mode)
{
    t_point    position;

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

int    key_hook(int key_code, t_all *all)
{
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

void game(t_all *all)
{
    all->screen_size = pnt_set(1024, 768);
    init(all);
    key_hook(-1, all);
    mlx_hook(all->win->win, 17, 0, &close_x, NULL);
    mlx_hook(all->win->win, 2, 1L << 0, key_hook, all);
	mlx_do_key_autorepeatoff(all->win->mlx);
    mlx_do_sync(all->win->mlx);
    mlx_loop(all->win->mlx);
}
