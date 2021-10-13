/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_to_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:07:54 by name              #+#    #+#             */
/*   Updated: 2021/10/02 22:44:30 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_outer(int height, int length, t_all *all)
{
	if (height < 0 || length < 0
		|| height > all->map_height + 1 || length > all->map_length + 1
		|| all->map[height][length] == '1' || all->map[height][length] == '0'
		|| all->map[height][length] == all->plrpos.direction
		|| all->map[height][length] == 'M')
		return ;
	all->map[height][length] = 'M';
	fill_outer(height - 1, length, all);
	fill_outer(height - 1, length - 1, all);
	fill_outer(height, length - 1, all);
	fill_outer(height + 1, length - 1, all);
	fill_outer(height + 1, length, all);
	fill_outer(height + 1, length + 1, all);
	fill_outer(height, length + 1, all);
	fill_outer(height - 1, length + 1, all);
}

void	spaces_to_walls(t_all *all)
{
	int	i;
	int	j;

	fill_outer(0, 0, all);
	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == ' ')
				all->map[i][j] = '0';
		}
	}
	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == 'M')
				all->map[i][j] = ' ';
		}
	}
#ifdef DEBUG
{
	printf("\n-----------------------------------------------------------------\n\n");
	for (int i = 0; all->map[i]; i++)
	{
		printf("new_map[%3d]: |%s| ,len: %ld\n", i, all->map[i], ft_strlen(all->map[i]));
	}
}
#endif
}