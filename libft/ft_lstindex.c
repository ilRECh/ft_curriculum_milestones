#include "libft.h"

int	ft_lstindex(t_list lst)
{
	int	index;

	index = 0;
	while (lst.head && lst.head != lst.cur)
	{
		lst.head = lst.head->next;
		index++;
	}
	if (!lst.head)
		return (-1);
	return (index);
}
