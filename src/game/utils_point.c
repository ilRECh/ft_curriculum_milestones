#include "cub3d.h"

// int
// convert (DOUBLE t_dpoint) to (INT t_point)
t_point conv_dtop(t_dpoint dpoint)
{
	t_point point;

	point.x = dpoint.x;
	point.y = dpoint.y;
	return (point);
}

// convert t_plr to t_point
t_point conv_pltop(t_plr plr)
{
	t_point point;

	point.x = plr.x;
	point.y = plr.y;
	return (point);
}

// return (point + point)
t_point pnt_plus(t_point p1, t_point p2)
{
	t_point res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	return (res);
}

// return (point - point)
t_point pnt_minus(t_point p1, t_point p2)
{
	t_point res;

	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	return (res);
}

// return (point / point)
t_point pnt_divide(t_point p1, t_point p2)
{
	t_point res;

	res.x = p1.x / p2.x;
	res.y = p1.y / p2.y;
	return (res);
}

// return (point * point)
t_point pnt_multiple(t_point p1, t_point p2)
{
	t_point res;

	res.x = p1.x * p2.x;
	res.y = p1.y * p2.y;
	return (res);
}


// return (point.x = xy, point.y = xy)
t_point pnt_s(int xy)
{
	t_point res;

	res.x = xy;
	res.y = xy;
	return (res);
}


// return (point.x = x, point.y = y)
t_point pnt_set(int x, int y)
{
	t_point res;

	res.x = x;
	res.y = y;
	return (res);
}

//
/////////////// double
//

// return (get mantissa for X and Y in dpoint)
t_dpoint dpnt_mod(t_dpoint dpoint)
{
	t_dpoint mod;
	double	t;

	mod.x = modf(dpoint.x, &t);
	mod.y = modf(dpoint.y, &t);
	return (mod);
}

// convert (INT point) to (DOUBLE dpoint)
t_dpoint conv_ptod(t_point point)
{
	t_dpoint dpoint;

	dpoint.x = point.x;
	dpoint.y = point.y;
	return (dpoint);
}

// convert t_plr to t_dpoint
t_dpoint conv_pltod(t_plr plr)
{
	t_dpoint dpoint;

	dpoint.x = plr.x;
	dpoint.y = plr.y;
	return (dpoint);
}

// return (t_dpoint + t_dpoint);
t_dpoint dpnt_plus(t_dpoint p1, t_dpoint p2)
{
	t_dpoint res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	return (res);
}

// return (t_dpoint - t_dpoint);
t_dpoint dpnt_minus(t_dpoint p1, t_dpoint p2)
{
	t_dpoint res;

	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	return (res);
}

// return (t_dpoint / t_dpoint);
t_dpoint dpnt_divide(t_dpoint p1, t_dpoint p2)
{
	t_dpoint res;

	res.x = p1.x / p2.x;
	res.y = p1.y / p2.y;
	return (res);
}

// return (t_dpoint * t_dpoint);
t_dpoint dpnt_multiple(t_dpoint p1, t_dpoint p2)
{
	t_dpoint res;

	res.x = p1.x * p2.x;
	res.y = p1.y * p2.y;
	return (res);
}

// return (t_dpoint.x = x, t_dpoint.y = y);
t_dpoint dpnt_set(double x, double y)
{
	t_dpoint res;

	res.x = x;
	res.y = y;
	return (res);
}

// return (t_dpoint.x = xy, t_dpoint.y = xy);
t_dpoint dpnt_s(double xy)
{
	t_dpoint res;

	res.x = xy;
	res.y = xy;
	return (res);
}
