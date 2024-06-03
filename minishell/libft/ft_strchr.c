/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:01:50 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/31 19:01:50 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	if (!s || !c)
		return (NULL);
	character = (unsigned char)c;
	while (*s != character && *s)
		s++;
	if (*s != character)
		return (NULL);
	return ((char *)s);
}
