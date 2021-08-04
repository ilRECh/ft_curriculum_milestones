#include "libft.h"

int	ft_lstsize(t_list lst)
{
	int	count;

	lst.cur = lst.head;
	count = 0;
	while (lst.cur)
	{
		count++;
		lst.cur = lst.cur->next;
	}
	return (count);
}
