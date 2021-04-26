#include <stdio.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	printf("printf out symbs: %d;\n",
		printf("a %10c\n", 'a'));

	printf("ft_printf out symbs: %d;\n",
		ft_printf("a %10c\n", 'a'));
	return (0);
}
