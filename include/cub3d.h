/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:36:39 by name              #+#    #+#             */
/*   Updated: 2021/09/28 10:52:50 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define FLOOR 0
# define CEILLING 1
# define SCALE 16 // условный размер каждого квадратика в карте

# define DEBUG

///
///	DATA
///
typedef struct s_win //структура для окна
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		line_l;
	int		bpp;
	int		en;
}	t_win;

typedef struct s_point // структура для точки
{
	int	x;
	int	y;
}	t_point;

typedef struct s_plr //структура для игрока и луча
{
	float	x;
	float	y;
	float	dir;
	float	start;
	float	end;
}	t_plr;

typedef struct s_all // структура для всего вместе
{
	t_win	*win;
	t_plr	*plr;
	char	**textures;
	int		**colors;
	char	**map;
	char	*err;
}	t_all;

///
///	PARSING
///
bool	parse(t_all *all, int fd);
bool	setup_params(t_all *all, t_list *lst);
bool	setup_map(t_all *all, t_list *lst);

///
/// CLEANING
///
bool	fl(t_list *lst);
bool	flf(t_list *lst, int fd);
bool	fs(char **split);

#endif //CUB3D_H