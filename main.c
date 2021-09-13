/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:33:35 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/13 19:31:55 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usage(void)
{
	printf(CYAN "\vusage:\t"
		"./philo time_to_die"
		"time_to_eat time_to_sleep"
		"[number_of_times_each_philosopher_must_eat]" RESET);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		philo(argv + 1);
	else
		usage();
	return (0);
}
