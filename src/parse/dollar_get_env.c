/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:19:57 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/28 22:10:42 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	min_border(int num)
{
	if (num < 0)
		return (0);
	return (num);
}

char	*set_env(char *line, char *ln)
{
	char	*needle;
	char	*res;
	int		klen;
	int		len;

	klen = 0;
	res = NULL;
	while (ln[klen] && !ft_strchr(" /\"\'$", ln[klen]))
		klen++;
	if (!klen)
		return (NULL);
	needle = ft_strndup(ln, klen);
	len = min_border(ln - line - 1);
	if (getvalue(needle))
		res = ft_strjoin_free(ft_strndup(line, len), getvalue(needle), 1);
	else if (getval_local(needle))
		res = ft_strjoin_free(ft_strndup(line, len), getval_local(needle), 1);
	line = ft_strjoin_free(res, ft_strdup(ln + klen), 3);
	free(needle);
	return (line);
}

char	*set_last_exit_app(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strndup(s1, s2 - s1);
	tmp = ft_strjoin_free(tmp, ft_itoa(g_param->ret), 3);
	tmp = ft_strjoin_free(tmp, s2 + 2, 1);
	return (tmp);
}

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
				ln = (line = tmp);
		}
		tmp = NULL;
		ln++;
	}
	return (line);
}
