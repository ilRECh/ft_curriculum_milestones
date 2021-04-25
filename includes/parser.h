#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

enum
{
	SPECIFIER = '%'
};

int		ft_vprintf(char *format, va_list vl);
char	*parse_specifier(char *spec, va_list arg, int *total);

#endif
