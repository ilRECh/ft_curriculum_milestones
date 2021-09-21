/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:33:31 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/17 20:22:29 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdint.h>
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
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIED 4

typedef struct s_table		t_table;
typedef struct s_watchdog	t_watchdog;
typedef pthread_mutex_t		t_mutex;
typedef struct s_philosopher
{
	pthread_t	life_th;
	uint32_t	num;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint32_t	dined_times;
	int32_t		max_dined_times;
	uint64_t	dined_last_time;
	t_mutex		eating_mutex;
	t_mutex		*msg_mutex;
	bool		is_eating;
	bool		is_alive;
	uint64_t	odd_wait;
	uint64_t	time_life_start;
	uint32_t	left_fork;
	uint32_t	right_fork;
	t_table		*table;
}	t_philosopher;

typedef struct s_watchdog
{
	t_mutex			*eating_mutex;
	t_mutex			*msg_mutex;
	pthread_t		watch_th;
	t_philosopher	*philo;
}	t_watchdog;

typedef struct s_table
{
	pthread_mutex_t		*Amutexes;
	t_philosopher		*Aphilos;
	t_watchdog			*Awatchdogs;
	uint32_t			philos;
	uint32_t			i;
	int32_t				is_on_diet;
	t_mutex				msg_mutex;
}	t_table;

int32_t		philo(int32_t argc, char **argv);
int32_t		sit_down_please(uint32_t *array, int32_t size);
void		*life(void *arg);
int32_t		msg(uint32_t type, uint32_t num, t_mutex *mute);
void		*I_SEE_YOU(void *arg);
uint64_t	get_time(void);

#endif
