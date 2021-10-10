/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:42:11 by name              #+#    #+#             */
/*   Updated: 2021/10/03 15:42:26 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_win	mlx_create( int width, int height )
{
	t_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, width, height, "cube3d!");
	return (win);
}

bool	game(t_all *all)
{
	t_win	win;

	win = mlx_create(1024, 512);
	all->win = win.win;
	return (false);
}