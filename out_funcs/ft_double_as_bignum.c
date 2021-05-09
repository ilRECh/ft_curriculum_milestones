#include "out_funcs.h"

static void	ft_integerbignum(t_list **lst, t_double *nbr)
{
	uint8_t		iter_1;
	t_list		*extra;

	iter_1 = -1;
	extra = NULL;
	ft_bignummultiply(lst, 2, nbr->true_exponent);
	while (++iter_1 < 52 && iter_1 < nbr->true_exponent
		&& nbr->true_exponent >= 0)
	{
		if (nbr->integer_part & ((uint64_t) 1 << iter_1))
		{
			ft_bignummultiply(&extra, 2, iter_1
				+ (nbr->true_exponent > 52) * (nbr->true_exponent - 52));
			ft_bignumaddition(*lst, &extra);
		}
	}
}

static void	ft_decimalbignum(t_list **lst, t_double *nbr)
{
	uint8_t		iter_1;
	t_list		*extra;
	int16_t		offset;

	extra = NULL;
	iter_1 = 0;
	offset = 52 - nbr->true_exponent * (nbr->true_exponent > 0);
	ft_bignummultiply(lst, 10, nbr->true_exponent * (-1)
		* (nbr->true_exponent < 0) * (ft_abs(nbr->true_exponent) <= 308)
		- (ft_abs(nbr->true_exponent) > 308));
	ft_bignummultiply(&extra, 5, nbr->true_exponent * (-1)
		* (nbr->true_exponent < 0) * (ft_abs(nbr->true_exponent) <= 308)
		- (nbr->true_exponent >= 0 || ft_abs(nbr->true_exponent) > 308));
	ft_bignumaddition(*lst, &extra);
	while (++iter_1 <= offset && nbr->true_exponent > -1023)
	{
		ft_bignummultiply(lst, 10, 1);
		if (nbr->decimal_part & ((uint64_t)1 << (offset - iter_1)))
		{
			ft_bignummultiply(&extra, 5, iter_1
				+ nbr->true_exponent * ((-1) * (nbr->true_exponent < 0)));
			ft_bignumaddition(*lst, &extra);
		}
	}
}

void	ft_int_dec(t_double *nbr, t_list **integer, t_list **decimal)
{
	uint8_t	iter_1;

	if (nbr->true_exponent > 53)
		nbr->integer_part = nbr->true_mantissa;
	else if (nbr->true_exponent < 0)
		nbr->decimal_part = nbr->true_mantissa;
	else if (nbr->true_exponent >= 0 && nbr->true_exponent <= 53)
	{
		iter_1 = nbr->true_exponent + 1;
		while (iter_1-- > 0)
			nbr->integer_part |= (nbr->true_mantissa
					>> (52 - nbr->true_exponent)) & ((uint64_t)1 << iter_1);
		iter_1 = -1;
		while (++iter_1 < 52 - nbr->true_exponent)
			nbr->decimal_part |= nbr->true_mantissa & ((uint64_t)1 << iter_1);
	}
	ft_integerbignum(integer, nbr);
	ft_decimalbignum(decimal, nbr);
}
