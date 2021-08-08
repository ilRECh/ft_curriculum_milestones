/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:04:04 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:04:05 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	if (!s)
		return (NULL);
	character = (unsigned char)c;
	while (*s != character && *s)
		s++;
	if (*s != character)
		return (NULL);
	return ((char *)s);
}
