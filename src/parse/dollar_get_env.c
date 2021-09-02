/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:47:41 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/03 01:56:26 by csamuro          ###   ########.fr       */
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

char	*get_some_var(char *str)
{
	char	*tmp;

	tmp = getvalue(str);
	if (!tmp)
		tmp = getval_local(str);
	free (str);
	return (tmp);
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

static void	seb_str_dollr(t_parse *parse, char **str, int i)
{
	char	*tmp;

	tmp = *str;
	while (*tmp && !ft_isspace(*tmp) && *tmp != '=')
		tmp++;
	if (*tmp == '=')
		return ;
	tmp = NULL;
	if (*((*str) + 1) == '?')
		tmp = set_last_exit_app(parse->argv[i], (*str));
	else
		tmp = set_env(parse->argv[i], (*str) + 1);
	if (tmp && *tmp)
	{
		free (parse->argv[i]);
		(*str) = tmp + ((*str) - parse->argv[i]) - 1;
		parse->argv[i] = tmp;
	}
}

unsigned int	dollr(t_parse *parse, t_list *l)
{
	unsigned int	i;
	char			*str;
	char			*tmp;
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
				tmp = str;
				while (tmp > parse->argv[i] && !ft_isspace(*tmp - 1))
					tmp--;
				if (ft_isalpha(*tmp))
					set_local(str, parse->argv[i]);
				else
				{
					ft_lstclear(l, free_parse);
					write (1, "Error: first char in variable isn't alpha\n", 43);
				}
				return (1);
			}
			if (*str == '$' && (parse->argv[i] == str || *(str - 1) != '\\'))
				seb_str_dollr(parse, &str, i);
			str++;
		}
	}
	return (0);
}
