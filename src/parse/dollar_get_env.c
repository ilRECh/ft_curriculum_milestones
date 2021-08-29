/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:19:57 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/29 19:44:04 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_env(char *line, char *ln)
{
	char	*needle;
	char	*res;
	int		klen;
	int		len;

	len = 0;
	klen = 0;
	res = NULL;
	while (ln[klen] && !ft_strchr(" /\"\'$", ln[klen]))
		klen++;
	if (!klen)
		return (NULL);
	needle = ft_strndup(ln, klen);
	if (ln > line)
		len = ln - line - 1;
	if (getvalue(needle))
		res = ft_strjoin_free(ft_strndup(line, len), getvalue(needle), 1);
	else if (getval_local(needle))
		res = ft_strjoin_free(ft_strndup(line, len), getval_local(needle), 1);
	free(needle);
	return (ft_strjoin_free(res, ft_strdup(ln + klen), 3));
}

char	*set_last_exit_app(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strndup(s1, s2 - s1);
	tmp = ft_strjoin_free(tmp, ft_itoa(g_param->ret), 3);
	tmp = ft_strjoin_free(tmp, s2 + 2, 1);
	return (tmp);
}

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

static void	seb_str_dollr(t_parse *parse, char **str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (*((*str) + 1) == '?')
		tmp = set_last_exit_app(parse->argv[i], (*str));
	else
		tmp = set_env(parse->argv[i], (*str) + 1);
	if (tmp)
	{
		free (parse->argv[i]);
		(*str) = tmp + ((*str) - parse->argv[i]);
		parse->argv[i] = tmp;
	}
}

unsigned int	dollr(t_parse *parse)
{
	unsigned int	i;
	char			*str;
	_Bool			was_space;

	i = -1;
	while (parse->argv[++i])
	{
		str = parse->argv[i];
		was_space = FALSE;
		while (*str)
		{
			if (ft_isspace(*str))
				was_space = TRUE;
			if (*str == '=' && !was_space)
			{
				set_local(str, parse->argv[i]);
				return (1);
			}
			if (*str == '$' && (parse->argv[i] == str || *(str - 1) != '\\'))
				seb_str_dollr(parse, &str, i);
			str++;
		}
	}
	return (0);
}
