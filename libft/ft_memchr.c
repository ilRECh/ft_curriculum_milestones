/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:00:55 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:01:00 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	character;

	source = (unsigned char *)s;
	character = (unsigned char)c;
	while (n--)
	{
		if (*source == character)
			return (source);
		source++;
	}
	return (NULL);
}
