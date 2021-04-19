#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	source_len;

	source_len = ft_strlen(src);
	if (dst_size)
	{
		dst_size--;
		while (dst_size-- && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (source_len);
}
