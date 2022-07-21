/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:11:31 by name              #+#    #+#             */
/*   Updated: 2021/10/29 19:39:13 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	usage(void)
{
	printf(CYAN "\vusage:\t" RESET
		GREEN_BOLD "./cub3d path_to_the_map\v\n" RESET);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (cub3d(argv[1]));
	else
		usage();
	return (0);
}
