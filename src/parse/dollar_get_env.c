#include "parse.h"

char	*find_env_value(char *needle, char **env)
{
	int	i;

	i = 0;
	while (*env)
	{
		while (needle[i] && env[0][i] && needle[i] == env[0][i])
			i++;
		if(!needle[i])
			return(ft_strdup(&env[0][++i]));
		env++;
	}
    free(needle);
	return (ft_strdup(" "));
}

char	*get_env(char *line, char *ln, char **env)
{
	char	*first_part;
	char	*tmp_fr;
	int		k;

	k = ln - line - 1;
	k = 0;
    tmp_fr = line;
	first_part = ft_strndup(line, ln - line - 1);
	while (ln[k] && !ft_strchr(" \"\'$", ln[k]))
		k++;
	line = ft_strjoin_free(first_part, find_env_value(ft_strndup(ln, k), env), 3);
	line = ft_strjoin_free(line, ft_strdup(ln + k), 3);
    free(tmp_fr);
	return(line);
}

char *dollar_get_env(char *line, char **env)
{
	char	*ln;

	ln = line;
	while(*ln)
	{
		if(*ln == '\'' && (ln == line || *(ln - 1) != '\\'))
			while (*++ln && *ln != '\'')
				;
		if (*ln == '$')
			line = get_env(line, ++ln, env);
		ln++;
	}
	return (line);
}