/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_old.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:47:19 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/02 10:51:05 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*set_last_exit_app_old(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strndup(s1, s2 - s1);
	if (!tmp)
		exit (ret_perr("malloc"));
	tmp = ft_strjoin_free(tmp, ft_itoa(g_param->ret), 3);
	if (!tmp)
		exit (ret_perr("malloc"));
	tmp = ft_strjoin_free(tmp, s2 + 2, 1);
	if (!tmp)
		exit (ret_perr("malloc"));
	return (tmp);
}

char	*set_env_old(char *line, char *ln)
{
	char	*needle;
	char	*tmp_fr;
	int		klen;
	int		len;

	len = 0;
	klen = 0;
	while (ln[klen] && !ft_strchr(" /\"\'$", ln[klen]))
		klen++;
	if (!klen)
		return (NULL);
	needle = ft_strndup(ln, klen);
	if (!needle)
		return (NULL);
	if (ln > line)
		len = ln - line - 1;
	tmp_fr = line;
	line = ft_strjoin_free(ft_strndup(line, len), getvalue(needle), 1);
	free(tmp_fr);
	if (line)
		line = ft_strjoin_free(line, ft_strdup(ln + klen), 3);
	free(needle);
	return (line);
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
				tmp = set_last_exit_app_old(line, ln);
			else
				tmp = set_env_old(line, ++ln);
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
