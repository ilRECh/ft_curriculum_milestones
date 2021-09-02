#include "minishell.h"

char	*set_local(char *str, char *base_str)
{
	char	*start;
	char	*end;
	char	*word;
	char	*new_value;

	(void)base_str;
	word = NULL;
	new_value = NULL;
	start = (end = str);
	while (start > base_str && !ft_isspace(*start - 1))
		start--;
	while (*end && !ft_isspace(*end + 1) && end++)
		if (ft_strchr("\'\"", *end) && *(end - 1) != '\\')
			end += skip_quote(end, 0, *end);
	if (start != str && end != str)
	{
		word = ft_strndup(start, str - start);
		new_value = ft_strndup(str + 1, end - str);
		setval_local(word, new_value);
	}
	return (NULL);
}
