/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:04:25 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:04:28 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int n, char c))
{
	char	*result;
	size_t	iter_1;

	if (!s || !f)
		return (NULL);
	result = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	iter_1 = -1;
	while (s[++iter_1])
		result[iter_1] = (*f)(iter_1, s[iter_1]);
	return (result);
}		
