#include "fdf.h"

static void	free_split(char **split)
{
	char **split_copy;

	split_copy = split;
	while (split_copy && *split_copy)
		free(*split_copy++);
	free(split);
}

static void	parse_values(t_list *map)
{
	char	**cont;
	char	**cont_copy;
	char	**vals;

	map->cur = map->head;
	while (TRUE)
	{
		cont = CUR_CONTENT;
		cont_copy = cont;
		map->cur->content = ft_calloc(1, sizeof(t_list));
		while (cont && *cont)
		{
			vals = ft_split(*cont, ',');
			ft_lstadd_back(CUR_EL_arrow, ft_calloc(5, sizeof(double)));
			*((double *)CUR_EL_arrow->end->content + 3) = ft_atoi(*vals);
			*((double *)CUR_EL_arrow->end->content + 4) = ft_atoi_base(*(vals + 1), 16);
			free_split(vals);
			cont++;
		}
		free_split(cont_copy);
		map->cur = map->cur->next;
		if (map->cur->prev == map->end)
			break ;
	}
}

static void	parse_map(char *map_name, t_list *map)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error();
	else if (read(fd, NULL, 0) < 0)
		error();
	while (TRUE)
	{
		if (!get_next_line(fd, &line))
		{
			free(line);
			break ;
		}
		ft_lstadd_back(map, ft_split(line, ' '));
		free(line);
	}
	parse_values(map);
	close(fd);
}

void	fdf(char *map_name)
{
	t_list	map;
	t_conf	mlx;
	t_mouse	mouse;

	ft_lst_init(1, &map);
	parse_map(map_name, &map);
	// parallel(map, &mlx);
	isometric(map, &mlx);
	mlx.instance = mlx_init();
	mlx.window = mlx_new_window(mlx.instance, LENGTH, WIDTH, "FDF");
	mouse.mlx = mlx;
	mouse.map = map;
	hooks_setup(&mouse);
	draw(map, mlx);
	mlx_loop(mlx.instance);
}
