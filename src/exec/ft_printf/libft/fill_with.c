#include "libft.h"

void	fill_with(char c, unsigned int amount)
{
	while (amount--)
		write(1, &c, 1);
}
