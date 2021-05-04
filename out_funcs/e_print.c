#include "out_funcs.h"

static void	setup_str(char *str, int8_t exp)
{
	str[0] = 'e';
	str[3] = exp * (exp >= 0) + exp * ((-1) * (exp < 0));
	if (exp >= 0)
		str[1] = '+';
	else if (exp < 0)
		str[1] = '-';
}

void	e_print(double nbr, int32_t *total, t_specifier *specifier)
{
	int8_t	exp;
	char	str[3];

	if (fge_special_cases(&nbr, total, specifier))
		return ;
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
	if (specifier->width > 8)
		specifier->width -= 4;
	setup_str(str, exp);
	f_print(nbr, total, specifier, str);
	*total += 4;
}
