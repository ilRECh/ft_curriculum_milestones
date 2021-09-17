/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:54:09 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/17 19:23:08 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval			time;
	static bool				init;
	static struct timeval	start_time;

	if (!init)
		gettimeofday(&start_time, NULL), init = true;
	gettimeofday(&time, NULL);
	return ((uint64_t)(time.tv_sec * 1000 + time.tv_usec / 1000)
		- (uint64_t)(start_time.tv_sec * 1000 + start_time.tv_usec / 1000));
}
