#include "libft.h"

char	*ft_itoa(int n)
{
	char	n_size;
	char	minus_sign;
	int	n_copy;
	char	*result;

	n_size = 1;
	n_copy = n;
	minus_sign = 0;
	if (n < 0)
		minus_sign = 1;
	while ((n_copy > 9 || n_copy < -9) && (n_copy /= 10))
		n_size++;
	result = (char *)ft_calloc(n_size + minus_sign + 1, sizeof(char));
	if (minus_sign)
		result[0] = '-';
	while (n_size--)
	{
		result[minus_sign + n_size] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (result);
}
