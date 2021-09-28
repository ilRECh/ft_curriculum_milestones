/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:26:25 by name              #+#    #+#             */
/*   Updated: 2021/09/28 10:33:06 by name             ###   ########.fr       */
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
