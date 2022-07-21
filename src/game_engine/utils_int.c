/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:52:34 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 14:53:26 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_min(int a, int b, bool updown)
{
	if (updown)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
}
