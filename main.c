#include <stdio.h>
#include <unistd.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	float n;
	float m;
	int l;

	n = 3.1415f;
	l = (int)n;
	m = n - (float)l;
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		printf("%f | %i | %f\n", n, l, m));
	printf("ft_printf:\t%d\n",
		ft_printf("%f | %i | %f\n", n, l, m));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%0.6f\n", n));
	printf("ft_printf:\t%d\n",
		   ft_printf("%f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%6.0f\n", n));
	printf("ft_printf:\t%d\n",
		   ft_printf("%f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%6.6f\n", n));
	printf("ft_printf:\t%d\n",
		   ft_printf("%f\n", n));
	printf("------------------------------------------\n");
	printf("printf:\t%d\n",
		   printf("%#f\n", n));
	printf("ft_printf:\t%d\n\n\n\n\n",
		   ft_printf("%10.0f\n", n));


	double b = 0.45234523451234125;
	printf("------------------------------------------\n");
	printf("%.10g\n", b);
	write(1,"0.",2);
	int j = -1;
	char c;
	while (++j < 10)
	{
		c = (char)(b * 10) + '0';
		write(1, &c, 1);
		b = b * 10 - (double)((int)(b * 10));
	}
	return (0);
}
