/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:22:21 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:22:23 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	substr_check(const char *big, const char *little, size_t len)
{
	while (*little)
		if ((*big++ - *little++) || (len-- == 0 && *little))
			return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == 0)
		return ((char *)big);
	while (*big && len--)
	{
		if (*big == *little && substr_check(big, little, len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
