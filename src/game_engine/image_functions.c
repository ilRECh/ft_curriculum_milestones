/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:01:54 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 15:02:50 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_to_image_cp(t_image *dst, t_image *src, t_point position)
{
	t_point	i;

	i = pnt_s(-1);
	while (++i.y < src->size.y)
	{
		while (++i.x < src->size.x)
			pixel_put(dst, pnt_plus(i, position), pixel_get(src, i));
		i.x = -1;
	}
}

void	image_to_image_cp_insert_clr(t_image *dst,
	t_image *src, t_point position, unsigned int ins_scolor)
{
	unsigned int	color;
	t_point			i;

	i = pnt_s(-1);
	while (++i.y < src->size.y)
	{
		while (++i.x < src->size.x)
		{
			color = pixel_get(src, i);
			if (color == ins_scolor)
				continue ;
			pixel_put(dst, pnt_plus(i, position), color);
		}
		i.x = -1;
	}
}
