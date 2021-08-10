/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:59:09 by name              #+#    #+#             */
/*   Updated: 2021/08/05 23:59:11 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_bin_search(int *arr, size_t left, size_t right, int to_find)
{
	size_t	middle;

	if (right >= left)
	{
		middle = left + (right - left) / 2;
		if (to_find > arr[middle])
			return (ft_bin_search(arr, middle + 1, right, to_find));
		else if (to_find < arr[middle])
			return (ft_bin_search(arr, left, middle - 1, to_find));
		return (middle);
	}
	return (-1);
}
