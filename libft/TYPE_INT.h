/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TYPE_INT.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:05:21 by name              #+#    #+#             */
/*   Updated: 2021/08/06 00:05:23 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_INT_H
# define TYPE_INT_H

# include <stdlib.h>
# include <unistd.h>

static int	INT_COMPARE(void *A_array,
					   void *B_array, size_t offset_A, size_t offset_B)
{
	int	*A;
	int	*B;

	if (!A_array || !B_array)
		return (write(1, "NULL ARRAY!", 11));
	A = (int *)A_array;
	B = (int *)B_array;
	return (A[offset_A] - B[offset_B]);
}

static int	INT_ASSIGN(void *A_array,
					  void *B_array, size_t offset_A, size_t offset_B)
{
	int	*A;
	int	*B;

	if (!A_array || !B_array)
		return (write(1, "NULL ARRAY!", 11));
	A = (int *)A_array;
	B = (int *)B_array;
	A[offset_A] = B[offset_B];
	return (1);
}

#endif