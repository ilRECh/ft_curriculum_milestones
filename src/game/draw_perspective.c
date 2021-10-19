#include "cub3d.h"

// void	draw_raycast(t_all *all)
// {
// 	t_dpoint	dpoint;
// 	t_dpoint	t;
// 	double		coef_rays;
// 	double		direction;
// 	double		count_rays;
// 	double		width_view;
// 	width_view = 0.9f; /* 90 это ширина обзора */
// 	count_rays = 64;
// 	coef_rays = width_view / count_rays;
// 	direction = all->plr->dir - coef_rays + (width_view / 2);
// 	dpoint = convert_plr_to_dpoint(*all->plr);
// 	while(count_rays--)
// 	{
// 		while(!is_wall(all, point_set(dpoint.x, dpoint.y)))
// 		{
// 			dpoint.x += sinf(direction) * 1.5;
// 			dpoint.y += cosf(direction) * 1.5;
// 		}
// 		t.x = dpoint.x - all->plr->x;
// 		t.y = dpoint.y - all->plr->y;
// 		dpoint.x -= t.x * 2;
// 		dpoint.y -= t.y * 2;
// 		draw_line(all->img_map, convert_plr_to_dpoint(*all->plr), dpoint, 0xAAFF0000);
// 		direction -= coef_rays;
// 		dpoint.x = all->plr->x;
// 		dpoint.y = all->plr->y;
// 	}
// }

bool	is_wall(t_all *all, t_point point)
{
	int	scale;

	scale = all->img_map->size.x / all->map_size.x;
	point = point_divide(point, point_set(scale, scale));
	if (all->map[point.y][point.x] == '0')
	// if (all->map[all->map_size.y - point.y - 1][all->map_size.x - point.x - 1] == '0')
		return (false);
	return (true);
}

void	draw_raycast(t_all *all)
{
	t_dpoint	dpoint;
	t_dpoint	t;
	double		coef_rays;
	double		direction;
	double		count_rays;
	double		width_view;

	width_view = 0.9f; /* 90 это ширина обзора */
	count_rays = 64;
	coef_rays = width_view / count_rays;
	direction = all->plr->dir - coef_rays + (width_view / 2);
	dpoint = convert_plr_to_dpoint(*all->plr);

	while(count_rays--)
	{
		while(!is_wall(all, point_set(dpoint.x, dpoint.y)))
		{
			dpoint.x += sinf(direction) * 1.5;
			dpoint.y += cosf(direction) * 1.5;
		}
		t.x = dpoint.x - all->plr->x;
		t.y = dpoint.y - all->plr->y;
		// dpoint.x -= t.x * 2;
		// dpoint.y -= t.y * 2;
		// draw_line(all->img_map, convert_plr_to_dpoint(*all->plr), dpoint, 0xAAFF0000);
		direction -= coef_rays;
		dpoint.x = all->plr->x;
		dpoint.y = all->plr->y;
	}
}

void    draw_perspective(t_all *all)
{

}