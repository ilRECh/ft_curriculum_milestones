#include "out_funcs.h"

void	char_print(char c, int *total, t_specifier *specifier)
{
	if (specifier->width)
	{
		specifier->width--;
		if (specifier->flags & MINUS_FLAG)
		{
			write(1, &c, 1);
			fill_with(' ', specifier->width);
		}
		else
		{
			fill_with(' ', specifier->width);
			write(1, &c, 1);
		}
	}
	else
		write(1, &c, 1);
	*total += 1 + specifier->width;
}
