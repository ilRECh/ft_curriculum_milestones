#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <string.h>
# include <math.h>

# define WIDTH 1080
# define LENGTH 1920
# define PARALLEL 1
# define ISOMETRIC 2
# define DRAW_STEP 50

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_conf
{
	void	*instance;
	void	*window;
	uint8_t	projection;
	t_img	img;
}	t_conf;

typedef struct s_mouse
{
	uint8_t	is_pressed;
	int		x;
	int		y;
	t_conf	mlx;
	t_list	map;
}	t_mouse;

void	fdf(char *map_name);
void	draw(t_list map, t_conf mlx);
void	parallel(t_list map, t_conf *mlx);
void	isometric(t_list map, t_conf *mlx);
void	hooks_setup(t_mouse *mouse);
void	translate(int tx, int ty, t_list map);
void	scale(double coeff, t_list map);
void	rotate(int rx, int ry, t_list map);
void	find_cp(int	*t, t_list map, double *main_mm);

static inline void	error(void)
{
	write(1, RED "ERROR: " RESET, 18);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
	exit(1);
}

#endif