/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:04:42 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:04:44 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*start;
	unsigned char	character;

	if (!s)
		return (NULL);
	character = (unsigned char)c;
	start = s;
	s += ft_strlen(s);
	while (*s != character && s != start)
		s--;
	if (*s != character)
		return (NULL);
	return ((char *)s);
}
