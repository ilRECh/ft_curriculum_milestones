#include "fdf.h"
#include "put_pixel.h"

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
			ft_lstadd_back(CUR_EL, ft_calloc(2, sizeof(int)));
			*((int *)CUR_EL->end->content) = ft_atoi(*vals);
			*((int *)CUR_EL->end->content + 1) = ft_atoi_base(*(vals + 1), 16);
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
}

void	fdf(char *map_name)
{
	t_list	map;

	ft_lst_init(1, &map);
	parse_map(map_name, &map);
}
// (void)map;
// t_conf	mlx;
// int a = 10;
// int b = 10;

// mlx.instance = mlx_init();
// mlx.window = mlx_new_window(mlx.instance, 1920, 1080, "FDF");
// mlx.img.img = mlx_new_image(mlx.instance, 1920, 1080);
// mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length,
// 		&mlx.img.endian);
// while (a--)
// {
// 	while (b--)
// 		my_mlx_pixel_put(&mlx.img, 5 + a, 5 + b, 0x00FF0000);
// 	b = 10;
// }
// mlx_put_image_to_window(mlx.instance, mlx.window, mlx.img.img, 0, 0);
// mlx_loop(mlx.instance);
