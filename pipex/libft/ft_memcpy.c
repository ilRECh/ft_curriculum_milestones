#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source = (unsigned char *)src;

	if (!dst && !src)
		return (NULL);
	destination = (unsigned char *)dst;
	while (n--)
		destination[n] = source[n];
	return (dst);
}
