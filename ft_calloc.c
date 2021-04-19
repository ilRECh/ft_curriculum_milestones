#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc_mem;
	size_t	total_bytes;

	if (nmemb * size > (size_t)0 - 1 || !nmemb || !size)
		return (NULL);
	total_bytes = nmemb * size;
	alloc_mem = malloc(total_bytes);
	ft_bzero(alloc_mem, total_bytes);
	return (alloc_mem);
}
