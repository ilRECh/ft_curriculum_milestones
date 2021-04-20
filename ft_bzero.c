#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;

	string = (unsigned char *)s;
	while (n--)
		string[n] = 0;
}
