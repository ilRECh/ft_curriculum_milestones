/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_point_math.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:51:31 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 15:16:01 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// return (point + point)
t_point	pnt_plus(t_point p1, t_point p2)
{
	t_point	res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	return (res);
}

// return (point - point)
t_point	pnt_minus(t_point p1, t_point p2)
{
	t_point	res;

	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	return (res);
}

// return (point / point)
t_point	pnt_divide(t_point p1, t_point p2)
{
	t_point	res;

	res.x = p1.x / p2.x;
	res.y = p1.y / p2.y;
	return (res);
}

// return (point * point)
t_point	pnt_multiple(t_point p1, t_point p2)
{
	t_point	res;

	res.x = p1.x * p2.x;
	res.y = p1.y * p2.y;
	return (res);
}
