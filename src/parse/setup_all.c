/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:22:58 by name              #+#    #+#             */
/*   Updated: 2021/09/28 22:29:53 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    setup_all(t_all *all)
{
	//win
	//plr
	all->textures = ft_calloc(5, sizeof (char *));
	all->colors = ft_calloc(3, sizeof(char *));
	all->map = NULL;
	all->err = NULL;
}
