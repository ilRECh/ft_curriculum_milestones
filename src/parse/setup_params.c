/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:48:24 by name              #+#    #+#             */
/*   Updated: 2021/09/29 09:36:35 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map_start(char **split, t_all *all)
{
	int i;
	int j;

	i = (j = -1);
	while (split[++i])
	{
		while (split[i][++j] == '1')
			;
		if (split[i][j])
			return (false);
	}
	return (true);
}

static bool	check_element_name(char **split, t_all *all,
		t_list *lst, int *index)
{
	int			i;
	const char	*values[] = {"NO", "SO", "WE", "EA", "F", "C"};

	if (check_map_start(split, all) && fs(split))
		return (true);
	if ((!split[1] || split[2]))
		return ((all->err = ft_strjoin("invalid element formatting: ", lst->Dcur->content)),
			fs(split), true);
	i = -1;
	while (++i < 6)
	{
		if (!ft_strncmp(split + 0, values[i], ft_strlen(values + i) + 1))
			break ;
	}
	if (i == 6)
		return ((all->err = ft_strjoin("element does not exist: ", split + 0)),
			fs(split), true);
	*index = i;
	return (false);
}

static inline bool	check_element_value(char **split, t_all *all, int *index)
{
	int		mapfd;
	char	**rgb;
	
	if (*index > 3)
	{
		mapfd = open(split[1], O_RDONLY);
		if ((!mapfd || (read(mapfd, NULL, 0) < 0 && close(mapfd))))
			return ((all->err = ft_strjoin("element value invalid: ", split + 1)),
				fs(split), true);
		close(mapfd);
	}
	else
	{
		rgb = ft_split(split + 1, ',');
		if ((!split[1] || !split[2]) && fs(rgb))
			return ((all->err = ft_strjoin("invalid rgb values: ", split + 1)), fs(split), true);
	}
	return (false);
}

static bool	set_element(char **split, t_all *all, t_list *lst, int *index)
{
	const char	*values[] = {"NO", "SO", "WE", "EA", "F", "C"};	
}

bool	setup_params(t_all *all, t_list *lst)
{
	int		i;
	char	**split;

	i = -1;
	lst->Dcur = lst->Dstart;
	while (true)
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
{int i = 0;
while (split[i])
	printf("split[%d]: %s\n", i, split[i]);}
#endif
		if (check_element_name(split, all, lst, &i))
		{
			if (all->err)
				return (true);
			else
				break ;
		}
		else if (check_element_value(split, all, &i))
			return (true);
		else
			set_element(split, all, lst, &i);
	}
	return (false);
}
