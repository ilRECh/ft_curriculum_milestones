#include "out_funcs.h"

void	out_funcs(va_list arg, int *total, t_specifier *specifier)
{
	if (specifier->type == 'c')
		char_print(va_arg(arg, int), total, specifier);
	else if (specifier->type == 's')
		str_print(va_arg(arg, char *), total, specifier);
	else if (specifier->type == 'p')
		pointer_print(va_arg(arg, void *), total, specifier);
	else if (specifier->type == 'd' || specifier->type == 'i')
		digit_print(va_arg(arg, int), total, specifier);
}
