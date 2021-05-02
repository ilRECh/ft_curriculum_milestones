#include "out_funcs.h"

static void	hex_digit_out_func(va_list arg, int *total, t_specifier *specifier)
{
	if (!specifier->size)
		hex_print(va_arg(arg, uint32_t), total, specifier);
	else if (specifier->size & L_LL_TYPE)
		hex_print(va_arg(arg, uint64_t), total, specifier);
	else if (specifier->size & H_TYPE)
		hex_print((unsigned short int)va_arg(arg, uint32_t),
				total, specifier);
	else if (specifier->size & HH_TYPE)
		hex_print((unsigned char) va_arg(arg, uint32_t), total, specifier);
}

static void	u_digit_out_func(va_list arg, int *total, t_specifier *specifier)
{
	if (!specifier->size)
		u_digit_print(va_arg(arg, uint32_t), total, specifier);
	else if (specifier->size & L_LL_TYPE)
		u_digit_print(va_arg(arg, uint64_t), total, specifier);
	else if (specifier->size & H_TYPE)
		u_digit_print((unsigned short int)va_arg(arg, uint32_t),
				total, specifier);
	else if (specifier->size & HH_TYPE)
		u_digit_print((unsigned char) va_arg(arg, uint32_t), total, specifier);
}

static void	digit_out_func(va_list arg, int *total, t_specifier *specifier)
{
	if (!specifier->size)
		digit_print(va_arg(arg, int32_t), total, specifier);
	else if (specifier->size & L_LL_TYPE)
		digit_print(va_arg(arg, int64_t), total, specifier);
	else if (specifier->size & H_TYPE)
		digit_print((short int)va_arg(arg, int32_t), total, specifier);
	else if (specifier->size & HH_TYPE)
		digit_print((char) va_arg(arg, int32_t), total, specifier);
}

void	out_funcs(va_list arg, int *total, t_specifier *specifier)
{
	if (specifier->type == 'c')
		char_print(va_arg(arg, int32_t), total, specifier);
	else if (specifier->type == 's')
		str_print(va_arg(arg, void *), total, specifier);
	else if (specifier->type == 'p')
		pointer_print(va_arg(arg, void *), total, specifier);
	else if (specifier->type == 'd' || specifier->type == 'i')
		digit_out_func(arg, total, specifier);
	else if (specifier->type == 'u')
		u_digit_out_func(arg, total, specifier);
	else if (specifier->type == 'x' || specifier->type == 'X')
		hex_digit_out_func(arg, total, specifier);
	else if (specifier->type == '%' && write(1, "%", 1))
		*total += 1;
}
