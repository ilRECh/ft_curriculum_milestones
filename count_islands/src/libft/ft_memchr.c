/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:08:20 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:08:21 by name             ###   ########.fr       */
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
