/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:49:23 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 14:50:07 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//
/////////////// double
//

// convert (INT point) to (DOUBLE dpoint)
t_dpoint	conv_ptod(t_point point)
{
	t_dpoint	dpoint;

	dpoint.x = point.x;
	dpoint.y = point.y;
	return (dpoint);
}

// convert t_plr to t_dpoint
t_dpoint	conv_pltod(t_plr plr)
{
	t_dpoint	dpoint;

	dpoint.x = plr.x;
	dpoint.y = plr.y;
	return (dpoint);
}

// return (t_dpoint.x = x, t_dpoint.y = y);
t_dpoint	dpnt_set(double x, double y)
{
	t_dpoint	res;

	res.x = x;
	res.y = y;
	return (res);
}

// return (t_dpoint.x = xy, t_dpoint.y = xy);
t_dpoint	dpnt_s(double xy)
{
	t_dpoint	res;

	res.x = xy;
	res.y = xy;
	return (res);
}
