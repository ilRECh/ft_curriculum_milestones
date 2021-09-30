/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:22:42 by name              #+#    #+#             */
/*   Updated: 2021/09/27 10:22:44 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_size;
	char	*dst;

	if (!s)
		return (NULL);
	if (s + ft_strlen(s) < s + start)
		return (ft_strdup(s + ft_strlen(s)));
	substr_size = ft_strlen(s + start);
	if (len < substr_size)
		substr_size = len;
	dst = ft_strndup(s + start, substr_size);
	return (dst);
}
