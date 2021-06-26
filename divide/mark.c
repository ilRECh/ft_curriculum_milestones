#include "push_swap.h"

void	mark_greater_than(t_list to_mark)
{
	((t_content *)to_mark.cur->content)->keep = TRUE;
	to_mark.end = to_mark.cur;
	while (TRUE)
	{
		to_mark.cur = to_mark.cur->next;
		if (to_mark.cur == to_mark.end)
			break ;
		if (((t_content *)to_mark.cur->content)->order
			> ((t_content *)to_mark.cur->prev->content)->order)
			((t_content *)to_mark.cur->content)->keep = TRUE;
		else
			((t_content *)to_mark.cur->content)->keep = FALSE;
	}
}

void	mark(t_list to_mark)
{
	int	last;

	last = ft_lstsize(to_mark) - 1;
	if (((t_content *)to_mark.cur->content)->order == last
		|| ((t_content *)to_mark.cur->content)->order + 1 == last
		|| ((t_content *)to_mark.cur->content)->order + 2 == last)
		((t_content *)to_mark.cur->content)->keep = TRUE;
}