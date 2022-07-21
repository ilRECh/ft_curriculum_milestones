/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:51:04 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:28:24 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int
// convert (DOUBLE t_dpoint) to (INT t_point)
t_point	conv_dtop(t_dpoint dpoint)
{
	t_point	point;

	point.x = dpoint.x;
	point.y = dpoint.y;
	return (point);
}

// convert t_player to t_point
t_point	conv_pltop(t_player plr)
{
	t_point	point;

	point.x = plr.x;
	point.y = plr.y;
	return (point);
}

// return (point.x = xy, point.y = xy)
t_point	pnt_s(int xy)
{
	t_point	res;

	res.x = xy;
	res.y = xy;
	return (res);
}

// return (point.x = x, point.y = y)
t_point	pnt_set(int x, int y)
{
	t_point	res;

	res.x = x;
	res.y = y;
	return (res);
}
