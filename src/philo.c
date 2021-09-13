/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:38:18 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/13 20:51:31 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argc--)
	{
		while (argv[argc][i])
		{
			if (!('0' <= argv[argc][i] && argv[argc][i] <= '9')
				&& argv[argc][i] != '+')
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	result;
	int				digits_countdown;

	result = 0;
	digits_countdown = 19;
	while (*nptr == ' ' || (*nptr >= 8 && *nptr <= 12) || *nptr == '0')
		nptr++;
	if (*nptr == '+')
		nptr++;
	while ('0' <= *nptr && *nptr <= '9')
	{
		if (!digits_countdown-- && ('0' <= *nptr && *nptr <= '9'))
			return (-1);
		result = result * 10 + (*nptr++ - '0');
	}
	return (result);
}

typedef struct s_init
{
	int			*array;
	int			size;
	int			i;
	int (*const	get_int)(char const *);
}	t_init;

int	philo(int argc, char **argv)
{
	static t_init	args = {NULL, 0, 0, ft_atoi};

	if (parse(argc, argv))
		return (1);
	args.array = malloc(sizeof(int) * (args.size = argc));
	if (!args.array)
		return (1);
	while (args.i < args.size)
		args.array[args.i++] = args.get_int(*argv++);
	//sit_down_please(args.array, args.size);
	return (0);
}