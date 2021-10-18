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

//	<<<<<<<<<<  mmmm, magic cos sin sex  >>>>>>>>>>>
void	magic_cossin(t_all *all, float to_dir)
{
	all->plr->x = (all->plr->x - all->plr->y) * cos(to_dir);
	all->plr->y = (all->plr->x + all->plr->y) * sin(to_dir);
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

void	draw_line(t_image *img_map, t_plr p1, t_plr p2)
{
	t_plr	t;
	int		step;

	step = 100;
	t.x = (p1.x - p2.x) / step;
	t.y = (p1.y - p2.y) / step;
	while (step --> 0)
	{
		pixel_put(img_map, point_set(p1.x -1, p1.y -1), 0x00FF00);
		p1.x += t.x;
		p1.y += t.y;
	}
}

void	draw_view(t_image *img_map, t_plr *plr)
{
	float	c;
	t_plr	p1;
	t_plr	p2;

	p1 = *plr;
	// p1.x = img_map->size.x / p1.x;
	// p1.y = img_map->size.y / p1.y;
	p2 = p1;
	c = 10.0f;
	p1.x += sinf(plr->dir) * c;
	p1.y += cosf(plr->dir) * c;
	draw_line(img_map, p1, p2);
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
	draw_view(all->img_map, all->plr);
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


