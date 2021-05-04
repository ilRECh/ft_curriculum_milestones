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

	n = 7523974.58347 / 0;
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%0.6f\n", n));
	printf("ft_printf:\t%d - %%0.6f\n",
		   ft_printf("%0.6f\n", n));
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
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%-10f\n", n));
	printf("ft_printf:\t%d - %%-10f, n = inf\n",
		   ft_printf("%-10f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%e\n", n));
	printf("ft_printf:\t%d - %%e, n = inf\n",
		   ft_printf("%e\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%10e\n", n));
	printf("ft_printf:\t%d - %%10e, n = inf\n",
		   ft_printf("%10e\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%-40.10e\n", n));
	printf("ft_printf:\t%d - %%-40.10e, n = inf\n",
		   ft_printf("%-40.10e\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%-13e\n", n));
	printf("ft_printf:\t%d - %%.2e, n = inf\n",
		   ft_printf("%-13e\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%g\n", n));
	printf("ft_printf:\t%d - %%g, n = inf\n",
		   ft_printf("%g\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%.8g\n", n));
	printf("ft_printf:\t%d - %%.8g, n = inf\n",
		   ft_printf("%.8g\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%.15g\n", n));
	printf("ft_printf:\t%d - %%.15g, n = inf\n",
		   ft_printf("%.15g\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%+- 07.06s\n", "hi low"));
	printf("ft_printf:\t%d - %%+- 07.06s, n = inf\n",
		   ft_printf("%+- 07.06s\n", "hi low"));
	printf("------------------------------------------\n");
	printf("%hh", 82);
	printf("printf:\t%d\n",
		   printf("%hh"));
	printf("ft_printf:\t%d - %%hh\n",
		   ft_printf("%hh"));
	return (0);
}
