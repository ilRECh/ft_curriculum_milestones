/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:33:35 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/14 18:25:58 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	usage(void)
{
	printf(CYAN "\vusage:\t" RESET
		GREEN_BOLD "./philo time_to_die "
		"time_to_eat time_to_sleep " RESET
		GREEN "[number_of_times_each_philosopher_must_eat]\v\n" RESET);
}

int32_t	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		return (philo(argc - 1, argv + 1));
	else
		usage();
	return (0);
}
