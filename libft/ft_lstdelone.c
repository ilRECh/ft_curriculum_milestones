#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	int	lst_size;

	lst_size = ft_lstsize(*lst);
	if (lst_size > 1)
	{
		lst->cur->next->prev = lst->cur->prev;
		lst->cur->prev->next = lst->cur->next;
		if (lst->cur == lst->head)
			lst->head = lst->cur->next;
		else if (lst->cur == lst->end)
			lst->end = lst->cur->prev;
	}
	if (del)
		(*del)(lst->cur->content);
	free(lst->cur);
	lst->cur = NULL;
	if (lst_size == 1)
	{
		lst->head = NULL;
		lst->end = NULL;
	}
}
