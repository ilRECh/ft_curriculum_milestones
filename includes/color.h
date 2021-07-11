#ifndef COLOR_H
# define COLOR_H

static inline uint32_t	create_trgb(uint32_t t, uint32_t r, uint32_t g, uint32_t b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static inline uint8_t	get_t(int trgb)
{
	return ((trgb & (0xFF << 24)) >> 24);
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

#endif