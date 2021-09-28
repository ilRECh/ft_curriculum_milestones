/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:11:31 by name              #+#    #+#             */
/*   Updated: 2021/09/28 22:30:05 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	usage(void)
{
	printf(CYAN "\vusage:\t" RESET
		GREEN_BOLD "./cub3d path_to_map\v\n" RESET);
}

int	cub3d(char *map)
{
	static t_all	all;
	int				fd;

	if (!ft_strrchr(map, '.') || ft_strncmp(ft_strrchr(map, '.') + 1, "cub", 4))
	{
		printf(RED "Error\n" RESET "invalid file\n");
		return (1);
	}
	fd = open(map, O_RDONLY);
	if (!fd || (read(fd, NULL, 0) < 0 && !close(fd)))
	{
		printf(RED "Error\n" RESET "invalid file\n");
		return (1);
	}
	if (!setup_all(&all))
	{
		printf(RED "Error\n" RESET "no space left\n");
		return (1);
	}
	if (parse(&all, fd))
	{
		printf(RED "Error\n" RESET "invalid file formatting: %s\n", all.err);
		fall(&all);
		return (1);
	}
	close(fd);
	//game(&all);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (cub3d(argv[1]));
	else
		usage();
	return (0);
}
