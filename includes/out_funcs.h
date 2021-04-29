#ifndef OUT_FUNCS_H
# define OUT_FUNCS_H

# include "parser.h"
# include "libft.h"

void	out_funcs(va_list arg, int *total, t_specifier *specifier);
void	char_print(char c, int *total, t_specifier *specifier);
void	str_print(char *str, int *total, t_specifier *specifier);
void	pointer_print(void *ptr, int *total, t_specifier *specifier);
void	digit_print(int nbr, int *total, t_specifier *specifier);

#endif