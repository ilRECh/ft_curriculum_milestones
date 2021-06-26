#include "libft.h"

void	ft_lstclear(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	lst->cur = lst->head;
	lst->end->next = NULL;
	while (lst->cur)
	{
		(*del)(lst->cur->content);
		lst->cur = lst->cur->next;
		free(lst->head);
		lst->head = lst->cur;
	}
	lst->head = NULL;
	lst->cur = NULL;
	lst->end = NULL;
}
