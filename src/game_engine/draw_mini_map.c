/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:33:02 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 16:33:05 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MLX_RED 0x800000
#define MLX_GRN 0x008000
#define MLX_BLU 0x000080
#define MLX_BLK 0x000000
#define MLX_WHT 0xFFFFFF
#define MLX_GRY 0x666666

// закрашиваю квадратик пикселей
void	drow_big_pixel(char c, t_image *img, t_point scale, t_point	px)
{
	t_point			i;
	t_point			to;
	unsigned int	colour;

	if (c == '1')
		colour = (MLX_WHT);
	else if (c == '0')
		colour = (MLX_GRY);
	else
		colour = (0xFF000000);
	scale = pnt_s(max_min(scale.x, scale.y, true));
	i = pnt_multiple(px, scale);
	to = pnt_plus(i, scale);
	i = pnt_plus(i, pnt_s(-1));
	while (++i.y <= to.y)
	{
		while (++i.x <= to.x)
			pixel_put(img, pnt_plus(px, i), colour);
		i.x = to.x - scale.x - 1;
	}
}

// закрашиваю круг пикселей

void	draw_line(t_image *img_map, t_dpoint p1, t_dpoint p2, int color)
{
	t_dpoint	t;
	int			step;

	step = 300;
	t.x = (p1.x - p2.x) / step;
	t.y = (p1.y - p2.y) / step;
	while (step -- > 0)
	{
		pixel_put(img_map, pnt_set(p1.x, p1.y), color);
		p1.x -= t.x;
		p1.y -= t.y;
	}
}

void	draw_view(t_all *all)
{
	float		c;
	t_dpoint	p1;
	t_dpoint	p2;

	p1 = conv_pltod(*all->plr);
	p1 = dpnt_multiple(p1, dpnt_s(all->scale));
	p2 = p1;
	c = 10.0f;
	p1.x -= sin(all->plr->dir) * c;
	p1.y -= cos(all->plr->dir) * c;
	draw_line(all->img_map, p1, p2, 0x00FF00);
}

// Закрашиваю изображение картой
void	draw_mini_map(t_all *all)
{
	t_point	px;
	t_point	scale;

	scale = pnt_divide(all->img_map->size, pnt_plus(all->map_size, pnt_s(1)));
	px = pnt_s(-1);
	while (all->map[++px.y])
	{
		while (all->map[px.y][++px.x])
		{
			drow_big_pixel(all->map[px.y][px.x], all->img_map, scale, px);
		}
		px.x = -1;
	}
	draw_view(all);
}
