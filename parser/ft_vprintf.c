#include "parser.h"
#include "libft.h"

//parse_specifier pasrses specifier, outputs formated arg, returns the end of the specifier

int	ft_vprintf(char *format, va_list vl)
{
	while (*format)
	{
		if (*format == SPECIFIER)
		{
			format += parse_specifier(format, vl);
		}
		ft_putchar_fd(*format, 1);
		format++;
	}
}
