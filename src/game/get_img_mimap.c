#include "cub3d.h"

#define MLX_RED 0x800000
#define MLX_GRN 0x008000
#define MLX_BLU 0x000080
#define MLX_BLK 0x000000
#define MLX_WHT 0xFFFFFF
#define MLX_GRY 0x666666

// считаю габариты карты
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

// закрашиваю один пиксель
void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int colour)
{
	char	*dst;

	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

// закрашиваю квадратик пикселей
void	drow_big_pixel(char c, t_image *img, t_point topnt, t_point	px)
{
	unsigned int		colour = 0xFF000000;
	t_point	i;

	if (c == '1')
		colour = MLX_WHT;
	else if (c == '0')
		colour = MLX_GRY;
	else if (c == 'W')
		colour = MLX_GRN;
	px.x *= topnt.x;
	px.y *= topnt.y;
	i.x = (i.y = -1);
	while (++i.y < topnt.y)
	{
		while (++i.x < topnt.x)
			my_mlx_pixel_put(img, px.x + i.x, px.y + i.y, colour);
		i.x = -1;
	}
}

// Закрашиваю изображение, (стена, пол или игрок)
void	draw_to_img_minmap(t_image *img_map, char **map, t_point topnt)
{
	t_point	px;

	px.x = (px.y = -1);
	while (map[++px.y])
	{
		while (map[px.y][++px.x])
			drow_big_pixel(map[px.y][px.x], img_map, topnt, px);
		px.x = -1;
	}
}

// создает новое изображение
t_image	*new_image(void *mlx, int width, int height)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->width = width;
	img->height = height;
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

// создаю изображение миникарты
t_image	*create_img_minimap(t_all *all, t_point point, int width, int height)
{
	t_point	topnt;
	t_image	*img_map;

	topnt.x = width / point.x;
	topnt.y = height / point.y;

	img_map = new_image(all->win->mlx, width, height);
	draw_to_img_minmap(img_map, all->map, topnt);
	return (img_map);
}

t_image	*get_img_mimap(t_all *all)
{
	t_point	size;

	size = map_len(all->map);
	return (create_img_minimap(all, size, 400, 200));
}
