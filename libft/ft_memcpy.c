/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:03:01 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:03:06 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source = (unsigned char *)src;

	if (!dst && !src)
		return (NULL);
	destination = (unsigned char *)dst;
	while (n--)
		destination[n] = source[n];
	return (dst);
}
