#include <stdio.h>
#include "includes/ft_stdio.h"

int	main(void)
{
	char	*ptr;

	ptr = 9751953785;
	printf("printf out symbs: %d;\n\n",
		printf("%0100p\n", ptr));

	printf("ft_printf out symbs: %d;\n",
		ft_printf("%23p\n", ptr));
	return (0);
}
