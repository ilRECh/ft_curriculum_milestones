#include "cub3d.h"

#define MLX_RED 0x800000
#define MLX_GRN 0x008000
#define MLX_BLU 0x000080
#define MLX_BLK 0x000000
#define MLX_WHT 0xFFFFFF
#define MLX_GRY 0x666666

unsigned int color_set_by_map(char c)
{
	if (c == '1')
		return (MLX_WHT);
	else if (c == '0')
		return (MLX_GRY);
	return (0xFF000000);
}

// закрашиваю квадратик пикселей
void	drow_big_pixel(char c, t_image *img, t_point scale, t_point	px)
{
	t_point			i;
	t_point			to;
	unsigned int 	colour;

	colour = color_set_by_map(c);
	scale = pnt_s(max_min(scale.x, scale.y, true));
	i = pnt_multiple(px, scale);
	to = pnt_plus(i, scale);
	i = pnt_plus(i, pnt_s(-1));
	while (++i.y <= to.y)
	{
		while (++i.x <= to.x)
		{
			if (colour != 0xFF000000 && (i.x == to.x || i.y == to.y))
				pixel_put(img, pnt_plus(px, i), 0x00116633);
			else
				pixel_put(img, pnt_plus(px, i), colour);
		}
		i.x = to.x - scale.x - 1;
	}
}

// закрашиваю круг пикселей
int	in_circle(t_plr *plr, float radius, t_dpoint i)
{
	float	distance;
	float	pow1;
	float	pow2;

	// radius /= 3;
	pow1 = powf(plr->x - i.x, 2.);
	pow2 = powf(plr->y - i.y, 2.);
	distance = sqrtf(pow1 + pow2);
	// distance = sqrtf(powf(plr->x - 1 - i.x, 2.) + powf(plr->y - 1 - i.y, 2.));
	if (distance <= radius)
	{
		if ((radius - distance) < 0.05)
			return (2);
		return (1);
	}
	return (0);
}

void	drow_circle(t_image *img, t_all *all)
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
			if (ret)
			{
				if (ret == 1)
					pixel_put(img, conv_dtop(dpnt_multiple(i, dpnt_s(SCALE >> 2))), 0xFF0000);
				else
					pixel_put(img, conv_dtop(dpnt_multiple(i, dpnt_s(SCALE >> 2))), 0x880011FF);
			}
			i.x += 0.05;
		}
		i.y += 0.05;
		i.x = all->plr->x - 0.5f;
	}
}

void	draw_line(t_image *img_map, t_dpoint p1, t_dpoint p2, int color)
{
	t_dpoint	t;
	int			step;

	step = 300;
	t.x = (p1.x - p2.x) / step;
	t.y = (p1.y - p2.y) / step;
	while (step --> 0)
	{
		pixel_put(img_map, pnt_set(p1.x -1, p1.y -1), color);
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
	p1 = dpnt_multiple(p1, dpnt_s(SCALE >> 2));
	// p1.x = img_map->size.x / p1.x;
	// p1.y = img_map->size.y / p1.y;
	p2 = p1;
	c = 10.0f;
	p1.x -= sin(all->plr->dir) * c;
	p1.y -= cos(all->plr->dir) * c;
	draw_line(all->img_map, p1, p2, 0x00FF00);
	// draw_raycast(all);
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

// Рисую позицию и направлене игрока на карте
void	player_in_map(t_all *all, t_image *img_map)
{
	// t_plr	plr;

	// plr = *all->plr;
	// all->plr->x *= img_map->size.x / all->map_size.x;
	// all->plr->y *= img_map->size.y / all->map_size.y;
	drow_circle(img_map, all);
}


