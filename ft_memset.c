/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:26:53 by vcobbler          #+#    #+#             */
/*   Updated: 2021/04/16 15:29:27 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char value;

	ptr = (unsigned char *)b;
	value = (unsigned char)c;
	while (len--)
		*ptr++ = c;
	return (b);
}
