#include "out_funcs.h"

static void	spec_init(t_specifier *specifier, uint8_t const *symbs_amount)
{
	if (specifier->width < 0)
	{
		specifier->width *= -1;
		specifier->flags |= MINUS_FLAG;
		if (specifier->flags & ZERO_FLAG)
			specifier->flags ^= ZERO_FLAG;
	}
	if (specifier->width < *symbs_amount + 2)
		specifier->width = *symbs_amount + 2;
	if ((specifier->flags & ZERO_FLAG) && specifier->precision < 0)
		specifier->precision = specifier->width - 2;
	else if (specifier->precision < *symbs_amount)
		specifier->precision = *symbs_amount;
	if (specifier->width - 2 < specifier->precision)
		specifier->width = specifier->precision + 2;
}

void	pointer_print(uint64_t *ptr, int *total, t_specifier *specifier)
{
	uint8_t	symbs_amount;
	uint8_t	not_print;

	not_print = 1;
	symbs_amount = count_symbs((uint64_t)ptr, 16);
	if (!specifier->precision && !(uint64_t)ptr && not_print--)
		symbs_amount = 0;
	spec_init(specifier, &symbs_amount);
	if (!(specifier->flags & MINUS_FLAG))
		fill_with(' ', specifier->width - 2 - specifier->precision);
	write(1, "0x", 2);
	fill_with('0', (specifier->precision > symbs_amount)
		* (specifier->precision - symbs_amount));
	if (not_print || (uint64_t)ptr)
		ft_putnbr_base((uint64_t)ptr, 16, "0123456789abcdef");
	if (specifier->flags & MINUS_FLAG)
		fill_with(' ', specifier->width - 2 - specifier->precision);
	*total += specifier->width;
}
