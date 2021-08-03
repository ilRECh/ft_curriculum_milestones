#include "libft.h"
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
			return(&env[0][++i]);
		env++;
	}
    free(needle);
	return (NULL);	
}

char	*get_env(char *line, char *ln, char **env)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	int		k;

	k = 0;
    tmp = line;
	s1 = ft_strndup(line, ln - line);
	while (ln[k] && !ft_strchr(" \"\'$", ln[k]))
		k++;
	s2 = ft_strdup(ln + k);
	line = ft_strjoin_free(s1, find_env_value(ft_strndup(ln, k + 1), env), 1);
	line = ft_strjoin_free(line, s2, 3);
    free(tmp);
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