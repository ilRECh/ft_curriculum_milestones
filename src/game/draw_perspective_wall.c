/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perspective_wall.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:20:12 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/27 15:24:23 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	idxw_detect(t_dpoint point, double *idwx)
{
	const float	limit = 0.998;

	point = dpnt_mod(point);
	if (point.x > limit && point.x > point.y)
		*idwx += 3;
	else if (point.x < 1 - limit && point.x < point.y)
		*idwx += 2;
	else if (point.y > limit)
		*idwx += 1;
	else
		*idwx += 0;
}

double	get_x_dwall(t_dpoint *dpoint)
{
	t_dpoint	in_scale;
	t_dpoint	half;
	double		res;

	in_scale = dpnt_mod(*dpoint);
	if (in_scale.x > 0.5)
		half.x = 1.0 - in_scale.x;
	else
		half.x = in_scale.x;
	if (in_scale.y > 0.5)
		half.y = 1.0 - in_scale.y;
	else
		half.y = in_scale.y;
	if (half.x < half.y)
		res = in_scale.y;
	else
		res = in_scale.x;
	idxw_detect(*dpoint, &res);
	return (res);
}

bool	is_wall(t_all *all, t_dpoint *point)
{
	if (point->x >= all->map_size.x || point->y >= all->map_size.y)
		return (true);
	if (point->x < 0 || point->y < 0)
		return (true);
	if (all->map[(int)point->y][(int)point->x] == '0')
		return (false);
	return (true);
}

void	shoot_ray(t_all *all, t_dpoint *dpoint, double direction)
{
	t_dpoint	bias;
	t_dpoint	vector;
	double		x;
	double		y;

	bias = dpnt_s(0);
	vector = dpnt_set(sin(direction), cos(direction));
	x = sin(direction) * 0.0005;
	y = cos(direction) * 0.0005;
	while (!is_wall(all, dpoint))
	{
		dpoint->x += x;
		dpoint->y += y;
	}
}
