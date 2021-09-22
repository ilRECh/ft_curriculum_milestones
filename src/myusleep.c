/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myusleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:00:48 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/22 19:00:49 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myusleep(uint64_t tm)
{
	const uint64_t	curtm = get_time();

	while (get_time() - curtm < tm)
		usleep(1);
}
