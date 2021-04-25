#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include <unistd.h>

enum
{
	SPECIFIER = '%'
};

int	ft_vprintf(char *format, va_list vl);
int	parse_specifier(char *spec, va_list arg);

#endif
