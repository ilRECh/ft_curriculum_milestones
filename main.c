#include <stdio.h>
#include <unistd.h>
#include "includes/ft_stdio.h"
#include "out_funcs.h"

void in_bin(uint64_t d, unsigned int n)
{
	static int m;

	printf("%d ", ++m);
	printf("the num in binary is:\t\t");
	while (n--)
		printf("%lu", (d >> n) & 1);
	printf("\n");
}

#include <float.h>

const double lowest_double = DBL_MIN;

int	main(void)
{
	t_double nbr;

	double n;

	n = 3.9999999;
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%f\n", n));
	printf("ft_printf:\t%d - %%f, n = 3.9999999\n",
		   ft_printf("%f\n", n));
	return (0);
}
