#include "fdf.h"

typedef struct s_init_xy
{
	int	ox;
	int	oy;
	int	x;
	int	y;
	int	step;
}	t_ixy;

static void	init_xy(t_list map, t_ixy *ixy)
{
	ixy->oy = ft_lstsize(map);
	ixy->ox = 0;
	map.cur = map.head;
	while (TRUE)
	{
		if (ft_lstsize(*((t_list *)map.cur->content)) > ixy->ox)
			ixy->ox = ft_lstsize(*((t_list *)map.cur->content));
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	if (1820 / ixy->ox > 980 / ixy->oy)
		ixy->step = 980 / ixy->oy;
	else
		ixy->step = 1820 / ixy->ox;
	ixy->ox = (1920 - ixy->ox * ixy->step) / 2;
	ixy->oy = (1080 - ixy->oy * ixy->step) / 2;
	ixy->y = ixy->oy;
}

void	parallel(t_list map, t_conf *mlx)
{
	t_ixy	ixy;

	mlx->projection = PARALLEL;
	init_xy(map, &ixy);
	map.cur = map.head;
	while (TRUE)
	{
		ixy.x = ixy.ox;
		((t_list *)map.cur->content)->cur = ((t_list *)map.cur->content)->head;
		while (TRUE)
		{
			((double *)((t_list *)map.cur->content)->cur->content)[0] = ixy.x;
			((double *)((t_list *)map.cur->content)->cur->content)[1] = ixy.y;
			ixy.x += ixy.step;
			((t_list *)map.cur->content)->cur
				= ((t_list *)map.cur->content)->cur->next;
			if (((t_list *)map.cur->content)->cur->prev
				== ((t_list *)map.cur->content)->end)
				break ;
		}
		ixy.y += ixy.step;
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
}

static void	setup_isometric(t_ixy *ixy, double *arr)
{
	arr[2] = arr[4];
	arr[0] = (ixy->x - ixy->y) * 0.866025;
	arr[1] = -(arr[2] * 3)
		+ (ixy->x + ixy->y) * 0.5;
	ixy->x += ixy->step;
}

static void	centralize_isometric(t_list map)
{
	double	max_min[4];
	int		t[2];

	find_cp(t, map, max_min);
	if (1820 / (max_min[2] - max_min[0]) < 980 / (max_min[3] - max_min[1]))
		scale(1820 / (max_min[2] - max_min[0]), map);
	else
		scale(980 / (max_min[3] - max_min[1]), map);
	translate(960 - t[0], 540 - t[1], map);
}

void	isometric(t_list map, t_conf *mlx)
{
	t_ixy	ixy;

	mlx->projection = ISOMETRIC;
	init_xy(map, &ixy);
	map.cur = map.head;
	while (TRUE)
	{
		ixy.x = ixy.ox;
		((t_list *)map.cur->content)->cur = ((t_list *)map.cur->content)->head;
		while (TRUE)
		{
			setup_isometric(&ixy,
				((double *)((t_list *)map.cur->content)->cur->content));
			((t_list *)map.cur->content)->cur
				= ((t_list *)map.cur->content)->cur->next;
			if (((t_list *)map.cur->content)->cur->prev
				== ((t_list *)map.cur->content)->end)
				break ;
		}
		ixy.y += ixy.step;
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	centralize_isometric(map);
}
