#include "cub3d.h"

double	degToRad(double degree)
{
    return (degree / 180 * M_PI);
}

double  d_plus(double d)
{
    if (d < 0.000000000)
        return (-d);
    return (d);
}