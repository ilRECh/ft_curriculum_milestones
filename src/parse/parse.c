/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:03:33 by name              #+#    #+#             */
/*   Updated: 2021/10/01 22:13:03 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse(t_all *all, int fd)
{
	t_list	lst;
	char	*line;
	int		ret;
	
	lst.Scur = (lst.Sstart = (t_slist *)(lst.Dcur = (lst.Dstart = NULL)));
	while (true)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			return ((all->err = ft_strdup("file corrupted while reading")), true);
		ft_lstadd_backD(&lst.Dstart, line);
		if (ret == 0)
			break ;
	}
#ifdef DEBUG
	lst.Dcur = lst.Dstart;
	while (lst.Dcur)
	{
		printf("|%s|\\n\n", (char *)lst.Dcur->content);
		lst.Dcur = lst.Dcur->next;
	}
#endif
	if (setup_params(all, &lst))
		return (flf(&lst, fd), true);
	if (setup_map(all, &lst))
		return (flf(&lst, fd), true);
	return (flf(&lst, fd), false);
}
