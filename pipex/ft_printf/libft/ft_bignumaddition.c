#include "libft.h"

void	ft_bignumaddition(t_list *lst, t_list **extra)
{
	t_list	*second;
	t_list	*first;

	second = *extra;
	first = lst;
	while (first && second)
	{
		first->value += second->value;
		first = first->next;
		second = second->next;
	}
	ft_lstnormalizer(lst);
	ft_lstclear(extra);
}
