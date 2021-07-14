#ifndef PUT_PIXEL_H
# define PUT_PIXEL_H

# include "fdf.h"

static inline void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

#endif