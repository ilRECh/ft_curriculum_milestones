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

int	main(void)
{
	t_double nbr;

	double n;

	n = 573.924;
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%e\n", n));
	printf("ft_printf:\t%d - %%e\n",
		   ft_printf("%e\n", n));
	return (0);
}
