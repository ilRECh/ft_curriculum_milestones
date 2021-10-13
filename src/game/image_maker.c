#include "cub3d.h"

// создает новое изображение
t_image	*new_image(void *mlx, int width, int height)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->size.x = width;
	img->size.y = height;
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

// закрашиваю один пиксель
void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int colour)
{
	char	*dst;

	if (x < 0 || x > img->size.x || y < 0 || y > img->size.y)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

// закрашиваю квадрат пикселей
// если start пустой то стартуется с нуля (x = 0) & (y = 0)
// если end пустой то закрашиваю все изображение со стартовой точки, (x = img.width) & (y = img.height)
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
		e.x = img->size.x;
		e.y = img->size.y;
	}
	i = s, i.x--, i.y--;
	while (++i.y < e.y)
	{
		while (++i.x < e.x)
			my_mlx_pixel_put(img, i.x, i.y, colour);
		i.x = s.x - 1;
	}
}

// Make background | ceiling and floor
void	set_background(t_all *all, int width, int height)
{
	t_point	end;
	t_point	start;
	if (!all->background)
	{
		all->background = new_image(all->win->mlx, width, height);
		start.x = (start.y = 0);
		end = all->background->size;
		end.y /= 2;
		fill_rect_to_img(all->background, &start, &end, 0x005055CC);
		start.y = end.y;
		end.y *= 2;
		fill_rect_to_img(all->background, &start, &end, 0x00201510);
	}
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->background->img, 0, 0);
}
