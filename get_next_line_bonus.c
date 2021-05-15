#include "get_next_line_bonus.h"

uint8_t	del_elem(t_list **lst, int32_t fd)
{
	t_list	*tmp;

	while (*lst)
	{
		if ((*lst)->fd == fd)
			break ;
		lst = &(*lst)->next;
	}
	tmp = (*lst);
	if ((*lst)->next)
		*lst = (*lst)->next;
	else
		*lst = NULL;
	free(tmp->str);
	free(tmp);
	return (0);
}

t_list	*new_elem(char *str, t_list *next, int32_t fd)
{
	t_list	*elem;

	elem = (t_list *)malloc(1 * sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->next = next;
	elem->str = str;
	if (elem->str)
		elem->str[0] = 0;
	elem->fd = fd;
	return (elem);
}

t_list	*rem_search(t_list *lst, int32_t fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		else if (lst->next && lst->next->fd > fd)
		{
			lst->next = new_elem(NULL, lst->next, fd);
			return (lst->next);
		}
		else if (!lst->next)
			break ;
		lst = lst->next;
	}
	if (lst)
	{
		lst->next = new_elem(NULL, NULL, fd);
		return (lst->next);
	}
	return (NULL);
}

uint8_t	ft_retline(char **str, char **line)
{
	char	*n_pos;

	n_pos = ft_strchr(*str, '\n');
	if (!n_pos)
	{
		if (!*str)
			*line = ft_strndup("", 0);
		else
			*line = ft_strndup(*str, ft_strlen(*str));
		free(*str);
		*str = NULL;
		return (0);
	}
	*line = ft_strndup(*str, n_pos - *str);
	if (!*line)
		return (1);
	n_pos = ft_strndup(n_pos + 1, ft_strlen(n_pos + 1));
	free(*str);
	*str = n_pos;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*lst_head;
	t_list			*cur_elem;
	ssize_t			br;

	if (!lst_head || (lst_head->fd != BUF))
		lst_head = new_elem((char *)malloc(BUFFER_SIZE + 1), lst_head, BUF);
	if ((fd < 0 || fd > 260 || !line || !lst_head || !(lst_head->str)
			|| (BUFFER_SIZE < 1)) && !del_elem(&lst_head, BUF))
		return (-1);
	cur_elem = rem_search(lst_head, fd);
	while (!ft_strchr(lst_head->str, '\n') && !ft_strchr(cur_elem->str, '\n'))
	{
		br = read(fd, lst_head->str, BUFFER_SIZE);
		lst_head->str[br] = 0;
		if (br <= 0)
			break ;
		cur_elem->str = ft_strjoin(cur_elem->str, lst_head->str);
	}
	del_elem(&lst_head, BUF);
	if ((br < 0 && !del_elem(&lst_head, fd)) || ft_retline(&cur_elem->str, line))
		return (-1);
	else if (br == 0 && !cur_elem->str)
		return (del_elem(&lst_head, fd));
	return (1);
}
