/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:59:56 by name              #+#    #+#             */
/*   Updated: 2021/08/05 23:59:58 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	n_size;
	char	minus_sign;
	int		n_copy;
	char	*result;

	n_size = 1;
	n_copy = n;
	minus_sign = 0;
	if (n < 0)
		minus_sign = 1;
	while ((n_copy > 9 || n_copy < -9) && n_copy)
	{
		n_copy /= 10;
		n_size++;
	}
	result = (char *)ft_calloc(n_size + minus_sign + 1, sizeof(char));
	if (minus_sign && result)
		result[0] = '-';
	while (n_size-- && result)
	{
		result[minus_sign + n_size] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (result);
}
