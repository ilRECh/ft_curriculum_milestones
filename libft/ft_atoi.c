/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:59:06 by name              #+#    #+#             */
/*   Updated: 2021/08/05 23:59:07 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	result;
	int				digits_countdown;
	int				minus_sign;

	result = 0;
	minus_sign = 1;
	digits_countdown = 19;
	while (ft_isspace(*nptr) || *nptr == '0')
		nptr++;
	if (*nptr == '-')
	{
		minus_sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		if (!digits_countdown-- && ft_isdigit(*(nptr)))
			return ((1 + minus_sign) / (-2));
		result = result * 10 + (*nptr++ - '0');
	}
	return (result * minus_sign);
}
