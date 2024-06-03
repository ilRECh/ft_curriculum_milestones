/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:36:42 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/22 18:59:20 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*I_SEE_YOU(void *arg)
{
	t_watchdog	*watchdog;
	uint64_t	tm;

	watchdog = arg;
	while (1)
	{
		usleep(10);
		pthread_mutex_lock(watchdog->eating_mutex);
		tm = get_time() + 3;
		if (tm - watchdog->philo->dined_last_time
			> watchdog->philo->time_to_die)
		{
			if (watchdog->philo->max_dined_times >= 0
				&& watchdog->philo->dined_times
				== watchdog->philo->max_dined_times)
				return (NULL);
			watchdog->philo->is_alive = false;
			msg(DIED, watchdog->philo, watchdog->msg_mutex);
			pthread_mutex_unlock(watchdog->eating_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(watchdog->eating_mutex);
	}
	return (NULL);
}

void	free_all(t_table *table)
{
	table->i = -1;
	while (++table->i < table->philos)
	{
		pthread_join(table->Aphilos[table->i].life_th, NULL);
		pthread_join(table->Awatchdogs[table->i].watch_th, NULL);
	}
	table->i = -1;
	while (++table->i < table->philos)
		pthread_mutex_destroy(table->Amutexes + table->i);
	free(table->Amutexes);
	table->i = -1;
	while (++table->i < table->philos)
	{
		pthread_mutex_destroy(table->Aphilos[table->i].eating_mutex);
		free(table->Aphilos[table->i].eating_mutex);
	}
	free(table->Aphilos);
	free(table->Awatchdogs);
	pthread_mutex_destroy(&table->msg_mutex);
}
