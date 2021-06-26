#include "libft.h"

void	ft_lstiter(t_list lst, void (*f)(t_list))
{
	lst.cur = lst.head;

	while (TRUE)
	{
		(*f)(lst);
		lst.cur = lst.cur->next;
		if (lst.cur == lst.head)
			break;
	}
}
