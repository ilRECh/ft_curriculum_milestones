/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:22:58 by name              #+#    #+#             */
/*   Updated: 2021/10/25 20:57:01 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	setup_all(t_all *all)
{
	all->textures = ft_calloc(7, sizeof (char *));
	if (!all->textures)
		return (true);
	all->colors = ft_calloc(7, sizeof(unsigned char *));
	if (!all->colors)
		return (true);
	all->plrpos.direction = 0;
	all->plrpos.x = -1;
	all->plrpos.y = -1;
	all->map = NULL;
	all->err = NULL;
	return (false);
}
