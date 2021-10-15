#include "cub3d.h"

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
