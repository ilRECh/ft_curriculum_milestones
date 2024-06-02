#include "libft.h"

void	ft_lstnormalizer(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		if (lst->value >= MAX_RANK)
		{
			if (!lst->next)
			{
				lst->next = ft_lstnew(lst->value / MAX_RANK);
				lst->next->prev = lst;
			}
			else
				lst->next->value += lst->value / MAX_RANK;
			lst->value %= MAX_RANK;
		}
		lst = lst->next;
	}
}
