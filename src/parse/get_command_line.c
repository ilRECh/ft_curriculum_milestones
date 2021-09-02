/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:05 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/02 11:14:14 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
// test_print_lst(lst, 0);
// printf("\n");
*/

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
	if (!tmp || (long long)tmp < 3 || !lst->head || post_parser(lst))
	{
		if (!tmp)
			return ((t_list *)ret_perr("utils"));
		if ((long long)tmp == 2)
			write (1, "Error: operator is't valid\n", 28);
		if (!tmp || (long long)tmp == 2)
			ft_lstclear(lst, free_parse);
		free(lst);
		return (NULL);
	}
	return (lst);
}
