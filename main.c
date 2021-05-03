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
	double n;
	double m;
	int l;

	n = 3.1415;
	l = (int)n;
	m = n - (double)l;
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		printf("%f | %i | %f\n", n, l, m));
	printf("ft_printf:\t%d\n",
		ft_printf("%f | %i | %f\n", n, l, m));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%0.6f\n", n));
	printf("ft_printf:\t%d - %%0.6f\n",
		   ft_printf("%0.6f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%6.0f\n", n));
	printf("ft_printf:\t%d - %%6.0f\n",
		   ft_printf("%6.0f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%6.6f\n", n));
	printf("ft_printf:\t%d - %%6.6f\n",
		   ft_printf("%6.6f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("% .3f\n", n));
	printf("ft_printf:\t%d - %% .3f\n",
		   ft_printf("% .3f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%0.0f\n", n));
	printf("ft_printf:\t%d - %%0.0f\n",
		   ft_printf("%0.0f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%0 20.3f\n", n));
	printf("ft_printf:\t%d - %%0 20.3f\n",
		   ft_printf("%0 20.3f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%.20f\n", n));
	printf("ft_printf:\t%d - %%.40f\n",
		   ft_printf("%.20f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("% .1f\n", n));
	printf("ft_printf:\t%d - %% .1f\n",
		   ft_printf("% .1f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%+.0f\n", 0.f));
	printf("ft_printf:\t%d - %%+.0f\n",
		   ft_printf("%+.0f\n", 0.f));
	printf("printf:\t%d\n",
		   printf("%0 20.3f\n", n * (-1)));
	printf("ft_printf:\t%d - %%0 20.3f\n",
		   ft_printf("%0 20.3f\n", n * (-1)));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("% 40.0f\n", n));
	printf("ft_printf:\t%d - %% 40.0f\n",
		   ft_printf("% 40.0f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("% .1f\n", n * (-1)));
	printf("ft_printf:\t%d - %% .1f\n",
		   ft_printf("% .1f\n", n * (-1)));
	n = 3.1415 / 0;
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%010.0f\n", n));
	printf("ft_printf:\t%d - %%010.0f, n = inf\n",
		   ft_printf("%010.0f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("% f\n", n));
	printf("ft_printf:\t%d - %%010.0f, n = inf\n",
		   ft_printf("% f\n", n));
	return (0);
}
//1100000010000011000100100110111111000000100000110001001001101111
//1100000010000011000100100110111111000000100000110001001001101111