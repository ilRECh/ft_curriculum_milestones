/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:58:24 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 15:56:29 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// создает новое изображение
t_image	*new_image(void *mlx, t_point size)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->size = size;
	img->img = mlx_new_image(mlx, size.x, size.y);
	img->addr = mlx_get_data_addr \
		(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

t_image	image(void *mlx, t_point size)
{
	t_image	img;

	img.size = size;
	img.img = mlx_new_image(mlx, size.x, size.y);
	img.addr = mlx_get_data_addr \
		(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

// закрашиваю квадрат пикселей
// если start пустой то стартуется с нуля (x = 0) & (y = 0)
// если end пустой то закрашиваю все изображение
// со стартовой точки, (x = img.width) & (y = img.height)
t_image	*fill_rect_to_img(t_image *img,
	const t_point *start, const t_point *end, const unsigned int colour)
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
		e = img->size;
	i = pnt_minus(s, pnt_s(1));
	while (++i.y < e.y)
	{
		while (++i.x < e.x)
			pixel_put(img, i, colour);
		i.x = s.x - 1;
	}
	return (img);
}

// Make background | ceiling and floor
void	set_background(t_all *all)
{
	t_point	end;
	t_point	start;

	if (!all->buff)
		all->buff = new_image(all->win->mlx, all->screen_size);
	start = pnt_s(0);
	end = all->buff->size;
	end.y /= 2;
	fill_rect_to_img(all->buff, &start, &end, create_rgb(all->colors[5]));
	start.y = end.y;
	end.y *= 2;
	fill_rect_to_img(all->buff, &start, &end, create_rgb(all->colors[4]));
}
