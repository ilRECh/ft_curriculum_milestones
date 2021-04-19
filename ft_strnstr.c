#include "libft.h"

static char	substr_check(const char *big, const char *little, size_t len)
{
	while (*little)
		if ((*big++ - *little++) || (len-- == 0 && *little))
			return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!big || !little || *little == 0)
		return ((char *)big);
	while (*big && len--)
	{
		if (*big == *little && substr_check(big, little, len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
