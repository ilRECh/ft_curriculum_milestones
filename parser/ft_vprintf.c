#include "parser.h"
#include "libft.h"

int	ft_vprintf(char *format, va_list vl)
{
	int	total;

	total = 0;
	while (*format)
	{
		total++;
		if (*format == SPECIFIER)
		{
			format += parse_specifier(format + 1, vl);
		}
		write(1, format, 1);
		format++;
	}
	return (total);
}
