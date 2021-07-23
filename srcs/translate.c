#include "fdf.h"

void	translate(int tx, int ty, t_list map, t_conf mlx)
{
	while (TRUE)
	{
		CUR_EL_dot->cur = CUR_EL_dot->head;
		while (TRUE)
		{
			CUR_EL_dot_cont[0] += tx;
			CUR_EL_dot_cont[1] += ty;
			CUR_EL_dot->cur = CUR_EL_dot->cur->next;
			if (CUR_EL_dot->cur->prev == CUR_EL_dot->end)
				break ;
		}
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	draw(map, mlx);
}