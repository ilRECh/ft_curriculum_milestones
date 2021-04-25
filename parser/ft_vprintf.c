#include "parser.h"
#include "libft.h"

int	ft_vprintf(char *format, va_list vl)
{
	int	total;

	total = 0;
	while (*format)
	{
		if (*format == SPECIFIER_SIGN)
			format = parse_specifier(format + 1, vl, &total);
		else
		{
			write(1, format, 1);
			total++;
			format++;
		}
	}
	return (total);
}
