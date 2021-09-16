/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:36:42 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/16 19:48:36 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*I_SEE_YOU(void *arg)
{
	t_philosopher	*philo;

	philo = arg;
	if (philo->is_alive)
		printf("he is alive!\n");
	while(1);
	return (NULL);
}