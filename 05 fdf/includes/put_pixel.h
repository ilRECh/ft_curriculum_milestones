#ifndef PUT_PIXEL_H
# define PUT_PIXEL_H

# include "fdf.h"

static inline void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

#endif