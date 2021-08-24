/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:19:57 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/18 06:19:59 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
	while (ln[klen] && !ft_strchr(" /\"\'$", ln[klen]))
		klen++;
	if (!klen)
		return (line);
	needle = ft_strndup(ln, klen);
	if (!needle)
		return (NULL);
	len = min_border(ln - line - 1);
	tmp_fr = line;
	line = ft_strjoin_free(ft_strndup(line, len), getvalue(needle), 1);
	free(tmp_fr);
	if (!line)
	{
		free(needle);
		return (NULL);
	}
	line = ft_strjoin_free(line, ft_strdup(ln + klen), 3);
	free(needle);
	return (line);
}

char	*dollar_get_env(char *line)
{
	char	*ln;
	int		len;
	int		len2;

	ln = line;
	len = ft_strlen(line);
	while (*ln)
	{
		if (*ln == '\'' && (ln == line || *(ln - 1) != '\\'))
			while (*++ln && *ln != '\'')
				;
		if (*ln == '$' && (line == ln || *(ln - 1) != '\\'))
		{
			line = set_env(line, ++ln);
			if (!line)
				exit((short)ret_perr("malloc err, dollar") + 1);
			len2 = ft_strlen(line);
			if (!*ln)
				break ;
			ln = line;
			len = len2;
		}
		ln++;
	}
	return (line);
}
