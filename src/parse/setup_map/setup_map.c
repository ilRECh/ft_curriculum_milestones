/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:49:06 by name              #+#    #+#             */
/*   Updated: 2021/10/01 23:54:30 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	del_empty_from_end(t_all *all, t_list *lst)
{
	t_dlist *next;
	t_dlist	*prev;

	lst->Dcur = ft_lstlastD(lst->Dstart);
	while (lst->Dcur && !ft_strlen(lst->Dcur->content))
	{
		next = lst->Dcur->next;
		prev = lst->Dcur->prev;
#ifdef DEBUG
	printf("lst->Dcur = %p, next = %p, prev = %p\n", lst->Dcur, lst->Dcur->next, lst->Dcur->prev);
#endif
		if (!next && !prev)
		{
			lst->Dstart = NULL;
			ft_lstdeloneD(lst->Dcur, free);
			lst->Dcur = NULL;
		}
		else
		{
			ft_lstdeloneD(lst->Dcur, free);
			lst->Dcur = prev;
		}
	}
	if (!lst->Dcur)
		return ((all->err = ft_strdup("file does not contain a map")), true);
#ifdef DEBUG
{
	int i = 0;
	lst->Dcur = lst->Dstart;
	while (lst->Dcur)
	{
		printf("lst[%3d]: %18p: %s\n", i, lst->Dcur, (char *)lst->Dcur->content);
		i++;
		lst->Dcur = lst->Dcur->next;
	}
}
#endif
	return (false);
}

bool	setup_map(t_all *all, t_list *lst)
{
	char	*tmp;
#ifdef DEBUG
{
	int i = 0;
	lst->Dcur = lst->Dstart;
	while (lst->Dcur)
	{
		printf("lst[%3d]: %18p: %s\n", i, lst->Dcur, (char *)lst->Dcur->content);
		i++;
		lst->Dcur = lst->Dcur->next;
	}
}
#endif
	if (del_empty_from_end(all, lst))
		return (true);
	if (make_map_from_lst(all, lst))
		return (true);
	if (check_closed(all))
		return ((all->err = ft_strjoin("the map is not closed properly"
			" or/and space occured inside the map:\n", (tmp = all->err))),
			free(tmp), true);
	// if (check_extra_regions(all))
	// 	return ((all->err = ft_strdup("extra regions aren't supported")), true);
	return (false);
}
