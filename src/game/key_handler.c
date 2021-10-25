#include "cub3d.h"

bool	check_in_radius(char **map, t_dpoint pnt, float radius)
{
	int			i;

	i = -1;
	while (++i < 360)
		if (map [(int)(pnt.y + (cos(degToRad(i)) * radius))] \
				[(int)(pnt.x + (sin(degToRad(i)) * radius))] == '1')
			return (false);
	return (true);
}

int	close_x()
{
	exit(EXIT_SUCCESS);
}

void	key_handler(int key_code, t_all *all)
{
	if (key_code == 0)
		all->plr->dir += degToRad(5);
	else if (key_code == 2)
		all->plr->dir -= degToRad(5);
	else if (key_code == 13)
	{
		if (check_in_radius(all->map, dpnt_plus(conv_pltod(*all->plr), \
			dpnt_set(sinf(all->plr->dir) / 2, 0)), 0.3f))
			all->plr->x += sinf(all->plr->dir) * 0.33;
		if (check_in_radius(all->map, dpnt_plus(conv_pltod(*all->plr), \
			dpnt_set(0, cosf(all->plr->dir) / 2)), 0.3f))
			all->plr->y += cosf(all->plr->dir) * 0.33;
	}
	else if (key_code == 1)
	{
		if (check_in_radius(all->map, dpnt_minus(conv_pltod(*all->plr), \
			dpnt_set(sinf(all->plr->dir) / 2, 0)), 0.3f))
			all->plr->x -= sinf(all->plr->dir) * 0.33;
		if (check_in_radius(all->map, dpnt_minus(conv_pltod(*all->plr), \
			dpnt_set(0, cosf(all->plr->dir) / 2)), 0.3f))
			all->plr->y -= cosf(all->plr->dir) * 0.33;
	}
	if (key_code == 53)
		exit (0);
}