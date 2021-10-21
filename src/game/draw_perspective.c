#include "cub3d.h"

//  NORTH > 0 < 1 
//  SOUTH > 1 < 2
//  WEST > 2 < 3
//  EAST > 3 < 4

// x			это позиция в общем буфере
// xdwall		это кэфициент позиций пикселей с текстуры 100.00
// height_wall	это размер вертикали стены
void    draw_vpixel_line(t_all *all, int x, int height_wall, double x_dwall)
{
	int		start_ybuff;
	int		iter;
	double	coef_iter;
	double	d_iter;

	// x_dwall 0.0 <-> 1.0
	x_dwall = (x_dwall * all->whalls[0].size.x);			// превращаем коэффициент в позицию X на текстуре
	start_ybuff = (all->buff->size.y - height_wall) / 2;	// Определяем место начала стены в буфере
	coef_iter = (double)all->whalls[0].size.y / (double)height_wall;	// коэфициент итерации для Y стены
	d_iter = 0.000;														// итератор для Y стены
	iter = -1;															// итератор для буфера
	while (++iter < height_wall)
	{
		pixel_put(all->buff, pnt_set(x, start_ybuff + iter), 
			pixel_get(&all->whalls[1], pnt_set(x_dwall , d_iter)));
		d_iter += coef_iter;
	}
}

bool	is_wall(t_all *all, t_point point)
{
	if (point.x >= all->map_size.x || point.y >= all->map_size.y)
		return (true);
	if (point.x < 0 || point.y < 0)
		return (true);
	if (all->map[point.y][point.x] == '0')
		return (false);
	return (true);
}


static inline int	height_wall(t_all *all, t_dpoint a, t_dpoint b, t_dpoint proj)
{
	a = dpnt_minus(a, proj);
	b = dpnt_minus(b, proj);
	b = dpnt_minus(a, b);
	b = dpnt_multiple(b, b);
	double test = (sqrtf(b.x + b.y));

	return (all->buff->size.y / test);
}

t_dpoint	to_round_step(t_dpoint *dpoint, double direction)
{
	t_dpoint	bias;
	double		integer;
	double		modX;
	double		modY;
	double		x;
	double		y;

	x = sin(direction) * 100;
	y = cos(direction) * 100;
	
	modX = x > 0 ? 1 - modf(dpoint->x, &integer) : - modf(dpoint->x, &integer);
	modY = y > 0 ? 1 - modf(dpoint->y, &integer) : - modf(dpoint->y, &integer);

	if (d_plus(modX) < d_plus(modY))
	{
		bias.y = cos(direction) * modX;
		bias.x = modX;
	}
	else
	{
		bias.x = sin(direction) * modY;
		bias.y = modY;
	}
	return (bias);
//|-------|----*--|-------|-------|
//|       |       |       |       |
//|       |       |       |       |
//|-------|-------*-------|-------|
//|       |       |       |       |
//|       |       |       |       |
//|-------|-------|-*-----|-------|
//|       |       |       |       |
//|       |       |       |       |
//|-------|-------|-----*-|-------|
}

void	shoot_ray_eco(t_all *all, t_dpoint *dpoint, double direction)
{
	t_dpoint	bias;
	double		x;
	double		y;
	// int8_t		mode;

	// mode = 0;
	bias = dpnt_s(0);
	// if (sin(direction) * 100 > 0)
	// 	mode |= RIGHT;
	// else
	// 	mode |= LEFT;
	// if (cos(direction) * 100 > 0)
	// 	mode |= DOWN;
	// else
	// 	mode |= UP;

	x = sin(direction) * 0.01;
	y = cos(direction) * 0.01;
	while(!is_wall(all, pnt_set(dpoint->x + bias.x, dpoint->y + bias.y)))
	{
		// bias = to_round_step(dpoint, direction, mode);
		bias.x += x;
		bias.y += y;
	}
	*dpoint = dpnt_plus(*dpoint, bias);
}

double	get_x_dwall(t_all *all, t_dpoint *dpoint)
{
	t_dpoint	in_scale;
	t_dpoint	half;

	in_scale = dpnt_mod(dpnt_divide(*dpoint, conv_ptod(all->map_size)));
	half.x = in_scale.x > 0.5 ? 1.0 - in_scale.x : in_scale.x;
	half.y = in_scale.y > 0.5 ? 1.0 - in_scale.y : in_scale.y;
	if (half.x < half.y)
		return (in_scale.y);
	return (in_scale.x);
}

void	draw_raycast(t_all *all)
{
	(void)all;
	double		scale;
	t_dpoint	dpoint;
	int			h_wall;
	double		coef_rays;
	double		direction;
	double		width_view;
	int			i;

	t_dpoint	project;
	double		width_plane;
	double		coef_projplane;

	scale = all->buff->size.x / all->map_size.x;

	width_view = degToRad(60); /* 90 это ширина обзора */
	coef_rays = width_view / all->buff->size.x;

	width_plane = 0.1;
	coef_projplane = width_plane / all->buff->size.x;
	project.x = all->plr->x + 0.5 * cosf(all->plr->dir - degToRad(width_view / 2));
	project.y = all->plr->y + 0.5 * cosf(all->plr->dir - degToRad(width_view / 2));


	direction = all->plr->dir - coef_rays + (width_view / 2);
	dpoint = conv_pltod(*all->plr);

	i = -1;
	while(++i < all->buff->size.x)
	{
		shoot_ray_eco(all, &dpoint, direction);
		h_wall = height_wall(all, conv_pltod(*all->plr), dpoint, project);
		project = dpnt_plus(project, dpnt_s(coef_projplane));
		draw_vpixel_line(all, i, h_wall, get_x_dwall(all, &dpoint));
		draw_line(all->img_map, 
			dpnt_multiple(	conv_pltod(*all->plr),	dpnt_s(SCALE >> 2)),
			dpnt_multiple(				dpoint,		dpnt_s(SCALE >> 2)), 0x0);
		dpoint = conv_pltod(*all->plr);
		direction -= coef_rays;
	}
}