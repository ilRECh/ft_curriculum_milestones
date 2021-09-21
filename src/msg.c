/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:04:49 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/17 19:23:50 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int32_t	msg(uint32_t type, uint32_t num, t_mutex *mute)
{
	const char	*msgs[] = {
		"has taken a fork",
		GREEN "is eating" RESET,
		"is sleeping",
		"is thinking",
		RED "died" RESET
	};
	static bool	is_typing = true;

	pthread_mutex_lock(mute);
	if (!is_typing)
		return (1);
	if (type == DIED)
		is_typing = false;
	printf("%lu %d %s\n", get_time(), num, msgs[type]);
	pthread_mutex_unlock(mute);
	return (0);
}
