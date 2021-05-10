#include "libft.h"

static void bignummultiply(t_list **lst, uint64_t value, int16_t power)
{
	t_list		*start;
	uint64_t	multiplier;

	start = *lst;
	multiplier = 1;
	while (TRUE)
	{
		if (power < 0)
			break ;
		while ((multiplier / 1000000000) == 0 && power--)
			multiplier *= value;
		while (start)
		{
			start->value *= multiplier;
			start = start->next;
		}
		ft_lstnormalizer(*lst);
		start = *lst;
		multiplier = 1;
	}
}

void	ft_bignummultiply(t_list **lst, uint64_t value, int16_t power)
{
	if (!lst)
		return ;
	else if (!*lst && power >= 0)
		ft_lstadd_front(lst, ft_lstnew(1));
	else if (power < 0)
	{
		ft_lstadd_front(lst, ft_lstnew(0));
		return ;
	}
	bignummultiply(lst, value, power);
}
