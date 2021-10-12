#include "cub3d.h"

void	set_plrpos(t_all *all, t_point map_size)
{
	t_point	i;

	i.x = (i.y = -1);
	while (++i.y < map_size.y)
	{
		while (++i.x < map_size.x)
		{
			if (ft_strchr("EWSN", all->map[i.y][i.x]))
			{
				all->plrpos.direction = all->map[i.y][i.x];
				all->plrpos.x = i.x;
				all->plrpos.y = i.y;
				i.y = map_size.y;
				break;
			}
		}
		i.x = -1;
	}
}

// Вызов должен быть осуществлен строго после ( set_plrpos(t_all, map_size); )
void	set_plr(t_all *all, float x, float y, float direction)
{
	all->plr = malloc(sizeof(t_plr));
	all->plr->x = x;
	all->plr->y = y;
	all->plr->dir = direction;
}
