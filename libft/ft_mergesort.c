/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:03:16 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:03:17 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sort_conf.h"

static void	Merge(int *A, t_index index, int *B, t_function function)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = index.First;
	j = index.Middle;
	k = index.First;
	while (k < index.Last)
	{
		if (i < index.Middle && (j >= index.Last
				|| function.compare(A, A, i, j) <= 0))
			function.assign(B, A, k, i++);
		else
			function.assign(B, A, k, j++);
		k++;
	}
}

static void	SplitMerge(void *B, t_index index, void *A, t_function function)
{
	t_index	Left;
	t_index	Right;

	if (index.Last - index.First <= 1)
		return ;
	index.Middle = (index.Last + index.First) / 2;
	Left.First = index.First;
	Left.Last = index.Middle;
	Right.First = index.Middle;
	Right.Last = index.Last;
	SplitMerge(A, Left, B, function);
	SplitMerge(A, Right, B, function);
	Merge(B, index, A, function);
}

void	ft_mergesort(void *to_sort, size_t len, t_DATA_TYPE type)
{
	size_t		i;
	t_index		index;
	void		*B;
	t_function	function;

	i = -1;
	B = (int *)malloc((type % 10) * len);
	if ((!B || function_by_data_type(&function, type))
		&& write(1, "MERGESORT FAIL!", 15))
		return ;
	while (++i < len)
		function.assign(B, to_sort, i, i);
	index.First = 0;
	index.Last = len;
	SplitMerge(B, index, to_sort, function);
	free(B);
}
