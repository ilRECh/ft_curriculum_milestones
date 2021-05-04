#include "out_funcs.h"

static void	spec_init(t_specifier *specifier)
{
	if (specifier->precision < 0)
		specifier->precision = 6;
	else if (specifier->precision == 0)
		specifier->precision = 1;
}

static int32_t	count_exp(double nbr)
{
	int	exp;

	exp = 0;
	while ((nbr > 10 && nbr > 0) || (nbr < -10 && nbr < 0))
	{
		nbr /= 10;
		exp++;
	}
	while ((nbr < 1 && nbr > 0) || (nbr > -1 && nbr < 0))
	{
		nbr *= 10;
		exp--;
	}
	return (exp);
}

static void	f_precision_setup(double const *nbr, t_specifier *specifier)
{
	double	decimal;
	double	correction;
	double	u_nbr;
	uint8_t iter_1;

	u_nbr = *nbr * (-1 * (*nbr < 0)) + *nbr * (*nbr >= 0);
	decimal = u_nbr - (double)((uint64_t)u_nbr);
	correction = 5.f;
	specifier->precision++;
	iter_1 = -1;
	while (++iter_1 < specifier->precision)
		correction /= 10;
	decimal += correction;
	correction = decimal;
	while (--specifier->precision)
	{
		iter_1 = -1;
		while (++iter_1 < specifier->precision)
			correction = correction * 10;
		if ((uint64_t)correction % 10 != 0)
			break ;
		correction = decimal;
	}
}

static void	e_precision_setup(double const *nbr, t_specifier *specifier)
{
	double	nbr_copy;

	nbr_copy = *nbr;
	while ((nbr_copy > 10 && nbr_copy > 0) || (nbr_copy < -10 && nbr_copy < 0))
		nbr_copy /= 10;
	f_precision_setup(&nbr_copy, specifier);
}

void	g_print(double nbr, int32_t *total, t_specifier *specifier)
{
	int32_t	exp;

	if (fge_special_cases(&nbr, total, specifier))
		return ;
	spec_init(specifier);
	exp = count_exp(nbr);
	if (specifier->precision > exp && exp >= -4)
	{
		specifier->precision -= exp + 1;
		f_precision_setup(&nbr, specifier);
		f_print(nbr, total, specifier, NULL);
	}
	else
	{
		specifier->precision--;
		e_precision_setup(&nbr, specifier);
		e_print(nbr, total, specifier);
	}
}
