#include "cub3d.h"

//  NORTH > 0 < 1 
//  SOUTH > 1 < 2
//  WEST > 2 < 3
//  EAST > 3 < 4

// x			это позиция в общем буфере
// xdwall		это кэфициент позиций пикселей с текстуры 100.00
// height_wall	это размер вертикали стены

// uint32_t	deep_dark(uint32_t colour, double x_dwall)
// {
// 	unsigned int	t;
// 	unsigned int	r;
// 	unsigned int	g;
// 	unsigned int	b;
// 	(void)x_dwall;

// 	x_dwall /= 1.2;
// 	if (x_dwall > 1)
// 		x_dwall = 1;
// 	t = (colour >> 24) * x_dwall;
// 	r = (0x000000FF & colour >> 16) * x_dwall;
// 	g = (0x000000FF & colour >> 8) * x_dwall;
// 	b = (0x000000FF & colour) * x_dwall;

// 	colour = t;
// 	colour <<= 8;
// 	colour += r;
// 	colour <<= 8;
// 	colour += g;
// 	colour <<= 8;
// 	colour += b;
// 	return (colour);
// }

void    draw_vpixel_line(t_all *all, int x, int height_wall, double x_dwall)
{
	int		start_ybuff;
	double	wy[2];
	double	coef;
	double	idw;
	int		iter;

	x_dwall = 1 - modf(x_dwall, &idw);
	coef = x_dwall;
	x_dwall *= all->whalls[(int)idw]->size.x;			// превращаем коэффициент в позицию X на текстуре
	start_ybuff = (all->buff->size.y - height_wall) / 2;	// Определяем место начала стены в буфере
	wy[1] = (double)all->whalls[(int)idw]->size.y / (double)height_wall;	// коэфициент итерации для Y стены
	wy[0] = 0.000;														// итератор для Y стены
	iter = -1;															// итератор для буфера
	while (++iter < height_wall)
	{
		pixel_put(all->buff, pnt_set(x, start_ybuff + iter), 
			/*deep_dark(*/pixel_get(all->whalls[(int)idw], pnt_set(x_dwall , wy[0]))/*, (double)height_wall / 450.0)*/);
		wy[0] += wy[1];
	}
}

bool	is_wall(t_all *all, t_dpoint *point)
{
	if (point->x >= all->map_size.x || point->y >= all->map_size.y)
		return (true);
	if (point->x < 0 || point->y < 0)
		return (true);
	if (all->map[(int)point->y][(int)point->x] == '0')
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

double	get_dist(double vector, double xy)
{
	double	integer;

	if (vector >= 0)
		return (1 - modf(xy, &integer));
	return (- modf(xy, &integer));
}

void	shoot_ray(t_all *all, t_dpoint *dpoint, double direction)
{
	t_dpoint	bias;
	t_dpoint	vector;
	double		x;
	double		y;

	bias = dpnt_s(0);
	vector = dpnt_set(sin(direction), cos(direction));
	x = sin(direction) * 0.009;
	y = cos(direction) * 0.009;
	while(!is_wall(all, dpoint))
	{
		dpoint->x += x;
		dpoint->y += y;
	}
		// to_round_step(dpoint, direction, vector);
}

void	idxw_detect(t_dpoint point, double *idwx)
{
	const float	limit = 0.990;

	point = dpnt_mod(point);
	if (point.x > limit && point.x > point.y)
		*idwx += 3;
	else if (point.x < 1 - limit && point.x < point.y)
		*idwx += 2;
	else if (point.y > limit)
		*idwx += 1;
	// if (point.x > limit)
	// 	*idwx += 3;
	// else if (point.x < 1 - limit)
	// 	*idwx += 2;
	// else if (point.y > limit)
	// 	*idwx += 1;
}

double	get_x_dwall(t_dpoint *dpoint)
{
	t_dpoint	in_scale;
	t_dpoint	half;
	double		res;

	// in_scale = dpnt_mod(dpnt_divide(*dpoint, conv_ptod(all->map_size)));
	in_scale = dpnt_mod(*dpoint);
	half.x = in_scale.x > 0.5 ? 1.0 - in_scale.x : in_scale.x;
	half.y = in_scale.y > 0.5 ? 1.0 - in_scale.y : in_scale.y;
	if (half.x < half.y)
		res = in_scale.y;
	else
		res = in_scale.x;
	idxw_detect(*dpoint, &res);
	return (res);
}

t_project_plane	project_plane_set(t_all *all, double width_in_deg, double distance_to_plane)
{
	t_project_plane	prj;

	prj.width = degToRad(width_in_deg);
	prj.project.x = all->plr->x + distance_to_plane * cosf(all->plr->dir - degToRad(width_in_deg / 2));
	prj.project.y = all->plr->y + distance_to_plane * cosf(all->plr->dir - degToRad(width_in_deg / 2));
	prj.coef = prj.width / all->buff->size.x;
	return (prj);
}

void	draw_raycast(t_all *all)
{
	t_project_plane proj;
	t_dpoint	dpoint;
	int			h_wall;
	double		direction;
	int			i;

	proj = project_plane_set(all, 60, 0.5);
	direction = all->plr->dir + (proj.width / 2);
	dpoint = conv_pltod(*all->plr);

	i = -1;
	while(++i < all->buff->size.x)
	{
		shoot_ray(all, &dpoint, direction);
		proj.project = dpnt_plus(proj.project, dpnt_s(proj.coef));
		h_wall = height_wall(all, conv_pltod(*all->plr), dpoint, proj.project);
		draw_vpixel_line(all, i, h_wall, get_x_dwall(&dpoint));
		draw_line(all->img_map, 
			dpnt_multiple(	conv_pltod(*all->plr),	dpnt_s(SCALE >> 3)),
			dpnt_multiple(				dpoint,		dpnt_s(SCALE >> 3)), 0x0);
		dpoint = conv_pltod(*all->plr);
		direction -= proj.coef;
	}
}