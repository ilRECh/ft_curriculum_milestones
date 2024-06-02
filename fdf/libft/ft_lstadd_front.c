#include "libft.h"

void	ft_lstadd_front(t_list *lst, void *content)
{
	t_dlist	*new;

	if (!lst)
		return ;
	new = ft_lstnew(content);
	if (!new && write(1, RED "ERROR: " RESET "FT_LSTADD_FRONT.\n", 35))
	{
		ft_lstclear(lst, free);
		exit(1);
	}
	if (ft_lstsize(*lst) > 0)
	{
		new->next = lst->head;
		new->prev = lst->end;
		lst->end->next = new;
		lst->head->prev = new;
		lst->head = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		lst->head = new;
		lst->end = new;
	}
}
