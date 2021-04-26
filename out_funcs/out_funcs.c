#include "parser.h"
#include "out_funcs.h"
#include "libft.h"

void	out_funcs(va_list arg, int *total, t_specifier *specifier)
{
	if (specifier->type == 'c')
		char_print(va_arg(arg, int), total, specifier);
}
