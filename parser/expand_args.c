#include "push_swap.h"

static void	convertation(int *nums, size_t nums_size, t_list *stack_a)
{
	t_content	*content;

	stack_a->cur = stack_a->head;
	while (TRUE)
	{
		content = (t_content *)ft_calloc(1, sizeof(t_content));
		content->value = *((int *)stack_a->cur->content);
		content->order = ft_bin_search(nums, 0, nums_size - 1, content->value);
		free(stack_a->cur->content);
		stack_a->cur->content = content;
		stack_a->cur = stack_a->cur->next;
		if (stack_a->cur->prev == stack_a->end)
			break ;
	}
}

void	expand_args(t_list *stack_a)
{
	int	iter_1;
	int	stack_a_size;
	int	*args;

	stack_a_size = ft_lstsize(*stack_a);
	args = (int *)ft_calloc(stack_a_size, sizeof(int));
	if (!args && ft_printf(RED "ERROR: " RESET "expand_args err.\n"))
	{
		ft_lstclear(stack_a, free);
		exit(4);
	}
	iter_1 = -1;
	stack_a->cur = stack_a->head;
	while (TRUE)
	{
		args[++iter_1] = *((int *)stack_a->cur->content);
		stack_a->cur = stack_a->cur->next;
		if (stack_a->cur->prev == stack_a->end)
			break ;
	}
	ft_mergesort(args, stack_a_size, INT);
	convertation(args, stack_a_size, stack_a);
}