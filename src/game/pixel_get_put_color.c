/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_get_put_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:00:25 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 15:01:40 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// закрашиваю один пиксель на изображении
void	pixel_put(t_image *img, t_point	p, unsigned int colour)
{
	char	*dst;

	if (p.x < 0 || p.x >= img->size.x || p.y < 0 || p.y >= img->size.y)
		return ;
	dst = img->addr + ((p.y * img->line_length) + \
		(p.x * (img->bits_per_pixel / 8)));
	*(unsigned int *)dst = colour;
}

// Получаю пиксель из изображения
unsigned int	pixel_get(t_image *img, t_point p)
{
	void			*dst;
	unsigned int	ret;

	if (p.x < 0 || p.x >= img->size.x || p.y < 0 || p.y >= img->size.y)
		return (0xFF000000);
	dst = img->addr + ((p.y * img->line_length) + \
		(p.x * (img->bits_per_pixel / 8)));
	ret = *(unsigned int *)dst;
	return (ret);
}
