#include "parse.h"

char	*dollar_get_env(char *line)
{
	char	*ln;
	char	*tmp;

	ln = line;
	while (*ln)
	{
		if (*ln == '\'' && (ln == line || *(ln - 1) != '\\'))
			while (*++ln && *ln != '\'')
				;
		if (*ln == '$' && (line == ln || *(ln - 1) != '\\'))
		{
			if (*(ln + 1) == '?')
				tmp = set_last_exit_app(line, ln);
			else
				tmp = set_env(line, ++ln);
			if (tmp)
			{
				line = tmp;
				ln = line;
			}
		}
		tmp = NULL;
		ln++;
	}
	return (line);
}
