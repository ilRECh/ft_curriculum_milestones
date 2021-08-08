#include "parse.h"

// char	*find_env_value(char *needle, char **env)
// {
// 	int	i;

// 	i = 0;
// 	while (*env)
// 	{
// 		while (needle[i] && env[0][i] && needle[i] == env[0][i])
// 			i++;
// 		if(!needle[i])
// 			return(ft_strdup(&env[0][++i]));
// 		env++;
// 	}
//     free(needle);
// 	return (ft_strdup(" "));
// }

int	min_border(int num)
{
	if (num < 0)
		return (0);
	return (num);
}

char	*set_env(char *line, char *ln)
{
	char	*needle;
	char	*tmp_fr;
	int		klen;
	int		len;

	klen = 0;
    tmp_fr = line;
	while (ln[klen] && !ft_strchr(" \"\'$", ln[klen]))
		klen++;
	needle = ft_strndup(ln, klen);
	if (!needle)
		return (NULL);
	len = min_border(ln - line - 1);
	line = ft_strjoin_free(ft_strndup(line, len), getvalue(needle), 1);
	if (!line)
	{
		free(needle);
		return (NULL);
	}
	line = ft_strjoin_free(line, ft_strdup(ln + klen), 3);
	free(needle);
	if (!line)
		return (NULL);
    free(tmp_fr);
	return(line);
}

// char	*set_env(char *line, char *ln)
// {
// 	char	*first_part;
// 	char	*needle;
// 	char	*tmp_fr;
// 	int		k;

// 	k = 0;
//     tmp_fr = line;
// 	first_part = ft_strndup(line, min_border(ln - line - 1));
// 	while (ln[k] && !ft_strchr(" \"\'$", ln[k]))
// 		k++;
// 	needle = ft_strndup(ln, k);
// 	line = ft_strjoin_free(first_part, getvalue(needle), 1);
// 	line = ft_strjoin_free(line, ft_strdup(ln + k), 3);
//     free(tmp_fr);
// 	return(line);
// }

char *dollar_get_env(char *line)
{
	char	*ln;
	char	len;
	char	len2;

	ln = line;
	len = ft_strlen(line);
	while(*ln)
	{
		if(*ln == '\'' && (ln == line || *(ln - 1) != '\\'))
			while (*++ln && *ln != '\'')
				;
		if (*ln == '$' && (line == ln || *(ln - 1) != '\\'))
		{
			line = set_env(line, ++ln);
			if (!line)
				return(NULL);
			len2 = ft_strlen(line);
			ln = line + len2 - len;
			len = len2;
		}
		ln++;
	}
	return (line);
}