#include <stdio.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	printf("printf:\t%d\n",
		printf("%--2.4s!\n",NULL));
	printf("ft_printf:\t%d\n",
		ft_printf("%--2.4s!\n",NULL));
	return (0);
}
