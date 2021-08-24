/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:05 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 21:42:09 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_command_line(char **line)
{
	t_list	*lst;

	if (pre_parser(*line))
		return (NULL);
	*line = dollar_get_env(*line);
	lst = split_ignore_caps(*line, 0);
	lst = split_sub_argutils(lst);
	test_print_lst(lst, 0);
	printf(RESET);
	printf("\n");
	return (lst);
}
