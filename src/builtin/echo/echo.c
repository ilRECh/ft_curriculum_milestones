/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:19:46 by name              #+#    #+#             */
/*   Updated: 2021/08/07 18:51:56 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline int	isaln(char *par)
{
	if (par && *par == '-')
		par += 1;
	else
		return (0);
	while (par && *par)
		if (*par++ != 'n')
			return (0);
	return (1);
}

int	ft_echo(char **argv)
{
	uint8_t	flag_nl;

	if (!ft_strncmp(argv[1], "-n", 2) && isaln(argv[1]))
	{
		argv += 1;
		flag_nl = 0;
	}
	else
		flag_nl = 1;
	while (++argv && *(argv + 1))
		write(1, *argv, ft_strlen(*argv)), write(1, " ", 1);
	write(1, *argv, ft_strlen(*argv));
	if (flag_nl)
		write(1, "\n", 1);
	return (0);
}
