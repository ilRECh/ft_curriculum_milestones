/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:33:31 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/13 20:37:22 by vcobbler         ###   ########.fr       */
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

int		philo(int argc, char **argv);

#endif
