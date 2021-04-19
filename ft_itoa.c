#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	n_size;
	int	n_copy;

	n_size = 1;
	n_copy = n;
	while ((n_copy > 10 || n_copy < -10) && (n_copy /= 10))
		n_size++;
	printf("size is:\t%d", n_size);
	exit(1);
}

int	main(void)
{
	ft_itoa(-9238749);
	return(0);
}
