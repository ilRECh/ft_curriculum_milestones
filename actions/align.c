#include "push_swap.h"

static void	make_align(t_list *stack_a, int index_of_min, int min_order)
{
	if (index_of_min <= ft_lstsize(*stack_a) / 2)
	{
		while (((t_content *)stack_a->head->content)->order != min_order)
			rotate('a', stack_a, NULL);
	}
	else
	{
		while (((t_content *)stack_a->head->content)->order != min_order)
			reverse_rotate('a', stack_a, NULL);
	}
}

void	align(t_list *stack_a)
{
	int	index_of_min;
	int	min_order;

	min_order = ((t_content *)stack_a->head->content)->order;
	stack_a->cur = stack_a->head;
	while (TRUE)
	{
		if (((t_content *)stack_a->cur->content)->order < min_order)
		{
			index_of_min = ft_lstindex(*stack_a);
			min_order = ((t_content *)stack_a->cur->content)->order;
		}
		stack_a->cur = stack_a->cur->next;
		if (stack_a->cur->prev == stack_a->end)
			break ;
	}
	make_align(stack_a, index_of_min, min_order);
}