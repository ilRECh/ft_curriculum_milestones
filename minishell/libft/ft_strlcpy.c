/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:04:19 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:04:20 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	source_len;

	if (!dst && !src)
		return (0);
	source_len = ft_strlen(src);
	if (dst_size)
	{
		dst_size--;
		while (dst_size-- && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (source_len);
}
