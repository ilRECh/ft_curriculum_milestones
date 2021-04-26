#include "parser.h"

static void		fill_with(char c, unsigned int amount)
{
	while (amount--)
		write(1, &c, 1);
}

void char_print(char c, int *total, t_specifier *specifier)
{
	if (specifier->width)
	{
		specifier->width--;
		if (specifier->flags & (1 << MINUS_FLAG))
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
