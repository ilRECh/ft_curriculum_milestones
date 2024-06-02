#include "push_swap.h"

int	not_keep_elem_count(t_list lst)
{
	int	not_keep;

	not_keep = 0;
	lst.cur = lst.head;
	while (TRUE)
	{
		if (!((t_content *)lst.cur->content)->keep)
			not_keep++;
		lst.cur = lst.cur->next;
		if (lst.cur->prev == lst.end)
			break ;
	}
	return (not_keep);
}
