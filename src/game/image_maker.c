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
