/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:09:06 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:09:09 by name             ###   ########.fr       */
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
