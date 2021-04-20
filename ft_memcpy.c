/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:09:11 by vcobbler          #+#    #+#             */
/*   Updated: 2021/04/20 16:18:38 by vcobbler         ###   ########.fr       */
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
		*destination++ = *source++;
	return (dst);
}
