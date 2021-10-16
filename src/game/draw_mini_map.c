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
int	in_circle(t_point i, float radius, t_point pos)
{
	float	distance;

	distance = sqrtf(powf(i.x - pos.x, 2.) + powf(i.y - pos.y, 2.));
	if (distance <= radius)
	{
		if ((radius - distance) < 15.00000000)
			return (2);
		return (1);
	}
	return (0);
}
void	drow_circle(t_image *img, t_point scale, t_point px)
{
	t_point		pos;
	t_point		to;
	t_point		i;

	scale = point_set(max_min(scale.x, scale.y, true), max_min(scale.x, scale.y, true));
	pos = px;

	to = point_plus(pos, scale);
	pos = (i = point_plus(pos, point_set(-1, -1)));
	while (++pos.y <= to.y)
	{
		while (++pos.x <= to.x)
		{
			if (in_circle(point_minus(pos, i), (float)(scale.x / 2) , point_set(8, 8)))
				pixel_put(img, point_plus(px, pos), 0xFF0000);
			// else
				// pixel_put(img, point_plus(px, pos), 0x00116633);
		}
		pos.x = to.x - scale.x - 1;
	}
}

// Закрашиваю изображение картой
t_image	*draw_mini_map(t_all *all)
{
	t_point	px;
	t_point	scale;
	t_image	*img_map;

	img_map = new_image(all->win->mlx, point_multiple(all->map_size, point_set(16, 16)));
	scale = point_divide(img_map->size, point_plus(all->map_size, point_set(1, 1)));
	px = point_set(-1, -1);
	while (all->map[++px.y])
	{
		while (all->map[px.y][++px.x])
		{
			drow_big_pixel(all->map[px.y][px.x], img_map, scale, px);
		}
		px.x = -1;
	}
	return (img_map);
}

// Рисую позицию и направлене игрока на карте
void	player_in_map(t_all *all, t_image *img_map)
{
	t_point	i;
	t_point	scale_map;

	i = point_set(all->plr->x, all->plr->y);
	scale_map = point_divide(img_map->size, all->map_size);
	drow_circle(img_map, scale_map, point_set(all->plr->x, all->plr->y));
}


