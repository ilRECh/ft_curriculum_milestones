/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:33:31 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/15 20:02:20 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define BLACK_BOLD "\033[0;30;1m"
# define RED_BOLD "\033[0;31;1m"
# define GREEN_BOLD "\033[0;32;1m"
# define YELLOW_BOLD "\033[0;33;1m"
# define BLUE_BOLD "\033[0;34;1m"
# define MAGENTA_BOLD "\033[0;35;1m"
# define CYAN_BOLD "\033[0;36;1m"

typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mutex;
typedef struct s_philosopherq
{
	uint32_t	num;
	uint32_t	time_to_die;
	uint32_t	time_to_eat;
	uint32_t	time_to_sleep;
	uint32_t	dined_times;
	int32_t		max_dined_times;
	uint32_t	dined_last_time;
	t_mutex		eating_mutex;
	bool		is_eating;
	bool		is_alive;
	int32_t		odd_wait;
	uint32_t	left_fork;
	uint32_t	right_fork;
	t_table		*table;
}	t_philosopher;

typedef struct s_table
{
	pthread_mutex_t		*Amutexes;
	t_philosopher		*Aphilos;
	uint32_t			philos;
	uint32_t			i;
	int32_t				is_on_diet;
}	t_table;

int32_t	philo(int32_t argc, char **argv);
int32_t	sit_down_please(uint32_t *array, int32_t size);
void	*life(void *arg);

#endif
