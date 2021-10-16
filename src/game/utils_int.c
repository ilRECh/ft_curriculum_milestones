#include "cub3d.h"

int max_min(int a, int b, bool updown)
{
    if (updown)
    {
        if (a > b)
            return (a);
        else
            return (b);
    }
    else
    {
        if (a < b)
            return (a);
        else
            return (b);
    }
}