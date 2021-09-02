/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:15 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/02 07:05:22 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_next_sp(char **ln, short *sp)
{
	*sp = is_split((*ln));
	while (*(*ln) && !*sp)
	{
		if (ft_strchr("\"\'", *(*ln)) && *((*ln) - 1) != '\\')
			skip_quotation(ln);
		else
			(*ln)++;
		*sp = is_split(*ln);
	}
}
