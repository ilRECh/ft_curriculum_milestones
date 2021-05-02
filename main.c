#include <stdio.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	printf("printf:\t%d\n",
		printf("%20.ld et %.4hhi !\n", 0x11ffaa147, (signed char)-8));
	printf("ft_printf:\t%d\n",
		ft_printf("%20.ld et %.4hhi !\n", 0x11ffaa147, (signed char)-8));
	return (0);
}
