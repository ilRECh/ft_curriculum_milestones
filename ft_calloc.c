#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*void_alloc_mem;
	char	*char_alloc_mem;
	size_t	total_bytes;

	if (nmemb * size > (size_t)0 - 1 || !nmemb || !size)
		return (NULL);
	total_bytes = nmemb * size;
	void_alloc_mem = malloc(total_bytes);
	char_alloc_mem = (char *)void_alloc_mem;
	while (total_bytes--)
		char_alloc_mem[total_bytes] = 0;
	return (void_alloc_mem);
}
