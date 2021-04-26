#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

enum
{
	MINUS_FLAG = 0,
	PLUS_FLAG = 1,
	SPACE_FLAG = 2,
	OCTAL_FLAG = 3,
	ZERO_FLAG = 4,
	SPECIFIER_SIGN = '%',
	WE_EXIST = 1
};

typedef struct s_specifier
{
	uint8_t			flags;
	unsigned int	width;
	unsigned int	precision;
	uint8_t			size;
	char			type;
} t_specifier;

int		ft_vprintf(char *format, va_list vl);
char	*parse_specifier(char *spec, va_list arg, int *total);
char	*flags_parse(char *spec, t_specifier *specifier);
char	*width_parse(char *spec, t_specifier *specifier, va_list arg);
char	*precision_parse(char *spec, t_specifier *specifier, va_list arg);
char	*size_parse(char *spec, t_specifier *specifier);

#endif
