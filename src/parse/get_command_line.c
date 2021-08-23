/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:05 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/18 06:20:06 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_list	*get_command_line(char **line)
{
	t_list	*lst;

	if (pre_parser(*line))
		return (NULL);
	*line = dollar_get_env(*line);
	if (!ft_strlen(*line))
	{
		free(*line);
		return (NULL);
	}
	lst = split_ignore_caps(*line, 0);
	lst = split_sub_argutils(lst);
	if (post_parser(lst))
		return (NULL);
	// test_print_lst(lst, 0);
	// printf(RESET);
	// printf("\n");
	return (lst);
}
