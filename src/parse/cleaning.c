/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:26:25 by name              #+#    #+#             */
/*   Updated: 2021/09/28 22:29:05 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	fl(t_list *lst)
{
	ft_lstclearD(&lst->Dstart, free);
	ft_lstclearS(&lst->Sstart, free);
	return (true);
}

bool	flf(t_list *lst, int fd)
{
	ft_lstclearD(&lst->Dstart, free);
	ft_lstclearS(&lst->Sstart, free);
	close(fd);
	return (true);
}

bool	fs(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i]);
	free(split);
	return (true);
}

bool	fall(t_all *all)
{
	int	i;

	//win
	//plr
	i = -1;
	while (all->textures[++i])
		free(all->textures[i]);
	free(all->textures);
	i = -1;
	while (all->colors[++i])
		free(all->colors[i]);
	free(all->colors);
	i = -1;
	while (all->map && all->map[++i])
		free(all->map[i]);
	free(all->map);
	free(all->err);
}
