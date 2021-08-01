#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	destination = (unsigned char *)dest;
	source = (unsigned char *) src;
	if (destination < source)
		while (n--)
			*(destination++) = *(source++);
	else
	{
		destination += n;
		source += n;
		while (n--)
			*--destination = *--source;
	}
	return (dest);
}
