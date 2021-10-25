/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:26:25 by name              #+#    #+#             */
/*   Updated: 2021/10/25 21:19:59 by vcobbler         ###   ########.fr       */
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

	i = -1;
	while (split && split[++i])
	{
		free(split[i]);
		(split[i] = NULL);
	}
	free(split);
	return (true);
}

bool	fall(t_all *all)
{
	int	i;

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
	return (true);
}

bool	free_but_i_hate_norminette(void *f)
{
	free(f);
	return (true);
}
