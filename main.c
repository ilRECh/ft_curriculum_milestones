#include <stdio.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	printf("printf out symbs: %d;\n\n",
		printf("%.s\n", "hi"));

	printf("ft_printf out symbs: %d;\n",
		ft_printf("%.s\n", "hi"));
	return (0);
}
