#ifndef COLOR_H
# define COLOR_H

static void	draw_line(double const *p0_main, double const *p1, t_conf mlx);

static inline uint32_t	create_trgb(uint32_t r, uint32_t g, uint32_t b)
{
	return (r << 16 | g << 8 | b);
}

static inline uint8_t	get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

static inline uint8_t	get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8);
}

static inline uint8_t	get_b(int trgb)
{
	return (trgb & 0xFF);
}

static inline void	additional_draw_line(t_list *map, t_conf mlx)
{
	draw_line(((t_list *)map->cur->content)->cur->content,
		((t_list *)map->cur->next->content)->cur->content, mlx);
	((t_list *)map->cur->content)->cur
		= ((t_list *)map->cur->content)->cur->next;
	map->cur = map->cur->next;
}

#endif