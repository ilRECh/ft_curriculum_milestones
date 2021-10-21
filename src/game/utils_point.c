#include "cub3d.h"

// int

t_point conv_dtop(t_dpoint dpoint)
{
	t_point point;

	point.x = dpoint.x;
	point.y = dpoint.y;
	return (point);
}

t_point conv_pltop(t_plr plr)
{
	t_point point;

	point.x = plr.x;
	point.y = plr.y;
	return (point);
}

t_point pnt_plus(t_point p1, t_point p2)
{
	t_point res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	return (res);
}

t_point pnt_minus(t_point p1, t_point p2)
{
	t_point res;

	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	return (res);
}

t_point pnt_divide(t_point p1, t_point p2)
{
	t_point res;

	res.x = p1.x / p2.x;
	res.y = p1.y / p2.y;
	return (res);
}

t_point pnt_multiple(t_point p1, t_point p2)
{
	t_point res;

	res.x = p1.x * p2.x;
	res.y = p1.y * p2.y;
	return (res);
}


t_point pnt_s(int xy)
{
	t_point res;

	res.x = xy;
	res.y = xy;
	return (res);
}

void pnt_swap_xy(t_point *p)
{
	float t;

	if (p)
	{
		t = p->x;
		p->x = p->y;
		p->y = t;
	}
}

t_point pnt_set(int x, int y)
{
	t_point res;

	res.x = x;
	res.y = y;
	return (res);
}

/////////////// double

t_dpoint dpnt_mod(t_dpoint dpoint)
{
	t_dpoint mod;
	double	t;

	mod.x = modf(dpoint.x, &t);
	mod.y = modf(dpoint.y, &t);
	return (mod);
}

t_dpoint conv_ptod(t_point point)
{
	t_dpoint dpoint;

	dpoint.x = point.x;
	dpoint.y = point.y;
	return (dpoint);
}

t_dpoint conv_pltod(t_plr plr)
{
	t_dpoint dpoint;

	dpoint.x = plr.x;
	dpoint.y = plr.y;
	return (dpoint);
}

t_dpoint dpnt_plus(t_dpoint p1, t_dpoint p2)
{
	t_dpoint res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	return (res);
}

t_dpoint dpnt_minus(t_dpoint p1, t_dpoint p2)
{
	t_dpoint res;

	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	return (res);
}

t_dpoint dpnt_divide(t_dpoint p1, t_dpoint p2)
{
	t_dpoint res;

	res.x = p1.x / p2.x;
	res.y = p1.y / p2.y;
	return (res);
}

t_dpoint dpnt_multiple(t_dpoint p1, t_dpoint p2)
{
	t_dpoint res;

	res.x = p1.x * p2.x;
	res.y = p1.y * p2.y;
	return (res);
}

t_dpoint dpnt_set(double x, double y)
{
	t_dpoint res;

	res.x = x;
	res.y = y;
	return (res);
}

void dpnt_swap_xy(t_dpoint *p)
{
	float t;

	if (p)
	{
		t = p->x;
		p->x = p->y;
		p->y = t;
	}
}

t_dpoint dpnt_s(double xy)
{
	t_dpoint res;

	res.x = xy;
	res.y = xy;
	return (res);
}
