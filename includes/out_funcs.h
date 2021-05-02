#ifndef OUT_FUNCS_H
# define OUT_FUNCS_H

# include "parser.h"
# include "libft.h"

void	out_funcs(va_list arg, int32_t *total, t_specifier *specifier);
void	char_print(char c, int32_t *total, t_specifier *specifier);
void	str_print(char *str, int32_t *total, t_specifier *specifier);
void	pointer_print(uint64_t *ptr, int32_t *total, t_specifier *specifier);
void	digit_print(int64_t nbr, int32_t *total, t_specifier *specifier);
void	u_digit_print(uint64_t nbr, int32_t *total, t_specifier *specifier);
void	hex_print(uint64_t nbr, int32_t *total, t_specifier *specifier);

#endif