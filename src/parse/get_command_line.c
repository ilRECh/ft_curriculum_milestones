/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:05 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/26 20:17:25 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_command_line(char **line)
{
	t_list	*lst;

	if (pre_parser(*line))
		return (NULL);
	*line = dollar_get_env(*line);
	*line = slash_parse(*line);
	lst = split_ignore_caps(*line, 0);
	free (*line);
	if (!split_sub_argutils(lst))
	{
		ft_lstclear(lst, free_parse);
		return ((t_list *)ret_perr("utils"));
	}
	if (post_parser(lst))
		return (NULL);
	// test_print_lst(lst, 0);
	return (lst);
}
