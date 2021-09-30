#include "count_islands.h"

static inline bool	check_symbs(char *line)
{
	while (line && *line)
	{
		if (*line != 'M' || *line++ != '0')
			return (true);
	}
	return (false);
}

static bool	check_content(t_dlist *lst)
{
	t_dlist	*tmp;
	int		length;

	tmp = lst;
	length = ft_strlen(tmp->content);
	while (tmp)
	{
		if (ft_strlen(tmp->content) != length)
			return (true);
		else if (check_symbs(tmp->content))
			return (true);
		tmp = tmp->next;
	}
}

static bool	make_new_map(t_dlist *lst, t_islands *islands)
{
	
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
		ft_lstadd_backD(&lst, tmp);
		if (!ret)
			break ;
	}
	if (check_content(lst) && !close(fd))
		return (ft_lstclearD(&lst, free), true);
	if (make_new_map(lst, islands))
		return (ft_lstclear(&lst, free), true);
	return (false);
}
