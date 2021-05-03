#ifndef OUT_FUNCS_H
# define OUT_FUNCS_H

# include "parser.h"
# include "libft.h"

typedef union u_double
{
	double		value;
	struct
	{
		uint64_t	mantissa: 52;
		uint16_t 	exponent: 11;
		uint8_t		sign: 1;
	} f_bits;
}	t_double;

void	out_funcs(va_list arg, int32_t *total, t_specifier *specifier);
void	char_print(char c, int32_t *total, t_specifier *specifier);
void	str_print(char *str, int32_t *total, t_specifier *specifier);
void	pointer_print(uint64_t *ptr, int32_t *total, t_specifier *specifier);
void	digit_print(int64_t nbr, int32_t *total, t_specifier *specifier);
void	u_digit_print(uint64_t nbr, int32_t *total, t_specifier *specifier);
void	hex_print(uint64_t nbr, int32_t *total, t_specifier *specifier);
void	f_print(double nbr, int32_t *total, t_specifier *specifier);
uint8_t	fge_special_cases(double *nbr, int32_t *total, t_specifier *specifier);

#endif