/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trigonometry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:44:27 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 14:45:52 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degToRad(double degree)
{
	return (degree / 180 * M_PI);
}

double	d_plus(double d)
{
	if (d < 0.000000000)
		return (-d);
	return (d);
}

double	d_dif_len(double a, double b)
{
	if (a < 0. && b >= 0.)
	{
		b += -a;
		a = 0;
	}
	else if (b < 0. && a >= 0.)
	{
		a += -b;
		b = 0;
	}
	if (a > b)
		return (b - a);
	return (a - b);
}
