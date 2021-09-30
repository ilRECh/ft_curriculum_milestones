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

static inline void	find_height_length(t_list *lst, int *height, int *length)
{
	int tmp;

	*height = 0;
	*length = 0;
	lst->Dcur = lst->Dstart;
	while (lst->Dcur)
	{
		*height += 1;
		tmp = ft_strlen(lst->Dcur->content);
		if (tmp > *length)
			*length = tmp;
		lst->Dcur = lst->Dcur->next;
	}
}

static inline bool	make_new_map(t_all *all, int height, int length)
{
	int	tmp;

	all->map = ft_calloc(height + 3, sizeof(char *));
	if (!all->map)
		return (true);
	tmp = -1;
	while (++tmp < height + 2)
	{
		all->map[tmp] = malloc((length + 3) * sizeof(char));
		if (!all->map[tmp])
			return (true);
		all->map[tmp][length + 2] = 0;
		ft_memset(all->map[tmp], ' ', length + 2);
	}
#ifdef DEBUG
{
	for (int i = 0; i < height + 2; i++)
	{
		printf("new_map[%3d]: |%s| ,len: %ld\n", i, all->map[i], ft_strlen(all->map[i]));
	}
	printf("\n---------------------------------------------------------\n\n");
}
#endif
	return (false);
}

static inline void	duplicate_map(t_all *all, t_list *lst)
{
	int	i;
	int	j;
	
	i = 1;
	lst->Dcur = lst->Dstart;
	while (lst->Dcur)
	{
		j = 0;
		while (((char *)lst->Dcur->content)[j++])
			all->map[i][j] = ((char *)lst->Dcur->content)[j - 1];
		i++;
		lst->Dcur = lst->Dcur->next;
	}
#ifdef DEBUG
{
	for (int i = 0; all->map[i]; i++)
	{
		printf("new_map[%3d]: |%s| ,len: %ld\n", i, all->map[i], ft_strlen(all->map[i]));
	}
}
#endif
}

bool	make_map_from_lst(t_all *all, t_list *lst)
{
	int	height;
	int	length;

	if (check_for_empty_lines(lst))
		return ((all->err
			= ft_strdup("map contains empty lines."
				" Unforgivable. Shame on you.")), true);
	find_height_length(lst, &height, &length);
	if (make_new_map(all, height, length))
		return ((all->err
			= ft_strdup("no space left")), true);
	duplicate_map(all, lst);
	return (false);
}
