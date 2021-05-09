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

	n = 0.00000000742937492374927349273947239749274923749723948;
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%.100e\n", n));
	printf("ft_printf:\t%d - %%f\n",
		   ft_printf("%e\n", n));
	return (0);
}
