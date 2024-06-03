/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:47:41 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/08 20:37:41 by vcobbler         ###   ########.fr       */
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

static _Bool	seb_dollr(t_parse *parse, char **str, int i, t_list *l)
{
	char	*tmp;

	tmp = *str;
	if (!tmp[1] || ft_strchr("<>|&\"\'()\\", tmp[1]) || ft_isspace(tmp[1]))
		return (FALSE);
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
		free(tmp), ft_lstdelone(l, free_parse);
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

typedef struct s_dollr
{
	unsigned int	i;
	char			*str;
	_Bool			was_space;
	_Bool			quot;
}	t_dollr;

unsigned int	dollr(t_parse *parse, t_list *l)
{
	t_dollr	var;

	var.i = (var.quot = FALSE) - 1;
	while (parse->argv[++var.i])
	{
		var.str = parse->argv[var.i];
		var.was_space = FALSE;
		while (l->head && *var.str)
		{
			(!var.quot && *var.str == '\"' && ++var.quot) || (var.quot \
			&& *var.str == '\"' && *(var.str - 1) != '\\' && --var.quot);
			if (!var.quot && *var.str == '\'' && *++var.str)
				while (*var.str && *var.str != '\'')
					var.str++;
			!var.was_space && ft_isspace(*var.str) && ++var.was_space;
			if (*var.str == '=' && !var.was_space)
				return (ft_for_equal(var.str, parse->argv[var.i], l));
			if ((*var.str == '$' && (parse->argv[var.i] == var.str || \
			var.str[-1] != '\\')) && (seb_dollr(parse, &var.str, var.i, l)))
				return (1);
			var.str++;
		}
	}
	return (0);
}
