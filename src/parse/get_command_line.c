/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:05 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/02 03:34:25 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_command_line(char **line)
{
	t_list	*lst;
	t_list	*tmp;

	if (!**line)
	{
		free(*line);
		return (NULL);
	}
	if (pre_parser(*line))
		return (NULL);
	lst = split_ignore_caps(*line, 0);
	free (*line);
	tmp = split_args(lst);
	if (!tmp)
	{
		ft_lstclear(lst, free_parse);
		return ((t_list *)ret_perr("utils"));
	}
	// test_print_lst(lst, 0);
	// printf("\n");
	if ((unsigned int)tmp == 1 || post_parser(lst))
		return (NULL);
	if (!lst->head)
	{
		free(lst);
		return (NULL);
	}
	return (lst);
}
