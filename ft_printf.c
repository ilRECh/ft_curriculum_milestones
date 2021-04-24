#include "includes/parser.h"

int	ft_printf(char *format, ...)
{
	va_list	vl;
	int	total;

	va_start(vl, format);
	total = ft_vprintf(format, vl);
	va_end(vl);
	return (total);
}
