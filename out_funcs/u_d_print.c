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
	if (specifier->width < *symbs_amount)
		specifier->width = *symbs_amount;
	if (specifier->flags & ZERO_FLAG && specifier->precision < 0)
		specifier->precision = specifier->width;
	if (specifier->width < specifier->precision)
		specifier->width = specifier->precision;
}

static void	print_space(t_specifier *specifier,
						   uint64_t const *nbr, uint8_t const *symbs_amount)
{
	int32_t	correction;

	if (*symbs_amount >= specifier->precision)
		correction = *symbs_amount;
	else
		correction = specifier->precision;
	if (specifier->width > correction)
		fill_with(' ', specifier->width
			- correction * (specifier->precision != 0 || *nbr != 0));
}

void	u_digit_print(uint64_t u_nbr, int *total, t_specifier *specifier)
{
	uint8_t		symbs_amount;

	symbs_amount = count_symbs(u_nbr, 10);
	if (!specifier->precision && !u_nbr)
		symbs_amount = 0;
	spec_init(specifier, &symbs_amount);
	if (!(specifier->flags & MINUS_FLAG))
		print_space(specifier, &u_nbr, &symbs_amount);
	fill_with('0', (specifier->precision > symbs_amount)
		* (specifier->precision - symbs_amount));
	if (specifier->precision || u_nbr)
		ft_putnbr_base(u_nbr, 10, "0123456789");
	if (specifier->flags & MINUS_FLAG)
		print_space(specifier, &u_nbr, &symbs_amount);
	*total += specifier->width;
}
