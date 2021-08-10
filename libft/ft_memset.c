/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:03:12 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:03:14 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;
	unsigned char	value;

	string = (unsigned char *)b;
	value = (unsigned char)c;
	while (len--)
		*string++ = value;
	return (b);
}
