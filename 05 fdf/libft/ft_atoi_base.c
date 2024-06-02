#include "libft.h"

int	ft_atoi_base(const char *nptr, uint8_t base)
{
	char		*lower;
	const char	*nptr_end;
	int			result;
	int			iter_1;

	if (!nptr || !(base >= 2 && base <= 16))
		return (0);
	if (*(nptr + 1) == 'b' || *(nptr + 1) == 'x'
		|| *(nptr + 1) == 'X')
		nptr += 2;
	nptr_end = nptr + ft_strlen(nptr);
	result = 0;
	iter_1 = 0;
	lower = "0123456789abcdef";
	while (TRUE)
	{
		nptr_end -= 1;
		result += (ft_strchr(lower, ft_tolower(*nptr_end)) - lower)
			* ft_pow(base, iter_1++);
		if (nptr_end == nptr)
			break ;
	}
	return (result);
}
