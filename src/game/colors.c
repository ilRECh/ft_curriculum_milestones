#include "cub3d.h"

unsigned int create_rgb(int *color)
{
    if (!color)
        return (0x0);
    return (color[0] << 16 | color[1] << 8 | color[2]);
}