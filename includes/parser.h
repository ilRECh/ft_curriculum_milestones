#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

enum
{
	SPECIFIER_SIGN = '%',
	WE_EXIST = 1
};

typedef struct s_specifier
{
	uint8_t			flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	size;
} t_specifier;

int		ft_vprintf(char *format, va_list vl);
char	*parse_specifier(char *spec, va_list arg, int *total);
char	*flags_parse(char *spec, t_specifier *specifier);
char	*width_parse(char *spec, t_specifier *specifier, va_list arg);
char	*precision_parse(char *spec, t_specifier *specifier, va_list arg);

#endif
