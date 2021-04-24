#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>

enum
{
	SPECIFIER = '%'
};

int	ft_vprintf(char *format, va_list vl);

#endif
