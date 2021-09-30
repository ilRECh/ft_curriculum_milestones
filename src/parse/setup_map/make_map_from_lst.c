/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_from_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:43:57 by name              #+#    #+#             */
/*   Updated: 2021/09/30 10:18:08 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_for_empty_lines(t_list *lst)
{
	char	*tmp;

	lst->Dcur = lst->Dstart;
	while (lst->Dcur)
	{
		if (ft_strlen(lst->Dcur->content))
		{
			tmp = lst->Dcur->content;
			while (ft_isspace(*tmp))
				tmp++;
			if (!*tmp)
				return (true);
		}
		else
			return (true);
		lst->Dcur = lst->Dcur->next;
	}
	return (false);
}

bool	make_map_from_lst(t_all *all, t_list *lst)
{
	if (check_for_empty_lines(lst))
		return ((all->err
			= ft_strdup("map contains empty lines."
				" Unforgivable. Shame on you.")), true);
	return (false);
}
