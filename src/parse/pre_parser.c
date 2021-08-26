/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:59 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 22:33:40 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	error_handler(int num, int parentheses)
{
	if (num > 0 && num < 4)
	{
		if (num == 1)
			printf("error, mistake to close: \'\n");
		else if (num == 2)
			printf("error, mistake to close: \"\n");
		return (TRUE);
	}
	if (parentheses)
	{
		if (parentheses > 0)
			printf("error, mistake: )\n");
		else if (parentheses < 0)
			printf("error, mistake: (\n");
		return (TRUE);
	}
	return (FALSE);
}

_Bool	pre_parser(char *line)
{
	unsigned int	i;
	int				parentheses;
	int				quotes_single;

	i = -1;
	parentheses = 0;
	quotes_single = 0;
	while (line[++i] && parentheses >= 0)
	{
		if (line[i] == '\"' && (!i || line[i - 1] != '\\'))
			while (line[++i] && (line[i] != '\"' || line[i - 1] == '\\'))
				;
		if (!line[i])
			return (error_handler(2, 0));
		if (line[i] == '\'' && (!i || line[i - 1] != '\\'))
			while (line[++i] && (line[i] != '\''))
				;
		if (!line[i])
			return (error_handler(1, 0));
		if (line[i] == '(' && (!i || line[i - 1] != '\\'))
			parentheses++;
		else if (line[i] == ')' && (!i || line[i - 1] != '\\'))
			parentheses--;
	}
	return (error_handler(0, parentheses));
}
