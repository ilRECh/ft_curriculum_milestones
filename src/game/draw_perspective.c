/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perspective.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:04:28 by csamuro           #+#    #+#             */
/*   Updated: 2021/10/26 16:33:05 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vpixel_line(t_all *all, int x, int height_wall, double x_dwall)
{
	int		start_ybuff;
	double	wy[2];
	double	coef;
	double	idw;
	int		iter;

	x_dwall = 1 - modf(x_dwall, &idw);
	coef = x_dwall;
	x_dwall *= all->whalls[(int)idw]->size.x;
	start_ybuff = (all->buff->size.y - height_wall) / 2;
	wy[1] = (double)all->whalls[(int)idw]->size.y / (double)height_wall;
	wy[0] = 0.000;
	iter = -1;
	while (++iter < height_wall)
	{
		pixel_put(all->buff, pnt_set(x, start_ybuff + iter),
			pixel_get(all->whalls[(int)idw], pnt_set(x_dwall, wy[0])));
		wy[0] += wy[1];
	}
}

static inline int	height_wall(t_all *all,
	t_dpoint a, t_dpoint b, t_dpoint proj)
{
	a = dpnt_minus(a, proj);
	b = dpnt_minus(b, proj);
	b = dpnt_minus(a, b);
	b = dpnt_multiple(b, b);
	return (all->buff->size.y / (sqrtf(b.x + b.y)));
}

double	get_dist(double vector, double xy)
{
	double	integer;

	if (vector >= 0)
		return (1 - modf(xy, &integer));
	return (-modf(xy, &integer));
}

t_project_plane	project_plane_set(t_all *all,
	double width_in_deg, double distance_to_plane)
{
	t_project_plane	prj;

	prj.width = degToRad(width_in_deg);
	prj.project.x = all->plr->x + distance_to_plane \
		* cosf(all->plr->dir - degToRad(width_in_deg / 2));
	prj.project.y = all->plr->y + distance_to_plane \
		* cosf(all->plr->dir - degToRad(width_in_deg / 2));
	prj.coef = prj.width / all->buff->size.x;
	return (prj);
}

void	draw_raycast(t_all *all)
{
	t_project_plane	proj;
	t_dpoint		dpoint;
	int				h_wall;
	double			direction;
	int				i;

	proj = project_plane_set(all, 60, 0.5);
	direction = all->plr->dir + (proj.width / 2);
	dpoint = conv_pltod(*all->plr);
	i = -1;
	while (++i < all->buff->size.x)
	{
		shoot_ray(all, &dpoint, direction);
		proj.project = dpnt_plus(proj.project, dpnt_s(proj.coef));
		h_wall = height_wall(all, conv_pltod(*all->plr), dpoint, proj.project);
		draw_vpixel_line(all, i, h_wall, get_x_dwall(&dpoint));
		draw_line(all->img_map,
			dpnt_multiple(conv_pltod(*all->plr), dpnt_s(all->scale)),
			dpnt_multiple(dpoint, dpnt_s(all->scale)), 0x0);
		dpoint = conv_pltod(*all->plr);
		direction -= proj.coef;
	}
}
