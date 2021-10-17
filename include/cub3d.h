/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:36:39 by name              #+#    #+#             */
/*   Updated: 2021/10/15 17:19:29 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define FLOOR 4
# define CEILLING 5
# define SCALE 16 // условный размер каждого квадратика в карте
# define MAP_SIZE 4096 // условный размер карты в виртуальной реальности

# define DEBUG

///
///	DATA
///
typedef struct s_point // структура для точки | и размеров
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image // структура для изображений
{
	void	*img;
	void	*addr;
	t_point	size;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

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
	t_image	*buff;
	t_image whalls[4];
	t_image *img_map;
	t_point	screen_size;
	char	**textures;
	int		**colors;
	char	**map;

	// предлагаю использовать вместо  |
	// этих переменных, структуру	  |
	int		map_length;
	int		map_height;
	// Вот эту структуру ниже		 \|/
	t_point	map_size;
	//--
	struct s_plrpos
	{
		int	x;
		int	y;
		char	direction;
	}		plrpos;
	char	*err;
}	t_all;

///
///	PARSING
///
bool	parse(t_all *all, int fd);
bool	setup_all(t_all *all);
bool	setup_params(t_all *all, t_list *lst);
bool	setup_map(t_all *all, t_list *lst);
bool	check_num(char *number);
bool	check_len_value(char **rgb);
bool	setup_missing(t_all *all);
bool	make_map_from_lst(t_all *all, t_list *lst);
bool	check_symbols(t_all *all, t_list *lst);
bool	check_closed(t_all *all);
void	spaces_to_walls(t_all *all);
bool	check_extra_regions(t_all *all);

///
/// CLEANING
///
bool	fl(t_list *lst);
bool	flf(t_list *lst, int fd);
bool	fs(char **split);
bool	fall(t_all *all);

//
// game
//
bool	game(t_all *all);
// img map
t_image	*draw_mini_map(t_all *all);
// plr
void	set_plrpos(t_all *all);
void	set_plr(t_all *all, float x, float y, float direction);
void	player_in_map(t_all *all, t_image *img_map);
// image create
t_image	*new_image(void *mlx, t_point size);
void    image_to_image_cp(t_image *dst, t_image *src, t_point position);
void    image_to_image_cp_insert_clr(t_image *dst, t_image *src, t_point position, unsigned int ins_scolor);
void	pixel_put(t_image *img, t_point p, unsigned int colour);
unsigned int	pixel_get(t_image *img, t_point	p);
void	fill_rect_to_img(t_image *img, const t_point *start, \
	const t_point *end, const unsigned int colour);
void	set_background(t_all *all);

//
// utils_int
//
int max_min(int a, int b, bool updown);
// utils_point
t_point point_set(int x, int y);
void	point_swap_xy(t_point *p);
t_point point_plus(t_point p1, t_point p2);
t_point point_minus(t_point p1, t_point p2);
t_point point_divide(t_point p1, t_point p2);
t_point point_multiple(t_point p1, t_point p2);

//
//	wrappers
//
int		image_to_window(t_all *all, const t_image *img, t_point position);
t_image	*xpm_to_new_image(t_all *all, char *path_to_xpm);
t_image	xpm_to_image(t_all *all, char *path_to_xpm);
int	image_free(t_all *all, t_image	*img, bool mode);

#endif //CUB3D_H
