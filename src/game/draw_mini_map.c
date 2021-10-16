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

	distance = sqrtf(powf(plr->x - i.x, 2.) + powf(plr->y - i.y, 2.));
	if (distance <= radius)
	{
		if ((radius - distance) < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}
void	drow_circle(t_image *img, t_point scale, t_plr plr)
{
	t_point		i;
	t_point		to;
	t_point		px;
	int			ret;

	px.x = plr.x;
	px.y = plr.y;
	i = point_multiple(point_plus(px, point_set(-2, -2)), scale);
	to = point_multiple(point_plus(px, point_set(2, 2)), scale);
	plr.x = (plr.x - 0.5f) * scale.x - 1;
	plr.y = (plr.y - 0.5f) * scale.y - 1;

	while (++i.y <= to.y)
	{
		while (++i.x <= to.x)
		{
			ret = in_circle(&plr, scale.x / 3, i);
			if (ret == 1)
				pixel_put(img, i, 0xFF0000);
			else if (ret == 2)
				pixel_put(img, i, 0x88FF0000);
			// else
				// pixel_put(img, point_plus(px, pos), 0x00116633);
		}
		i.x = (px.x - 2) * scale.x;
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
	drow_circle(img_map, scale_map, *all->plr);
}


