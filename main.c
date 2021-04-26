#include <stdio.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	printf("printf out symbs: %d;\n",
		printf("%.1s\n", NULL));

	printf("ft_printf out symbs: %d;\n",
		ft_printf("%.1s\n", NULL));
	return (0);
}
