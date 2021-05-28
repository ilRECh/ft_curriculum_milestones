#ifndef TYPE_INT_H
# define TYPE_INT_H

# include <stdlib.h>
# include <unistd.h>

static int	int_compare(void *A_array,
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

static int	int_assign(void *A_array,
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