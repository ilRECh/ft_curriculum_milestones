#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	character;

	source = (unsigned char *)s;
	character = (unsigned char)c;
	while (n--)
	{
		if (*source == character)
			return (source);
		source++;
	}
	return (NULL);
}
