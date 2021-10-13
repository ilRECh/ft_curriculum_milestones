#include "cub3d.h"

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

// закрашиваю один пиксель
void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int colour)
{
	char	*dst;

	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

// закрашиваю квадрат пикселей
// если start пустой то стартуется с нуля
// если end пустой то закрашиваю все изображение со стартовой точки;
void	fill_rect_to_img(t_image *img, const t_point *start, const t_point *end, const unsigned int colour)
{
	t_point	i;
	t_point	s;
	t_point	e;

	if (start)
		s = *start;
	else
		s.x = (s.y = 0);
	if (end)
		e = *end;
	else
	{
		e.x = img->width;
		e.y = img->height;
	}
	i = s, i.x--, i.y--;
	while (++i.y < e.y)
	{
		while (++i.x < e.x)
			my_mlx_pixel_put(img, i.x, i.y, colour);
		i.x = s.x - 1;
	}
}
