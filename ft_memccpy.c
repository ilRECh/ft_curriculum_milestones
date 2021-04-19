/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:47:31 by vcobbler          #+#    #+#             */
/*   Updated: 2021/04/16 17:27:46 by vcobbler         ###   ########.fr       */
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
