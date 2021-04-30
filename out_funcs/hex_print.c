#include "out_funcs.h"

static void	spec_init(t_specifier *specifier,
					  uint32_t *nbr, uint8_t *symbs_amount)
{
	uint8_t oct_flag;

	oct_flag = 2 * ((specifier->flags & OCTAL_FLAG) > 0) * (*nbr > 0);
	if (specifier->width < *symbs_amount + oct_flag)
		specifier->width = *symbs_amount + oct_flag;
	if (specifier->flags & ZERO_FLAG && specifier->precision < 0)
		specifier->precision = specifier->width - oct_flag;
	if (specifier->width - oct_flag < specifier->precision)
		specifier->width = specifier->precision + oct_flag;
}

static void	print_space(t_specifier *specifier,
						uint32_t *nbr, uint8_t *symbs_amount)
{
	int32_t	correction;
	uint8_t	flag_correction;

	flag_correction = 2 * ((specifier->flags & OCTAL_FLAG) > 0) * (*nbr > 0);
	if (*symbs_amount >= specifier->precision)
		correction = *symbs_amount;
	else
		correction = specifier->precision;
	if (specifier->width > correction)
		fill_with(' ',specifier->width - flag_correction
		- correction * (specifier->precision != 0 || *nbr != 0));
}

void	hex_print(uint32_t nbr, int *total, t_specifier *specifier)
{
	uint8_t	symbs_amount;

	symbs_amount = count_symbs(nbr, 16);
	spec_init(specifier, &nbr, &symbs_amount);
	if (!(specifier->flags & MINUS_FLAG))
		print_space(specifier, &nbr, &symbs_amount);
	if (specifier->flags & OCTAL_FLAG && specifier->type == 'x' && nbr)
		write(1, "0x", 2);
	else if (specifier->flags & OCTAL_FLAG && specifier->type == 'X' && nbr)
		write(1, "0X", 2);
	fill_with('0', (specifier->precision > symbs_amount)
				* (specifier->precision - symbs_amount));
	if (specifier->type == 'x' && (specifier->precision || nbr))
		ft_putnbr_base(nbr, 16, "0123456789abcdef");
	else if (specifier->precision || nbr)
		ft_putnbr_base(nbr, 16, "0123456789ABCDEF");
	if (specifier->flags & MINUS_FLAG)
		print_space(specifier, &nbr, &symbs_amount);
	*total += specifier->width - (!(specifier->precision || nbr)
									&& specifier->width == 1);
}
