/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:48:24 by name              #+#    #+#             */
/*   Updated: 2021/09/28 10:54:34 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	setup_params(t_all *all, t_list *lst)
{
	int			i;
	const char	*values[] = {"NO", "SO", "WE", "EA", "F", "C"};
	char		**split;

	i = 0;
	lst->Dcur = lst->Dstart;
	while (i < 6)
	{
		if (ft_strlen(lst->Dcur->content) == 0)
		{
			lst->Dcur = lst->Dcur->next;
			if (lst->Dcur->prev == lst->Dstart)
				lst->Dstart = lst->Dcur;
			ft_lstdeloneD(lst->Dcur->prev, free);
			continue ;
		}
		split = ft_split(lst->Dcur->content, ' ');
#ifdef DEBUG
int i = 0;
while (split[i])
	printf("split[%d]: %s", i, split[i]);
#endif
		if (split[2] && fs(split))
			return ((all->err = ft_strjoin("wrong argument: ", lst->Dcur->content)), true);
	}
	(void)values;
	return (false);
}
