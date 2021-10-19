#include "cub3d.h"

// int

t_point convert_dpoint_to_point(t_dpoint dpoint)
{
    t_point point;

    point.x = dpoint.x;
    point.x = dpoint.x;
    return (point);
}

t_point convert_plr_to_point(t_plr plr)
{
    t_point point;

    point.x = plr.x;
    point.y = plr.y;
    return (point);
}

t_point point_plus(t_point p1, t_point p2)
{
    t_point res;

    res.x = p1.x + p2.x;
    res.y = p1.y + p2.y;
    return (res);
}

t_point point_minus(t_point p1, t_point p2)
{
    t_point res;

    res.x = p1.x - p2.x;
    res.y = p1.y - p2.y;
    return (res);
}

t_point point_divide(t_point p1, t_point p2)
{
    t_point res;

    res.x = p1.x / p2.x;
    res.y = p1.y / p2.y;
    return (res);
}

t_point point_multiple(t_point p1, t_point p2)
{
    t_point res;

    res.x = p1.x * p2.x;
    res.y = p1.y * p2.y;
    return (res);
}

t_point point_set(int x, int y)
{
    t_point res;

    res.x = x;
    res.y = y;
    return (res);
}

void point_swap_xy(t_point *p)
{
    float t;

    if (p)
    {
        t = p->x;
        p->x = p->y;
        p->y = t;
    }
}

/////////////// double

t_dpoint convert_point_to_dpoint(t_point point)
{
    t_dpoint dpoint;

    dpoint.x = point.x;
    dpoint.x = point.x;
    return (dpoint);
}

t_dpoint convert_plr_to_dpoint(t_plr plr)
{
    t_dpoint dpoint;

    dpoint.x = plr.x;
    dpoint.y = plr.y;
    return (dpoint);
}

t_dpoint dpoint_plus(t_dpoint p1, t_dpoint p2)
{
    t_dpoint res;

    res.x = p1.x + p2.x;
    res.y = p1.y + p2.y;
    return (res);
}

t_dpoint dpoint_minus(t_dpoint p1, t_dpoint p2)
{
    t_dpoint res;

    res.x = p1.x - p2.x;
    res.y = p1.y - p2.y;
    return (res);
}

t_dpoint dpoint_divide(t_dpoint p1, t_dpoint p2)
{
    t_dpoint res;

    res.x = p1.x / p2.x;
    res.y = p1.y / p2.y;
    return (res);
}

t_dpoint dpoint_multiple(t_dpoint p1, t_dpoint p2)
{
    t_dpoint res;

    res.x = p1.x * p2.x;
    res.y = p1.y * p2.y;
    return (res);
}

t_dpoint dpoint_set(double x, double y)
{
    t_dpoint res;

    res.x = x;
    res.y = y;
    return (res);
}

void dpoint_swap_xy(t_dpoint *p)
{
    float t;

    if (p)
    {
        t = p->x;
        p->x = p->y;
        p->y = t;
    }
}
