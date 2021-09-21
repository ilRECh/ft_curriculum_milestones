/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:36:42 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/17 20:44:30 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*I_SEE_YOU(void *arg)
{
	t_watchdog	*watchdog;

	watchdog = arg;
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(watchdog->eating_mutex);
		//printf("%lu %lu %lu\n", get_time(), watchdog->philo->dined_last_time, watchdog->philo->time_to_die);
		if (get_time() - watchdog->philo->dined_last_time >= watchdog->philo->time_to_die)
		{
			msg(DIED, watchdog->philo->num, watchdog->msg_mutex);
			pthread_mutex_unlock(watchdog->eating_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(watchdog->eating_mutex);
		usleep(1000);
	}
	return (NULL);
}