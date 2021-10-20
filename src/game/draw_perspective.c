#include "cub3d.h"

//  NORTH > 0 < 1 
//  SOUTH > 1 < 2
//  WEST > 2 < 3
//  EAST > 3 < 4

int	use_pols(double *dbl)
{
	int pol;

	if (*dbl > 3)
		pol = EAST;
	else if (*dbl > 2)
		pol = WEST;
	else if (*dbl > 1)
		pol = SOUTH;
	else
		pol = NORTH;
	*dbl -= pol;
	return (pol);
}

// x			это позиция в общем буфере
// xdwall		это кэфициент позиций пикселей с текстуры 100.00
// height_wall	это размер вертикали стены
void    draw_vpixel_line(t_all *all, int x, double xdwall, int height_wall)
{
	int		start_ybuff;
	int		iter;
	double	coef_iter;
	double	d_iter;
	int		pols;

	pols = use_pols(&xdwall);
	xdwall *= 200;
	// xdwall = (xdwall * all->whalls[pols].size.x);
	start_ybuff = (all->buff->size.y - height_wall) / 2;
	coef_iter = (double)all->whalls[pols].size.y / (double)height_wall;
	iter = -1;
	d_iter = 0.000;
	while (++iter < height_wall)
	{
		pixel_put(all->buff, point_set(x, start_ybuff + iter), 
			pixel_get(&all->whalls[pols], point_set(xdwall , d_iter)));
		d_iter += coef_iter;
	}
}

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


static inline double	len_ray(t_dpoint a, t_dpoint b)
{
	b = dpoint_minus(b, a);
	b = dpoint_multiple(b, b);
	return (sqrt(b.x + b.y));
}

double		get_pole(t_dpoint ray, t_dpoint size)
{
	t_dpoint	dif;
	t_point		pos_on_map;
	(void)size;
	ray = dpoint_divide(ray, size);
	pos_on_map = conv_dp_to_p(ray);
	dif.x = ray.x - (double)pos_on_map.x;
	dif.y = ray.y - (double)pos_on_map.y;
	if (dif.y > 1.0 - SENS_RAY)
		return (SOUTH + dif.x);
	else if (dif.x < SENS_RAY)
		return (WEST + dif.y);
	else if (dif.x > 1 - SENS_RAY)
		return (EAST + dif.y);
	else if (dif.y < SENS_RAY)
		return (NORTH + dif.x);
	return (0);
}

void	draw_raycast(t_all *all)
{
	(void)all;
	t_dpoint	dpoint;
	t_dpoint	t;
	double		coef_rays;
	double		direction;
	double		count_rays;
	double		width_view;

	width_view = 0.75f; /* 90 это ширина обзора */
	count_rays = all->buff->size.x;
	coef_rays = width_view / count_rays;
	direction = all->plr->dir - coef_rays + (width_view / 2);
	dpoint = conv_plr_to_dpoint(*all->plr);

	while(count_rays--)
	{
		while(!is_wall(all, point_set(dpoint.x, dpoint.y)))
		{
			dpoint.x += sinf(direction) * 1.5;
			dpoint.y += cosf(direction) * 1.5;
		}
		draw_vpixel_line(all, all->buff->size.x - count_rays , get_pole(dpoint, conv_p_to_dp(all->map_size)),
			300 - len_ray(conv_plr_to_dpoint(*all->plr), dpoint));
		t.x = dpoint.x - all->plr->x;
		t.y = dpoint.y - all->plr->y;
		dpoint.x -= t.x * 2;
		dpoint.y -= t.y * 2;
		draw_line(all->img_map, conv_plr_to_dpoint(*all->plr), dpoint, 0xAAFF0000);
		direction -= coef_rays;
		dpoint.x = all->plr->x;
		dpoint.y = all->plr->y;
	}
}