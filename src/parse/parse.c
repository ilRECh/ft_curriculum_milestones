/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:03:33 by name              #+#    #+#             */
/*   Updated: 2021/09/27 16:13:38 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse(t_all *all, int fd)
{
	t_list	lst;
	char	*line;
	int		ret;
	
	lst.Sstart = NULL;
	while (true)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			return (true);
		ft_lstadd_backS(&lst.Sstart, line);
		if (ret == 0)
			break ;
	}
	lst.Scur = lst.Sstart;
	while (lst.Scur)
	{
		printf("|%s|\\n\n", (char *)lst.Scur->content);
		lst.Scur = lst.Scur->next;
	}
	(void)all;
	return (false);
}