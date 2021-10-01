/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 22:25:24 by name              #+#    #+#             */
/*   Updated: 2021/10/02 00:11:52 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define UP 0
#define UPLEFT 1 
#define LEFT 2
#define DOWNLEFT 3 
#define DOWN 4
#define DOWNRIGHT 5 
#define RIGHT 6
#define UPRIGHT 7

static inline bool	err_at(int i, int j, t_all *all)
{
	char	*tmp[2];

	tmp[0] = ft_strndup(all->map[i - 1] + j - 1, 4);
	tmp[0][3] = '\n';
	tmp[1] = ft_strndup(all->map[i] + j - 1, 4);
	tmp[1][3] = '\n';
	all->err = ft_strjoin(tmp[0], tmp[1]);
	free(tmp[0]), free(tmp[1]);
	tmp[0] = ft_strndup(all->map[i + 1] + j - 1, 3);
	tmp[1] = all->err;
	all->err = ft_strjoin(all->err, tmp[0]);
	free(tmp[0]), free(tmp[1]);
	return (true);
}

static bool	check(int i, int j, t_all *all, bool go)
{
	int					dir;
	static const int	dirs[8][2] = {
		{-1, 0},
		{-1, -1},
		{0, -1},
		{1, -1},
		{1, 0},
		{1, 1},
		{0, 1},
		{-1, 1}
	};

	dir = 0;
	if ((all->map[i][j] == ' ' && ++dir) || all->map[i][j] == '1')
		return (dir);
	while (dir < 8)
	{
		if (check(i + dirs[dir][0], j + dirs[dir][1], all, false))
			return (err_at(i, j, all), true);
		if (go)
			dir++;
		else
			return (false);
	}
	return (false);
}

bool	check_closed(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '0'
				|| all->map[i][j] == all->plrpos.direction)
				if (check(i, j, all, true))
					return (true);
		}
	}
	return (false);
}
