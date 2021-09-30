/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:48:24 by name              #+#    #+#             */
/*   Updated: 2021/09/30 09:14:07 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map_start(char **split)
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

	if (check_map_start(split) && fs(split))
		return (true);
#ifdef DEBUG
printf("checking the element\n");
#endif
	if (!split[1] || split[2])
		return ((all->err = ft_strjoin("invalid element formatting: ",
			lst->Dcur->content)), fs(split), true);
#ifdef DEBUG
printf("normal configuration\n");
#endif
	i = -1;
	while (++i < 6)
	{
		if (!ft_strncmp(split[0], values[i], ft_strlen(values[i]) + 1))
			break ;
	}
#ifdef DEBUG
printf("the index of the value: %d\n", i);
#endif
	if (i == 6)
		return ((all->err = ft_strjoin("element does not exist: ", split[0])),
			fs(split), true);
	*index = i;
	return (false);
}

static bool	check_element_value(char **split, t_all *all, int *index)
{
	int		mapfd;
	const char	**rgb = NULL;
	
	if (*index < 4)
	{
#ifdef DEBUG
printf("checking the file\n");
#endif
		mapfd = open(split[1], O_RDONLY);
		if (mapfd < 0 || (read(mapfd, NULL, 0) < 0 && close(mapfd)))
			return ((all->err = ft_strjoin("element value invalid: ",split[1])),
				fs(split), true);
		close(mapfd);
#ifdef DEBUG
printf("the file is good\n");
#endif
	}
	else
	{
		rgb = (const char **)ft_split(split[1], ',');
		if (((!rgb[1] || !rgb[2]) 
			|| (check_len_value((char **)rgb))
			|| !(ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[0]) <= 255)
			|| !(ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[1]) <= 255)
			|| !(ft_atoi(rgb[2]) >= 0 && ft_atoi(rgb[2]) <= 255))
				&& fs((char **)rgb))
			return ((all->err = ft_strjoin("invalid rgb values: ", split[1])),
				fs(split), true);
		fs((char **)rgb);
	}
	return (false);
}

//possibility for a texture for the ceilling or the floor is left

static bool	set_element(char **split, t_all *all, t_list *lst, int *index)
{
	const char	**rgb = NULL;
	
#ifdef DEBUG
printf("index: %d\n", *index);
#endif
	if (*index < 4)
	{
#ifdef DEBUG
printf("all->textures + *index: %p\n", all->textures + *index);
#endif
		free(all->textures[*index]);
		all->textures[*index] = ft_strdup(split[1]);
#ifdef DEBUG
printf("all->textures[%d] %s\n", *index, all->textures[*index]);
#endif
	}
	else
	{
		rgb = (const char **)ft_split(split[1], ',');
#ifdef DEBUG
printf("rgbstr: [0] %s, [1] %s, [2] %s\n", rgb[0], rgb[1], rgb[2]);
#endif
		all->colors[*index] = ft_calloc(3, sizeof(unsigned char));
		all->colors[*index][0] = ft_atoi(rgb[0]);
		all->colors[*index][1] = ft_atoi(rgb[1]);
		all->colors[*index][2] = ft_atoi(rgb[2]);
		fs((char **)rgb);
#ifdef DEBUG
printf("rgbdigit: [0] %d, [1] %d, [2] %d\n",
	all->colors[*index][0],
	all->colors[*index][1],
	all->colors[*index][2]);
#endif
	}
	{
		t_dlist *next;
		t_dlist	*prev;

		next = lst->Dcur->next;
		prev = lst->Dcur->prev;
		if (!next && !prev)
		{
			lst->Dstart = NULL;
			ft_lstdeloneD(lst->Dcur, free);
			lst->Dcur = NULL;
		}
		else
		{
			if (lst->Dcur == lst->Dstart)
				lst->Dstart = next;
			ft_lstdeloneD(lst->Dcur, free);
			lst->Dcur = next;
		}
	}
	// lst->Dcur = lst->Dcur->next;
	// if (lst->Dcur && lst->Dcur->prev == lst->Dstart)
	// 	lst->Dstart = lst->Dcur;
	// else if (!lst->Dcur)
	// 	return (false);
	// ft_lstdeloneD(lst->Dcur->prev, free);
	return (false);
}

bool	setup_params(t_all *all, t_list *lst)
{
	int		i;
	char	**split;

	i = -1;
	lst->Dcur = lst->Dstart;
	while (true)
	{
		if (!lst->Dcur)
			break ;
		if (ft_strlen(lst->Dcur->content) == 0)
		{
			lst->Dcur = lst->Dcur->next;
			if (lst->Dcur && lst->Dcur->prev == lst->Dstart)
				lst->Dstart = lst->Dcur;
			else if (!lst->Dcur)
				break ;
			ft_lstdeloneD(lst->Dcur->prev, free);
			continue ;
		}
		split = ft_split(lst->Dcur->content, ' ');
#ifdef DEBUG
{int i = -1;
while (split[++i])
	printf("split[%d]: |%s|\n", i, split[i]);}
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
	if (setup_missing(all))
		return (true);
#ifdef DEBUG
{int i = -1;
while (++i < 6)
	if(all->textures[i])
		printf("all->textures[%d]: |%s|\n", i, all->textures[i]);
	else
		printf("all->textures[%d]: NULL\n", i);
i = -1;
printf("-----------------------------\n");
while (++i < 6)		
	if(all->colors[i])
		printf("all->colors[%d]: |%3d|, |%3d|, |%3d|\n", i, all->colors[i][0]
						, all->colors[i][1]
						, all->colors[i][2]);
	else
		printf("all->colors[%d]: NULL\n", i);	}
#endif
	return (false);
}
