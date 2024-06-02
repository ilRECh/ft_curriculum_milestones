#include "fdf.h"

void	scale(double coeff, t_list map)
{
	int	t[2];

	find_cp(t, map, NULL);
	translate(-t[0], -t[1], map);
	map.cur = map.head;
	while (TRUE)
	{
		((t_list *)map.cur->content)->cur = ((t_list *)map.cur->content)->head;
		while (TRUE)
		{
			((double *)((t_list *)map.cur->content)->cur->content)[0] *= coeff;
			((double *)((t_list *)map.cur->content)->cur->content)[1] *= coeff;
			((double *)((t_list *)map.cur->content)->cur->content)[2] *= coeff;
			((t_list *)map.cur->content)->cur
				= ((t_list *)map.cur->content)->cur->next;
			if (((t_list *)map.cur->content)->cur->prev
				== ((t_list *)map.cur->content)->end)
				break ;
		}
		map.cur = map.cur->next;
		if (map.cur->prev == map.end)
			break ;
	}
	translate(t[0], t[1], map);
}
