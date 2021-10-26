/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dpoint_math.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:53:48 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 14:54:16 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// return (get mantissa for X and Y in dpoint)
t_dpoint	dpnt_mod(t_dpoint dpoint)
{
	t_dpoint	mod;
	double		t;

	mod.x = modf(dpoint.x, &t);
	mod.y = modf(dpoint.y, &t);
	return (mod);
}

// return (t_dpoint + t_dpoint);
t_dpoint	dpnt_plus(t_dpoint p1, t_dpoint p2)
{
	t_dpoint	res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	return (res);
}

// return (t_dpoint - t_dpoint);
t_dpoint	dpnt_minus(t_dpoint p1, t_dpoint p2)
{
	t_dpoint	res;

	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	return (res);
}

// return (t_dpoint / t_dpoint);
t_dpoint	dpnt_divide(t_dpoint p1, t_dpoint p2)
{
	t_dpoint	res;

	res.x = p1.x / p2.x;
	res.y = p1.y / p2.y;
	return (res);
}

// return (t_dpoint * t_dpoint);
t_dpoint	dpnt_multiple(t_dpoint p1, t_dpoint p2)
{
	t_dpoint	res;

	res.x = p1.x * p2.x;
	res.y = p1.y * p2.y;
	return (res);
}
