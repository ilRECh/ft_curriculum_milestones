/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_down_please.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:19:03 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/17 20:23:48 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philos_init(t_table *table, uint32_t *array, int32_t is_on_diet)
{
	while (++table->i < table->philos)
	{

		table->Aphilos[table->i].msg_mutex = &table->msg_mutex;
		table->Aphilos[table->i].eating_mutex = malloc(sizeof(t_mutex));
		if (!table->Aphilos[table->i].eating_mutex)
			return ;
		pthread_mutex_init(table->Aphilos[table->i].eating_mutex, NULL);
		table->Aphilos[table->i].num = table->i + 1;
		table->Aphilos[table->i].time_to_die = array[0];
		table->Aphilos[table->i].time_to_eat = array[1];
		table->Aphilos[table->i].time_to_sleep = array[2];
		if (is_on_diet >= 0)
			table->Aphilos[table->i].max_dined_times = is_on_diet;
		else
			table->Aphilos[table->i].max_dined_times = -1;
		table->Aphilos[table->i].dined_times = 0;
		table->Aphilos[table->i].dined_last_time = 0;
		table->Aphilos[table->i].left_fork = table->Amutexes + table->i;
		table->Aphilos[table->i].right_fork = table->Amutexes + table->i + 1;
		table->Aphilos[table->i].table = table;
	}
	if (table->philos > 1)
		table->Aphilos[table->i - 1].right_fork = table->Amutexes;
	else
		table->Aphilos[table->i - 1].right_fork = NULL;
}

static void	mutexes_init(t_table *table)
{
	table->i = -1;
	while (++table->i < table->philos)
		pthread_mutex_init(table->Amutexes + table->i, NULL);
	pthread_mutex_init(&table->msg_mutex, NULL);
}

static int32_t	threads_init(t_table *table)
{
	table->i = 0;
	while (table->i < table->philos)
	{
		if (pthread_create(&table->Aphilos[table->i].life_th,
				NULL, life, table->Aphilos + table->i))
			return (1);
		if (pthread_create(&table->Awatchdogs[table->i].watch_th,
				NULL, I_SEE_YOU, table->Awatchdogs + table->i))
			return (1);
		table->i += 2;
		usleep(300);
	}
	myusleep(1);
	table->i = 1;
	while (table->philos > 1 && table->i < table->philos)
	{
		if (pthread_create(&table->Aphilos[table->i].life_th,
				NULL, life, table->Aphilos + table->i))
			return (1);
		if (pthread_create(&table->Awatchdogs[table->i].watch_th,
				NULL, I_SEE_YOU, table->Awatchdogs + table->i))
			return (1);
		table->i += 2;
		usleep(300);
	}
	table->i = -1;
	while (++table->i < table->philos)
	{
		if (pthread_join(table->Aphilos[table->i].life_th, NULL))
			return (1);
		if (pthread_join(table->Awatchdogs[table->i].watch_th, NULL))
			return (1);
	}
	return (0);
}

static void	watchdogs_init(t_table *table)
{
	table->i = -1;
	while (++table->i < table->philos)
	{
		table->Awatchdogs[table->i].philo = table->Aphilos + table->i;
		table->Awatchdogs[table->i].eating_mutex
			= table->Aphilos[table->i].eating_mutex;
		table->Awatchdogs[table->i].msg_mutex
			= &table->msg_mutex;
	}
}

int32_t	sit_down_please(uint32_t *array, int32_t size)
{
	t_table	table;

	table.Amutexes = malloc(sizeof(t_mutex) * array[0]);
	if (!table.Amutexes)
		return (1);
	table.philos = array[0];
	table.Aphilos = malloc(sizeof(t_philosopher) * array[0]);
	table.Awatchdogs = malloc(sizeof(t_watchdog) * array[0]);
	if (!table.Aphilos || !table.Awatchdogs)
		return (1);
	mutexes_init(&table);
	if (size == 5)
		table.is_on_diet = array[4];
	else
		table.is_on_diet = -1;
	table.i = -1;
	philos_init(&table, array + 1, table.is_on_diet);
	watchdogs_init(&table);
	if (threads_init(&table))
		return (1);
	// free_all(table);
	return (0);
}
