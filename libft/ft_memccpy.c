#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		character;
	unsigned char		*destination;
	const unsigned char	*source = (unsigned char *)src;

	character = (unsigned char)c;
	destination = (unsigned char *)dst;
	while (n--)
	{
		*destination = *source++;
		if (*destination++ == character)
			return (destination);
	}
	return (NULL);
}
