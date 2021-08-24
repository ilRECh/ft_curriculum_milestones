/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:32 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 22:33:55 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

short	sub_is_split(char *str)
{
	if (*(str) == '&')
		return (AND);
	if (*(str) == '|')
		return (OR);
	if (*(str) == '<')
		return (RDCT_L2);
	if (*(str) == '>')
		return (RDCT_R2);
	return (0);
}

short	is_split(char *str)
{
	if (!str || !*(str) || *(str - 1) == '\\')
		return (0);
	if (*(str) == '(' && *(str - 1) != '\\')
		return (CASE_OPEN);
	if (*(str) == ')' && *(str - 1) != '\\')
		return (CASE_CLOSE);
	if (*(str) == *(str + 1))
		return (sub_is_split(str));
	if (*(str) == ';')
		return (END);
	if (*(str) == '|')
		return (PIPE);
	if (*(str) == '<')
		return (RDCT_L);
	if (*(str) == '>')
		return (RDCT_R);
	return (FALSE);
}
