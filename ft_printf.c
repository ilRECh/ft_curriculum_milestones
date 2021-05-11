#include "parser.h"

int	ft_printf(char const *format, ...)
{
	va_list	vl;
	int		total;

	va_start(vl, format);
	total = ft_vprintf((char *)format, vl);
	va_end(vl);
	return (total);
}
