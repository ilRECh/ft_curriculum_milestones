/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:33:31 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/15 20:04:43 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->Amutexes[philo->right_fork]);
	//printf("%ld %s has taken a fork\n", get_time(), philo->num);
	uleep( 20);
	if (pthread_mutex_lock(&philo->table->Amutexes[philo->left_fork]) == EBUSY)
	{ 	
		uleep(20);
		pthread_mutex_unlock(&philo->table->Amutexes[philo->right_fork]);
		printf("%s: oh, I am so sorry!\n", philosopher->name);
	}
	printf("%s is eating\n", philosopher->name);
	pthread_mutex_unlock(&table->forks[philosopher->right_fork]);
	pthread_mutex_unlock(&table->forks[philosopher->left_fork]);
	printf("%s finished dinner\n", philosopher->name);
	return (0);
}

static int	sleep(t_philosopher *philo)
{

	return (0);
}

static int	think(t_philosopher *philo)
{

	return (0);
}

void	*life(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	usleep(10 + philo->odd_wait);
	printf("Hello! I am philo %d\n", philo->num);
	return (0);
}
