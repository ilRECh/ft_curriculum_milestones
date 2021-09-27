/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:11:31 by name              #+#    #+#             */
/*   Updated: 2021/09/27 13:03:55 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	usage(void)
{
	printf(CYAN "\vusage:\t" RESET
		GREEN_BOLD "./cub3d path_to_map\v\n" RESET);
}

void cub3d(void)
{
	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (parse(argv + 1, NULL))
			cub3d();
	}
	else
		usage();
	return (0);
}
