#include "fdf.h"

void	scale(double coeff, t_list map)
{
	int	t[2];

	find_cp(t, map, NULL);
	translate(-t[0], -t[1], map);
	map.cur = map.head;
	while (TRUE)
	{
		CUR_EL_dot->cur = CUR_EL_dot->head;
		while (TRUE)
		{
			CUR_EL_dot_cont[0] *= coeff;
			CUR_EL_dot_cont[1] *= coeff;
			CUR_EL_dot_cont[2] *= coeff;
			CUR_EL_dot->cur = CUR_EL_dot->cur->next;
			if (CUR_EL_dot->cur->prev == CUR_EL_dot->end)
				break ;
		}
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	translate(t[0], t[1], map);
}