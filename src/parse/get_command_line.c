/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:05 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/31 19:51:36 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_command_line(char **line)
{
	t_list	*lst;

	if (!**line)
	{
		free(*line);
		return (NULL);
	}
	if (pre_parser(*line))
		return (NULL);
	lst = split_ignore_caps(*line, 0);
	free (*line);
	if (!split_args(lst))
	{
		ft_lstclear(lst, free_parse);
		return ((t_list *)ret_perr("utils"));
	}
	if (post_parser(lst))
		return (NULL);
	return (lst);
}
