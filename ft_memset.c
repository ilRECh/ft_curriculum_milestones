#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;
	unsigned char	value;

	string = (unsigned char *)b;
	value = (unsigned char)c;
	while (len--)
		string[len] = value;
	return (b);
}
