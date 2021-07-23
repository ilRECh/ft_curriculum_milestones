#include "fdf.h"
#include "put_pixel.h"

typedef struct s_xy
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
}	t_xy;

static inline void	init_xy(t_xy *xy, int *p0,
	int const *p1, int const *p0_main)
{
	p0[0] = p0_main[0];
	p0[1] = p0_main[1];
	xy->dx = abs(p1[0] - p0[0]);
	if (p1[0] > p0[0])
		xy->sx = 1;
	else
		xy->sx = -1;
	xy->dy = -abs(p1[1] - p0[1]);
	if (p1[1] > p0[1])
		xy->sy = 1;
	else
		xy->sy = -1;
	xy->err = xy->dx + xy->dy;
}

static void	draw_line(int const *p0_main, int const *p1, t_conf mlx)
{
	t_xy	xy;
	int		p0[2];

	init_xy(&xy, p0, p1, p0_main);
	while (TRUE)
	{
		if (p0[0] >= 50 && p0[0] <= 1870 && p0[1] >= 50 && p0[1] <= 1030)
			put_pixel(&mlx.img, p0[0], p0[1], 0x00ff00ff);
		if (abs(abs(p0[0]) - abs(p1[0])) <= 1
			&& abs(abs(p0[1]) - abs(p1[1])) <= 1)
			break;
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
		CUR_EL_dot->cur = CUR_EL_dot->head;
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	while (TRUE)
	{
		map.cur = map.head;
		while (TRUE)
		{
			draw_line(CUR_EL_dot->cur->content, CUR_EL_NEXT_dot->cur->content, mlx);
			CUR_EL_dot->cur = CUR_EL_dot->cur->next;
			map.cur = map.cur->next;
			if (map.cur == map.end)
			{
				CUR_EL_dot->cur = CUR_EL_dot->cur->next;
				break ;
			}
		}
		if (CUR_EL_dot->cur->prev == CUR_EL_dot->end)
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
		CUR_EL_dot->cur = CUR_EL_dot->head;
		while (CUR_EL_dot->cur != CUR_EL_dot->end)
		{
			draw_line(CUR_EL_dot->cur->content, CUR_EL_dot->cur->next->content, mlx);
			CUR_EL_dot->cur = CUR_EL_dot->cur->next;
		}
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	draw_vlines(map, mlx);
	mlx_put_image_to_window(mlx.instance, mlx.window, mlx.img.img, 0, 0);
}
