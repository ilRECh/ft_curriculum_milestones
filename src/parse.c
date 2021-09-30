#include "count_islands.h"

static inline bool	check_symbs(char *line)
{
	while (line && *line)
	{
		if (*line != 'M' && *line != '.')
			return (true);
		line++;
	}
	return (false);
}

static bool	check_content(t_dlist *lst)
{
	t_dlist	*tmp;
	int		length;

	if (!lst)
		return (true);
	tmp = lst;
	length = ft_strlen(tmp->content);
	while (tmp)
	{
		if (ft_strlen(tmp->content) != (size_t)length)
			return (true);
		else if (check_symbs(tmp->content))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

static bool	make_new_map(t_dlist *lst, t_islands *islands)
{
	int	i;

	islands->height = ft_lstsizeD(lst);
	islands->length = ft_strlen(lst->content);
	islands->map = malloc((islands->height + 3) * sizeof(char *));
	if (!islands->map)
		return (true);
	islands->map[islands->height + 2] = NULL;
	islands->map[0] = malloc((islands->length + 3) * sizeof(char));
	islands->map[islands->height + 1] = malloc((islands->length + 3) * sizeof(char));
	ft_memset(islands->map[0], '.', islands->length + 2);
	ft_memset(islands->map[islands->height + 1], '.', islands->length + 2);
	i = 0;
	while (lst)
	{
		islands->map[++i] = malloc((islands->length + 3) * sizeof(char));
		islands->map[i][islands->length + 2] = 0;
		ft_memset(islands->map[i], '.', islands->length + 2);
		ft_memcpy(islands->map[i] + 1, lst->content, ft_strlen(lst->content));
		lst = lst->next;
	}
	lst = ft_lstfirstD(lst);
	ft_lstclearD(&lst, free);
	for (int i = 1; i < islands->height + 2; i++)
	{
		islands->map[i][islands->length + 1] = '\n';
		printf("%s", islands->map[i] + 1);
	}
	return (false);
}

bool	parse(char *map, t_islands *islands)
{
	const int		fd = open(map, O_RDONLY);
	int				ret;
	char			*tmp;
	static t_dlist	*lst = NULL;

	if (fd < 0 || (read(fd, NULL, 0) < 0 && !close(fd)))
		return (true);
	while (true)
	{
		ret = get_next_line(fd, &tmp);
		if (ret < 0 && !close(fd))
			return (true);
		if (ft_strlen(tmp))
			ft_lstadd_backD(&lst, tmp);
		else
			free(tmp);
		if (!ret)
			break ;
	}
	if (check_content(lst) && !close(fd))
		return (ft_lstclearD(&lst, free), true);
	if (make_new_map(lst, islands))
		return (ft_lstclearD(&lst, free), true);
	return (false);
}
