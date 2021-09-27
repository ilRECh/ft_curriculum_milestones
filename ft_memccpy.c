/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:08:12 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:08:14 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		character;
	unsigned char		*destination;
	const unsigned char	*source = (unsigned char *)src;

	character = (unsigned char)c;
	destination = (unsigned char *)dst;
	while (n--)
	{
		*destination = *source++;
		if (*destination++ == character)
			return (destination);
	}
	return (NULL);
}
