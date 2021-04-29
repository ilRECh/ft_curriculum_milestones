#include <stdio.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	char	*ptr;

	ptr = 235453457934;
	printf("POINTER PRINT-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		printf("%10.5p\n", ptr));

	printf("ft_printf out symbs: %d;\n",
		ft_printf("%10.5p\n", ptr));
	printf("-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%5.10p\n", ptr));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%5.10p\n", ptr));
	printf("-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%010.5p\n", ptr));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%010.5p\n", ptr));
	printf("-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%-10.5p\n", ptr));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%-10.5p\n", ptr));
	printf("-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%05.10p\n", ptr));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%05.10p\n", ptr));
	printf("-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%5p\n", ptr));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%5p\n", ptr));
	printf("-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%05p\n", ptr));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%05p\n", ptr));
	printf("\n\nDIGIT PRINT-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%.4d\n", 100));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%.4d\n", 100));
	printf("\n\n-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%10.4d\n", 100));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%10.4d\n", 100));
	printf("\n\n-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%010.4i\n", -100));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%010.4i\n", -100));
	printf("\n\n-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%0 4.10i\n", -100));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%0 4.10i\n", -100));
	printf("\n\n-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%08i\n", -72));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%08i\n", -72));
	printf("\n\n-------------------------------------------\n");
	printf("printf out symbs: %d;\n\n",
		   printf("%.0i\n", 0));

	printf("ft_printf out symbs: %d;\n",
		   ft_printf("%.0i\n", 0));
	return (0);
}
