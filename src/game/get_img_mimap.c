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
	unsigned int		colour = 0xFF000000;
	t_point	i;

	if (c == '1')
		colour = MLX_WHT;
	else if (c == '0')
		colour = MLX_GRY;
	else if (c == 'W')
		colour = MLX_GRN;
	px = point_multiple(px, scale);
	i = point_plus(px, scale);
	while (++i.y < scale.y)
	{
		while (++i.x < scale.x)
			pixel_put(img, point_plus(px, i), colour);
			// pixel_put(img, px.x + i.x, px.y + i.y, colour);
		i.x = -1;
	}
}

// Закрашиваю изображение, (стена, пол или игрок)
void	draw_to_buff_minmap(t_all *all, int div_map)
{
	t_point	px;
	t_point	coef;

	coef = point_divide(point_divide(all->screen_size, point_set(div_map, div_map)), all->map_size);
	px = point_set(-1, -1);
	while (all->map[++px.y])
	{
		while (all->map[px.y][++px.x])
		{
			drow_big_pixel(all->map[px.y][px.x], all->buff, coef, \
				point_plus(px, point_set(50, 50)));
		}
		px.x = -1;
	}
}

// рисую изображение миникарты на буфере и задаю коодинаты игроку
void	draw_mini_map(t_all *all)
{
	set_plrpos(all);
	set_plr(all, all->plrpos.x, all->plrpos.y, 10);
	draw_to_buff_minmap(all, 20);
}
