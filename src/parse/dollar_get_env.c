/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:47:41 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/03 02:39:56 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_dollar_variable(char *ln, char *line)
{
	char	*tmp;
	int		len;

	tmp = ln - 1;
	len = ft_strlen(tmp);
	ft_memmove(tmp, tmp + 1, len--);
	while (len && !ft_strchr(" \"\'\\$", *tmp))
		ft_memmove(tmp, tmp + 1, len--);
	return (line);
}

char	*set_env(char *line, char *ln)
{
	char	*needle;
	char	*res;
	int		klen;
	int		len;

	res = NULL;
	len = (klen = 0);
	while (ln[klen] && !ft_strchr(" /\\\"\'$", ln[klen]))
		klen++;
	if (!klen)
		return (NULL);
	needle = ft_strndup(ln, klen);
	if (ln > line)
		len = ln - line - 1;
	needle = get_some_var(needle);
	if (needle)
		res = ft_strjoin_free(ft_strndup(line, len), needle, 1);
	else
		return (ft_strdup(rm_dollar_variable(ln, line)));
	return (ft_strjoin_free(res, ft_strdup(ln + klen), 3));
}

static _Bool	seb_str_dollr(t_parse *parse, char **str, int i, t_list *l)
{
	char	*tmp;

	tmp = *str;
	while (*tmp && !ft_isspace(*tmp) && *tmp != '=')
		tmp++;
	if (*tmp == '=')
		return (FALSE);
	if (*((*str) + 1) == '?')
		tmp = set_last_exit_app(parse->argv[i], (*str));
	else
		tmp = set_env(parse->argv[i], (*str) + 1);
	if (tmp && *tmp)
	{
		free (parse->argv[i]);
		(*str) = tmp + ((*str) - parse->argv[i]) - 1;
		parse->argv[i] = tmp;
		return (FALSE);
	}
	else if (tmp)
	{
		free (tmp);
		ft_lstdelone(l, free_parse);
		return (TRUE);
	}
	return (TRUE);
}

unsigned int	ft_for_equal(char *str, char *base_str, t_list *l)
{
	char		*tmp;

	tmp = str;
	while (tmp > base_str && !ft_isspace(*tmp - 1))
		tmp--;
	if (ft_isalpha(*tmp))
		set_local(str, base_str);
	else
	{
		ft_lstclear(l, free_parse);
		write (1, "Error: first char in variable isn't alpha\n", 43);
	}
	return (1);
}

unsigned int	dollr(t_parse *parse, t_list *l)
{
	unsigned int	i;
	char			*str;
	_Bool			was_space;
	_Bool			quot;

	i = -1;
	quot = FALSE;
	while (parse->argv[++i])
	{
		str = parse->argv[i];
		was_space = FALSE;
		while (l->head && *str)
		{
			if ((!quot && *str == '\"') || (quot && *str == '\"' && *(str -1) != '\\'))
				quot = !quot;
			if (!quot && *str == '\'' && *++str)
				while (*str && *str != '\'')
					str++;
			if (ft_isspace(*str))
				was_space = TRUE;
			if (*str == '=' && !was_space)
				return (ft_for_equal(str, parse->argv[i], l));
			if (*str == '$' && (parse->argv[i] == str || *(str - 1) != '\\'))
				if (seb_str_dollr(parse, &str, i, l))
					return (1);
			str++;
		}
	}
	return (0);
}
