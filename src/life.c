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

static int	mysleep(t_philosopher *philo)
{
	if (msg(SLEEP, philo, philo->msg_mutex))
		return (1);
	// usleep(philo->time_to_sleep * 1000);
	myusleep(philo->time_to_sleep);
	return (0);
}

static int	eat(t_philosopher *philo)
{
	if (philo->table->philos < 2)
		return (1);
	pthread_mutex_lock(philo->right_fork);
	if (msg(FORK, philo, philo->msg_mutex))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->eating_mutex);
	if (msg(FORK, philo, philo->msg_mutex))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->eating_mutex);
		return (1);
	}
	philo->dined_last_time = get_time();
	philo->dined_times++;
	if (msg(EAT, philo, philo->msg_mutex))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->eating_mutex);
		return (1);
	}
	myusleep(philo->time_to_eat - 10);
	//usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->eating_mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (philo->max_dined_times >= 0
		&& philo->dined_times == philo->max_dined_times)
		return (1);
	return (0);
}

void	*life(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	philo->is_eating = false;
	philo->is_alive = true;
	while (1)
	{
		if (philo->max_dined_times >= 0
			&& philo->dined_times == philo->max_dined_times)
			break ;
		if (!philo->is_alive)
			break ;
		if (eat(philo))
			break ;
		if (mysleep(philo))
			break ;
		if (msg(THINK, philo, philo->msg_mutex))
			break ;
	}
	return (NULL);
}
