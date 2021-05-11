#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
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
	printf("printf:\t%d\n",
		printf("%5.0i", 0));
	printf("ft_printf:\t%d\n",
		ft_printf("%5.0i", 0));
	return (0);
}
