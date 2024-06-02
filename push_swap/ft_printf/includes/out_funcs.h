#ifndef OUT_FUNCS_H
# define OUT_FUNCS_H

# include "parser.h"
# include "libft.h"

typedef struct s_double
{
	union
	{
		uint64_t		all_bits;
		double			value;
		struct
		{
			uint64_t	mantissa : 52;
			uint64_t	exponent : 11;
			uint64_t	sign : 1;
		}	s_bitfields;
	}	u_number;
	uint64_t			true_mantissa : 53;
	int16_t				true_exponent;
	uint64_t			integer_part;
	uint64_t			decimal_part;
}	t_double;

void		out_funcs(va_list arg, int32_t *total, t_specifier *specifier);
void		char_print(char c, int32_t *total, t_specifier *specifier);
void		str_print(char *str, int32_t *total, t_specifier *specifier);
void		pointer_print(uint64_t *ptr, int32_t *total,
				t_specifier *specifier);
void		digit_print(int64_t nbr, int32_t *total, t_specifier *specifier);
void		u_digit_print(uint64_t nbr, int32_t *total, t_specifier *specifier);
void		hex_print(uint64_t nbr, int32_t *total, t_specifier *specifier);
void		feg_print(double to_print, int32_t *total, t_specifier *specifier);
void		g_print(t_list *integer, t_list *decimal, t_specifier *specifier);
uint8_t		feg_special_cases(t_double const *nbr,
				int32_t *total, t_specifier *specifier);
void		ft_int_dec(t_double *nbr, t_list **integer, t_list **decimal);
void		ft_putdouble(t_list **integer, t_list **decimal,
				t_specifier *specifier, int32_t *total);
void		ft_round_decimal(t_list **integer, t_list **decimal,
				t_specifier *specifier);
uint16_t	integer_symbs_count(t_list *integer);
uint16_t	decimal_zeros_count(t_list *decimal);
int16_t		ft_change_to_exp(t_list **integer,
				t_list **decimal, t_specifier *specifier);
void		exclude_trailing_zeros(t_list *decimal, t_specifier *specifier);

#endif
