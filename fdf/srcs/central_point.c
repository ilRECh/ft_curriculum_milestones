#include "fdf.h"

static inline void	compare(double *max_min, double *point)
{
	if (point[0] < max_min[0])
		max_min[0] = point[0];
	if (point[0] > max_min[2])
		max_min[2] = point[0];
	if (point[1] < max_min[1])
		max_min[1] = point[1];
	if (point[1] > max_min[3])
		max_min[3] = point[1];
}

static inline void	setup_mm(int *t, double *max_min, double *main_mm)
{
	t[0] = max_min[0] + (max_min[2] - max_min[0]) / 2;
	t[1] = max_min[1] + (max_min[3] - max_min[1]) / 2;
	if (main_mm)
	{
		main_mm[0] = max_min[0];
		main_mm[1] = max_min[1];
		main_mm[2] = max_min[2];
		main_mm[3] = max_min[3];
	}
}

static inline void	presetup_mm(double *max_min, double *head)
{
	max_min[0] = head[0];
	max_min[1] = head[1];
	max_min[2] = head[0];
	max_min[3] = head[1];
}

// min_x: 0, min_y: 1, max_x: 2, max_y: 3
void	find_cp(int	*t, t_list map, double *main_mm)
{
	double	max_min[4];

	map.cur = map.head;
	((t_list *)map.cur->content)->cur = ((t_list *)map.cur->content)->head;
	presetup_mm(max_min,
		((double *)((t_list *)map.cur->content)->cur->content));
	while (TRUE)
	{
		((t_list *)map.cur->content)->cur = ((t_list *)map.cur->content)->head;
		while (TRUE)
		{
			compare(max_min,
				((double *)((t_list *)map.cur->content)->cur->content));
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
	setup_mm(t, max_min, main_mm);
}
