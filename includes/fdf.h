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
# define HEAD_EL ((t_list *)map->head->content)
# define CUR_EL ((t_list *)map->cur->content)
# define END_EL ((t_list *)map->cur->content)

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

static inline void	error(void)
{
	ft_printf(RED "ERROR: %s\n" RESET, strerror(errno));
	exit(1);
}

#endif