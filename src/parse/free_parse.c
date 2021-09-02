/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:25:52 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/02 07:04:35 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_parse(void *p)
{
	t_parse	*parse;
	int		i;

	i = 0;
	parse = (t_parse *)p;
	if (parse->argv)
	{
		if (parse->argv[i] && \
		!ft_strncmp(parse->argv[i], CASE, ft_strlen(CASE)))
			ft_lstclear((t_list *)parse->argv[1], free_parse);
		if (parse->argv[i])
			free(parse->argv[i]);
		while (parse->argv[++i])
			free(parse->argv[i]);
		free(parse->argv);
	}
	free(parse);
}
