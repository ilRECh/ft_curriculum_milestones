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
		if (ft_lstsize(*CUR_EL_dot) > ixy->ox)
			ixy->ox = ft_lstsize(*CUR_EL_dot);
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
		CUR_EL_dot->cur = CUR_EL_dot->head;
		while (TRUE)
		{
			CUR_EL_dot_cont[0] = ixy.x;
			CUR_EL_dot_cont[1] = ixy.y;
			ixy.x += ixy.step;
			CUR_EL_dot->cur = CUR_EL_dot->cur->next;
			if (CUR_EL_dot->cur->prev == CUR_EL_dot->end)
				break ;
		}
		ixy.y += ixy.step;
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
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
		CUR_EL_dot->cur = CUR_EL_dot->head;
		while (TRUE)
		{
			CUR_EL_dot_cont[2] = CUR_EL_dot_cont[3];
			CUR_EL_dot_cont[0] = (ixy.x - ixy.y) * 0.866025;
			CUR_EL_dot_cont[1] = -(CUR_EL_dot_cont[2] * 2)
				+ (ixy.x + ixy.y) * 0.5;
			ixy.x += ixy.step;
			CUR_EL_dot->cur = CUR_EL_dot->cur->next;
			if (CUR_EL_dot->cur->prev == CUR_EL_dot->end)
				break ;
		}
		ixy.y += ixy.step;
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
}
