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
		if (get_time() - watchdog->philo->dined_last_time >= watchdog->philo->time_to_die)
		{
			if (watchdog->philo->max_dined_times >= 0
				&& watchdog->philo->dined_times == watchdog->philo->max_dined_times)
				return (NULL);
			watchdog->philo->is_alive = false;
			msg(DIED, watchdog->philo, watchdog->msg_mutex);
			pthread_mutex_unlock(watchdog->eating_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(watchdog->eating_mutex);
		usleep(1000);
	}
	return (NULL);
}