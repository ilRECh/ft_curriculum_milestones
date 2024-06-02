#include "fdf.h"
#include "put_pixel.h"
#include "color.h"

typedef struct s_xy
{
	double	dx;
	double	sx;
	double	dy;
	double	sy;
	double	err;
}	t_xy;

static int	get_color(double const *p0, double const *p0_main,
	double const *p1)
{
	double	coeff;

	coeff = sqrt((p1[0] - p0[0]) * (p1[0] - p0[0])
			+ (p1[1] - p0[1]) * (p1[1] - p0[1]))
		/ sqrt((p1[0] - p0_main[0]) * (p1[0] - p0_main[0])
			+ (p1[1] - p0_main[1]) * (p1[1] - p0_main[1]));
	return (create_trgb(get_r(p1[3])
			+ (get_r(p0_main[3]) - get_r(p1[3])) * coeff,
			get_g(p1[3]) + (get_g(p0_main[3]) - get_g(p1[3])) * coeff,
			get_b(p1[3]) + (get_b(p0_main[3]) - get_b(p1[3])) * coeff));
}

static inline void	init_xy(t_xy *xy, double *p0,
	double const *p1, double const *p0_main)
{
	p0[0] = p0_main[0];
	p0[1] = p0_main[1];
	p0[3] = p0_main[3];
	xy->dx = fabs(p1[0] - p0[0]);
	if (p1[0] > p0[0])
		xy->sx = 1;
	else
		xy->sx = -1;
	xy->dy = -fabs(p1[1] - p0[1]);
	if (p1[1] > p0[1])
		xy->sy = 1;
	else
		xy->sy = -1;
	xy->err = xy->dx + xy->dy;
}

static void	draw_line(double const *p0_main, double const *p1, t_conf mlx)
{
	t_xy	xy;
	double	p0[4];

	init_xy(&xy, p0, p1, p0_main);
	while (TRUE)
	{
		if (p0[0] >= 50 && p0[0] <= 1870 && p0[1] >= 50 && p0[1] <= 1030)
			put_pixel(&mlx.img, p0[0], p0[1], get_color(p0, p0_main, p1));
		if (fabs(fabs(p0[0]) - fabs(p1[0])) <= 1.5
			&& fabs(fabs(p0[1]) - fabs(p1[1])) <= 1.5)
			break ;
		if (2 * xy.err >= xy.dy)
		{
			xy.err += xy.dy;
			p0[0] += xy.sx;
		}
		if (2 * xy.err <= xy.dx)
		{
			xy.err += xy.dx;
			p0[1] += xy.sy;
		}
	}
}

static void	draw_vlines(t_list map, t_conf mlx)
{
	map.cur = map.head;
	while (TRUE)
	{
		((t_list *)map.cur->content)->cur = ((t_list *)map.cur->content)->head;
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	while (TRUE)
	{
		map.cur = map.head;
		while (TRUE)
		{
			additional_draw_line(&map, mlx);
			if (map.cur == map.end)
			{
				((t_list *)map.cur->content)->cur
					= ((t_list *)map.cur->content)->cur->next;
				break ;
			}
		}
		if (((t_list *)map.cur->content)->cur->prev
			== ((t_list *)map.cur->content)->end)
			break ;
	}
}

void	draw(t_list map, t_conf mlx)
{
	mlx.img.img = mlx_new_image(mlx.instance, LENGTH, WIDTH);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img,
			&mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	map.cur = map.head;
	while (TRUE)
	{
		((t_list *)map.cur->content)->cur = ((t_list *)map.cur->content)->head;
		while (((t_list *)map.cur->content)->cur
			!= ((t_list *)map.cur->content)->end)
		{
			draw_line(((t_list *)map.cur->content)->cur->content,
				((t_list *)map.cur->content)->cur->next->content, mlx);
			((t_list *)map.cur->content)->cur
				= ((t_list *)map.cur->content)->cur->next;
		}
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	draw_vlines(map, mlx);
	mlx_put_image_to_window(mlx.instance, mlx.window, mlx.img.img, 0, 0);
}
