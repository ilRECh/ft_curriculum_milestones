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
	scale = point_set(max_min(scale.x, scale.y, true), max_min(scale.x, scale.y, true));
	i = point_multiple(px, scale);
	to = point_plus(i, scale);
	i = point_plus(i, point_set(-1, -1));
	while (++i.y <= to.y)
	{
		while (++i.x <= to.x)
		{
			if (colour != 0xFF000000 && (i.x == to.x || i.y == to.y))
				pixel_put(img, point_plus(px, i), 0x00116633);
			else
				pixel_put(img, point_plus(px, i), colour);
		}
		i.x = to.x - scale.x - 1;
	}
}

// закрашиваю круг пикселей
int	in_circle(t_plr *plr, float radius, t_point i)
{
	float	distance;
	float	pow1;
	float	pow2;

	pow1 = powf(plr->x - 1 - i.x, 2.);
	pow2 = powf(plr->y - 1 - i.y, 2.);
	distance = sqrtf(pow1 + pow2);
	// distance = sqrtf(powf(plr->x - 1 - i.x, 2.) + powf(plr->y - 1 - i.y, 2.));
	if (distance <= radius)
	{
		if ((radius - distance) < 2.0000000)
			return (2);
		return (1);
	}
	return (0);
}

void	drow_circle(t_image *img, t_plr plr)
{
	t_point		i;
	t_point		to;
	int			ret;

	i.x = plr.x - SCALE;
	i.y = plr.y - SCALE;
	to.x = plr.x + SCALE;
	to.y = plr.y + SCALE;

	while (++i.y <= to.y)
	{
		while (++i.x <= to.x)
		{
			ret = in_circle(&plr, SCALE / 3, i);
			if (!ret)
				continue ;
			else if (ret == 1)
				pixel_put(img, i, 0xFF0000);
			else
				pixel_put(img, i, 0x88FF0000);
			// else
				// pixel_put(img, point_plus(px, pos), 0x00116633);
		}
		i.x = plr.x * 0.9f;
	}
}

void	draw_line(t_image *img_map, t_plr p1, t_plr p2, int color)
{
	t_plr	t;
	int		step;

	step = 100;
	t.x = (p1.x - p2.x) / step;
	t.y = (p1.y - p2.y) / step;
	while (step --> 0)
	{
		pixel_put(img_map, point_set(p1.x -1, p1.y -1), color);
		p1.x += t.x;
		p1.y += t.y;
	}
}

bool	is_wall(t_all *all, t_point point)
{
	int	scale;

	scale = all->img_map->size.x / all->map_size.x;
	point = point_divide(point, point_set(scale, scale));
	if (all->map[point.y][point.x] == '0')
	// if (all->map[all->map_size.y - point.y - 1][all->map_size.x - point.x - 1] == '0')
		return (false);
	return (true);
}

void	draw_raycast(t_all *all)
{
	t_plr	fpoint;
	t_plr	t;
	float	coef_rays;
	float	direction;
	float	count_rays;
	float	width_view;

	width_view = 0.9f; /* 90 это ширина обзора */
	count_rays = 32;
	coef_rays = width_view / count_rays;
	direction = all->plr->dir - coef_rays + width_view / 2;
	fpoint = *all->plr;

	while(count_rays--)
	{
		while(!is_wall(all, point_set(fpoint.x, fpoint.y)))
		{
			fpoint.x += sinf(direction) * 0.5;
			fpoint.y += cosf(direction) * 0.5;
		}
		t.x = fpoint.x - all->plr->x;
		t.y = fpoint.y - all->plr->y;
		fpoint.x -= t.x * 2;
		fpoint.y -= t.y * 2;
		draw_line(all->img_map, *all->plr, fpoint, 0xFF0000);
		direction -= coef_rays;
		fpoint.x = all->plr->x;
		fpoint.y = all->plr->y;
	}
}

void	draw_view(t_all *all)
{
	float	c;
	t_plr	p1;
	t_plr	p2;

	p1 = *all->plr;
	// p1.x = img_map->size.x / p1.x;
	// p1.y = img_map->size.y / p1.y;
	p2 = p1;
	c = 10.0f;
	p1.x += sinf(all->plr->dir) * c;
	p1.y += cosf(all->plr->dir) * c;
	draw_line(all->img_map, p1, p2, 0x00FF00);
	draw_raycast(all);
}

// Закрашиваю изображение картой
void	draw_mini_map(t_all *all)
{
	t_point	px;
	t_point	scale;

	scale = point_divide(all->img_map->size, point_plus(all->map_size, point_set(1, 1)));
	px = point_set(-1, -1);
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
	drow_circle(img_map, *all->plr);
}


