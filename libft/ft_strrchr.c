/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:22:31 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:22:33 by name             ###   ########.fr       */
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
