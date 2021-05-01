#include <stdio.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	printf("printf:\t%d\n", printf("(null)\n", (char)0));
	printf("ft_printf:\t%d\n", ft_printf("(null)\n"), (char)0);
	return (0);
}
