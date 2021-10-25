/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_missing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:00:06 by name              #+#    #+#             */
/*   Updated: 2021/10/25 21:11:44 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	setup_missing(t_all *all)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (!all->textures[i] && !all->colors[i])
		{
			all->colors[i] = ft_calloc(3, sizeof(unsigned char));
			if (!all->colors[i])
				return ((all->err
						= ft_strdup("setup_missing error: no space left")),
					true);
			all->colors[i][0] = 255 - (255 / 5) * i;
			all->colors[i][1] = 255 - (255 / 5) * i;
			all->colors[i][2] = 255 - (255 / 5) * i;
		}
	}
	return (false);
}
