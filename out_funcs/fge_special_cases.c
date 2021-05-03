#include "out_funcs.h"

uint8_t	fge_special_cases(double *nbr,
						  int32_t *total, t_specifier *specifier)
{
	t_double	union_nbr;

	union_nbr.value = *nbr;
	if (union_nbr.f_bits.exponent == 0b11111111111
		&& union_nbr.f_bits.sign == 1
		&& union_nbr.f_bits.mantissa == 0)
		str_print("-inf", total, (specifier->precision = -1, specifier));
	else if (union_nbr.f_bits.exponent == 0b11111111111
			&& union_nbr.f_bits.sign == 0
			&& union_nbr.f_bits.mantissa == 0)
		str_print("inf", total, (specifier->precision = -1, specifier));
	else if (union_nbr.f_bits.exponent == 0b11111111111
		&& union_nbr.f_bits.sign == 1
		&& union_nbr.f_bits.mantissa == ((uint64_t)1 << 51))
		str_print("-nan", total, (specifier->precision = -1, specifier));
	else if (union_nbr.f_bits.exponent == 0b11111111111
		  && union_nbr.f_bits.sign == 0
		  && union_nbr.f_bits.mantissa == ((uint64_t )1 << 51))
		str_print("nan", total, (specifier->precision = -1, specifier));
	else
		return (0);
	return (1);
}
