/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:59 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/08 20:12:56 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	error_handler(int num, int parentheses, char *str)
{
	if (num == parentheses && num == -1)
		printf("Error: names near redirect is not valid\n");
	else if (num == parentheses && num == -2)
		printf("Error: parentheses not filled in\n");
	else if (num > 0 && num < 4)
	{
		if (num == 1)
			printf("error, mistake to close: \'\n");
		else if (num == 2)
			printf("error, mistake to close: \"\n");
	}
	else if (parentheses)
	{
		if (parentheses > 0)
			printf("error, mistake: )\n");
		else if (parentheses < 0)
			printf("error, mistake: (\n");
	}
	else
		return (FALSE);
	free(str);
	return (TRUE);
}

_Bool	redir_check(char redir, char *str)
{
	_Bool	was_name;

	was_name = FALSE;
	if (str && *str == redir)
		str++;
	while (str && *str && ft_isspace(*str))
		str++;
	if (str && *str && (ft_strchr("\'\"", *str) || ft_isalpha(*str)))
		was_name = TRUE;
	return (was_name);
}

_Bool	is_empty_par(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	if (!*str || *str == ')')
		return (TRUE);
	return (FALSE);
}

_Bool	pre_parser(char *ln)
{
	unsigned int	i;
	int				pare;
	int				quotes_single;

	i = -1;
	pare = (quotes_single = 0);
	while (ln[++i] && pare >= 0)
	{
		if (ft_strchr ("<>", ln[i]) && !redir_check(ln[i], &ln[i + 1]))
			return (error_handler (-1, -1, ln));
		if (ln[i] == '\"' && (!i || ln[i - 1] != '\\'))
			while (ln[++i] && (ln[i] != '\"' || ln[i - 1] == '\\'))
				;
		if (!ln[i])
			return (error_handler(2, 0, ln));
		if (ln[i] == '\'' && (!i || ln[i - 1] != '\\'))
			while (ln[++i] && (ln[i] != '\''))
				;
		if (!ln[i])
			return (error_handler(1, 0, ln));
		((!i || ln[i - 1] != '\\') && \
		((ln[i] == '(' && ++pare) || (ln[i] == ')' && pare--)));
		if (ln[i] == '(' && is_empty_par(&ln[i + 1]))
			return (error_handler(-2, -2, ln));
	}
	return (error_handler(0, pare, ln));
}
