/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:04:08 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:04:09 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	s_size;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * s_size + 1);
	if (!dst)
		return (NULL);
	dst[s_size] = 0;
	while (*s)
		*dst++ = *s++;
	return (dst - s_size);
}
