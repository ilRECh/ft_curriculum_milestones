#include "libft.h"

void	ft_bignummultiply(t_list **lst, uint64_t value, int16_t power)
{
	t_list	*start;

	if (!lst)
		return ;
	else if (!*lst && power >= 0)
		ft_lstadd_front(lst, ft_lstnew(1));
	else if (power < 0)
	{
		ft_lstadd_front(lst, ft_lstnew(0));
		return ;
	}
	start = *lst;
	while (power--)
	{
		while (start)
		{
			start->value *= value;
			start = start->next;
		}
		ft_lstnormalizer(*lst);
		start = *lst;
	}
}
