#include "push_swap.h"

uint8_t	is_sort(t_list stack)
{
	stack.cur = stack.head;
	mark_greater_than(stack);
	while (TRUE)
	{
		if (!((t_content *)stack.cur->content)->keep)
			return (0);
		stack.cur = stack.cur->next;
		if (stack.cur->prev == stack.end)
			break ;
	}
	return (1);
}
