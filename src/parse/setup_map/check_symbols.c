/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:04:26 by name              #+#    #+#             */
/*   Updated: 2021/10/02 00:09:40 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check(t_all *all, char *line, int i)
{
	int		j;
	char	tmp[2];

	j = (tmp[1] = 0) - 1;
	while (line && line[++j])
	{
		if (line[j] != ' ' && line[j] != '1' && line[j] != '0')
		{
			if (line[j] != 'W' && line[j] != 'E'
				&& line[j] != 'N' && line[j] != 'S')
				return ((all->err = ft_strjoin("wrong character appeared: ",
					((line[j + 1] = 0), line + j))), true);
			else if (!all->plrpos.direction)
			{
				all->plrpos.direction = line[j];
				all->plrpos.x = j + 1;
				all->plrpos.y = i + 1;
			}
			else
				return ((all->err
					= ft_strjoin("there can be only one player, it is ",
					(tmp[0] = all->plrpos.direction, tmp))), true);
		}
	}
	return (false);
}

bool	check_symbols(t_all *all, t_list *lst)
{
	int	i;

	i = 0;
	lst->Dcur = lst->Dstart;
	while (lst->Dcur)
	{
		if (check(all, lst->Dcur->content, i))
			return (true);
		lst->Dcur = lst->Dcur->next;
		i++;
	}
	if (!all->plrpos.direction)
		return ((all->err = ft_strdup("there is no player")), true);
	return (false);
}
