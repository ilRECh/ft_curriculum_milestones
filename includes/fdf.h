#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <errno.h>
# include <string.h>
# include <math.h>

# define HEAD_CONTENT ((char **)map->head->content)
# define CUR_CONTENT ((char **)map->cur->content)
# define END_CONTENT ((char **)map->end->content)

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_conf
{
	void	*instance;
	void	*window;
	t_data	img;
}	t_conf;

typedef struct s_cont
{
	char **arg;
}	t_cont;

void	fdf(char *map_name);

#endif