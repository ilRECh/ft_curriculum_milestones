/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:33:31 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/17 20:42:59 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	think(t_philosopher *philo)
{
	msg(THINK, philo->num, philo->msg_mutex);
	return (0);
}

static int	mysleep(t_philosopher *philo)
{
	msg(SLEEP, philo->num, philo->msg_mutex);
	usleep(philo->time_to_sleep * 1000);
	return (0);
}

static int	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->Amutexes[philo->right_fork]);
	msg(FORK, philo->num, philo->msg_mutex);
	pthread_mutex_lock(&philo->table->Amutexes[philo->left_fork]);
	philo->dined_last_time = get_time();
	if (philo->max_dined_times >= 0)
		philo->dined_times++;
	pthread_mutex_lock(&philo->eating_mutex);
	msg(FORK, philo->num, philo->msg_mutex);
	msg(EAT, philo->num, philo->msg_mutex);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->table->Amutexes[philo->right_fork]);
	pthread_mutex_unlock(&philo->table->Amutexes[philo->left_fork]);
	pthread_mutex_unlock(&philo->eating_mutex);
	return (0);
}

void	*life(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	philo->is_eating = false;
	philo->is_alive = true;
	usleep(10 + philo->odd_wait);
	while (1)
	{
		// usleep(1000000);
		eat(philo);
		mysleep(philo);
		think(philo);
	}
	return (0);
}
