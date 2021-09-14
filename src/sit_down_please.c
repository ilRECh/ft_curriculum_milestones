/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_down_please.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:19:03 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/14 22:09:29 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philos_init(t_table *table, uint32_t *array, int32_t is_on_diet)
{
	while (table->i < table->philos)
	{
		table->Aphilos[table->i].num = table->i + 1;
		table->Aphilos[table->i].time_to_die = array[0];
		table->Aphilos[table->i].time_to_eat = array[1];
		table->Aphilos[table->i].time_to_sleep = array[2];
		if (is_on_diet >= 0)
			table->Aphilos[table->i].max_dined_times = is_on_diet;
		else
			table->Aphilos[table->i].max_dined_times = -1;
		table->Aphilos[table->i].dined_times = 0;
		if (table->i % 2)
			table->Aphilos[table->i].odd_wait = 300;
		else
			table->Aphilos[table->i].odd_wait = 0;
		table->Aphilos[table->i].left_fork = table->i;
		table->Aphilos[table->i].right_fork = table->i + 1;
		table->Aphilos[table->i].table = table;
		table->i++;
	}
	if (table->philos > 1)
		table->Aphilos[table->i - 1].right_fork = 0;
	table->i = 0;
}

static void	mutexes_init(t_table *table)
{
	table->i = 0;
	while (table->i < table->philos)
	{
		pthread_mutex_init(table->Amutexes + table->i, NULL);
		table->i++;
	}
}

static int32_t	threads_init(t_table *table)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * table->philos);
	if (!threads)
		return (1);
	table->i = 0;
	while (table->i < table->philos)
	{
		pthread_create(threads + table->i, NULL, life,
			table->Aphilos + table->i);
		table->i++;
	}
	table->i = 0;
	while (table->i < table->philos)
	{
		pthread_join(threads[table->i], NULL);
		table->i++;
	}
	free(threads);
	return (0);
}

int32_t	sit_down_please(uint32_t *array, int32_t size)
{
	t_table			table;

	table.Amutexes = malloc(sizeof(pthread_mutex_t)
			* (array[0] == 1) * 2 + (array[0] != 1) * array[0]);
	if (!table.Amutexes)
		return (1);
	table.philos = array[0];
	table.Aphilos = malloc(sizeof(t_philosopher) * array[0]);
	if (!table.Aphilos)
		return (1);
	mutexes_init(&table);
	if (size == 5)
		table.is_on_diet = array[4];
	else
		table.is_on_diet = -1;
	table.i = 0;
	philos_init(&table, array + 1, table.is_on_diet);
	if (threads_init(&table))
		return (1);
	// free_all(table);
	return (0);
}
