/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:48:24 by name              #+#    #+#             */
/*   Updated: 2021/09/28 22:50:52 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map_start(char **split, t_all *all)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (split[++i])
	{
		while (split[i][++j] == '1')
			;
		if (split[i][j])
	}
}

static bool	check_element_name(char **split, t_all *all,
		const char **values)
{
	int			i;
	static bool	is_set[6] = {false};

	if (check_map_start(split, all) && fs(split))
		return (true);
	i = -1;
	while (++i < 6)
	{
		if (!ft_strncmp(split + 0, values[i], ft_strlen(values + i) + 1))
		{
			if (is_set[i])
				return ((all->err = ft_strjoin("element has already been set: ",
					split + 0)), fs(split), true);
			else
			{
				is_set[i] = true;
				break ;
			}
		}
	}
	if (i == 6)
		return ((all->err = ft_strjoin("element does not exist: ", split + 0)),
			fs(split), true);
	return (false);
}

static inline bool	check_element_value(char **split, t_all *all)
{
	const int	mapfd = open(split[1], O_RDONLY);

	if ((!mapfd || (read(mapfd, NULL, 0) < 0 && close(mapfd))))
		return ((all->err = ft_strjoin("element value corrupted: ", split + 1)),
			fs(split), true);
	close(mapfd);
	return (false);
}

static bool	set_element(char **split, t_all *all, t_list *lst, char **values)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (!ft_strncmp(split + 0, values[i], ft_strlen(values + i) + 1))
			break ;
	
}

bool	setup_params(t_all *all, t_list *lst)
{
	int			i;
	char		**split;
	const char	*values[] = {"NO", "SO", "WE", "EA", "F", "C"};

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
	printf("split[%d]: %s\n", i, split[i]);
#endif
		if (check_element_name(split, all, values))
		{
			if (all->err)
				return (true);
			else
				break ;
		}
		else if (check_element_value(split, all))
			return (true);
		else
			set_element(split, all, lst, values);
	}
	return (false);
}
