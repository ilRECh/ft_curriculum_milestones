#include "fdf.h"

void	translate(int tx, int ty, t_list map)
{
	while (TRUE)
	{
		((t_list *)map.cur->content)->cur = ((t_list *)map.cur->content)->head;
		while (TRUE)
		{
			((double *)((t_list *)map.cur->content)->cur->content)[0] += tx;
			((double *)((t_list *)map.cur->content)->cur->content)[1] += ty;
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
}
