#include "push_swap.h"

static void	prepare_a(t_list stack_a, t_merge_conf *max, t_merge_conf *cur)
{
	max->steps_a = ft_lstsize(stack_a);
	max->dir_a = NO_DIR;
	if (cur->steps_a < max->steps_a)
	{
		max->steps_a = cur->steps_a;
		max->dir_a = cur->dir_a;
	}
}

static void	prepare_b(t_list stack_b, t_merge_conf *max, t_merge_conf *cur)
{
	max->steps_b = ft_lstsize(stack_b);
	max->dir_b = NO_DIR;
	if (ft_lstindex(stack_b) <= ft_lstsize(stack_b) / 2)
	{
		cur->steps_b = ft_lstindex(stack_b);
		cur->dir_b = ROTATE * !(!cur->steps_b) + NO_DIR * (!cur->steps_b);
	}
	else
	{
		cur->steps_b = ft_lstsize(stack_b) - ft_lstindex(stack_b);
		cur->dir_b = REVERSE_ROTATE;
	}
	if (cur->steps_b < max->steps_b)
	{
		max->steps_b = cur->steps_b;
		max->dir_b = cur->dir_b;
	}
}

static void	prepare(t_list stack_a, t_list stack_b, t_merge_conf *total)
{
	t_merge_conf	max;
	t_merge_conf	cur;
	int				smaller;
	int				bigger;

	stack_b.cur = stack_b.head;
	while (TRUE)
	{
		prepare_b(stack_b, &max, &cur);
		find_smaller_and_bigger(&smaller, &bigger,
			((t_content *)stack_b.cur->content)->order, stack_a);
		index_check(smaller, bigger, stack_a, &cur);
		prepare_a(stack_a, &max, &cur);
		if (total->steps_a + total->steps_b > max.steps_a + max.steps_b)
		{
			total->steps_a = max.steps_a;
			total->steps_b = max.steps_b;
			total->dir_a = max.dir_a;
			total->dir_b = max.dir_b;
		}
		stack_b.cur = stack_b.cur->next;
		if (stack_b.cur->prev == stack_b.end)
			break ;
	}
}

static void	proceed(t_list *stack_a, t_list *stack_b, t_merge_conf total)
{
	while (total.steps_b > 0 && total.dir_b != NO_DIR)
	{
		if (total.dir_b == total.dir_a && total.steps_a > 0
			&& total.dir_a != NO_DIR)
		{
			if (total.dir_b == ROTATE && total.steps_a-- && total.steps_b--)
				rotate('&', stack_a, stack_b);
			else if (total.dir_b == REVERSE_ROTATE && total.steps_a-- && total.steps_b--)
				reverse_rotate('&', stack_a, stack_b);
		}
		else if (total.dir_b == ROTATE && total.steps_b--)
			rotate('b', stack_a, stack_b);
		else if (total.dir_b == REVERSE_ROTATE && total.steps_b--)
			reverse_rotate('b', stack_a, stack_b);
	}
	while (total.steps_a > 0 && total.dir_a != NO_DIR)
	{
		if (total.dir_a == ROTATE && total.steps_a--)
			rotate('a', stack_a, stack_b);
		else if (total.dir_a == REVERSE_ROTATE && total.steps_a--)
			reverse_rotate('a', stack_a, stack_b);
	}
	push('a', stack_a, stack_b);
}

void	merge(t_list *stack_a, t_list *stack_b)
{
	t_merge_conf total;

	while (ft_lstsize(*stack_b))
	{
		total.steps_a = ft_lstsize(*stack_a);
		total.steps_b = ft_lstsize(*stack_b);
		total.dir_a = NO_DIR;
		total.dir_b = NO_DIR;
		prepare(*stack_a, *stack_b, &total);
		proceed(stack_a, stack_b, total);
	}
}