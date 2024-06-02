#include "push_swap.h"

inline static void	div_rot(int steps, int rot_dir,
							t_list *stack_a, t_list *stack_b)
{
	if (rot_dir == ROTATE)
	{
		while (steps--)
			rotate('a', stack_a, stack_b);
	}
	else if (rot_dir == REVERSE_ROTATE)
	{
		while (steps--)
			reverse_rotate('a', stack_a, stack_b);
	}
}

static uint8_t	sort_small(t_list *stack_a)
{
	while (TRUE)
	{
		stack_a->cur = stack_a->head;
		while (TRUE)
		{
			mark_greater_than(*stack_a);
			stack_a->cur = stack_a->cur->next;
			if (stack_a->cur->prev == stack_a->end
				|| !not_keep_elem_count(*stack_a))
				break ;
		}
		if (!not_keep_elem_count(*stack_a))
			break ;
		else
			swap(stack_a);
	}
	return (1);
}

static void	find_nearest_false(t_list to_look, int *steps, int *rot_dir)
{
	*steps = ft_lstsize(to_look);
	*rot_dir = NO_DIR;
	to_look.cur = to_look.head;
	while (TRUE)
	{
		if (ft_lstindex(to_look) < ft_lstsize(to_look) / 2
			&& !((t_content *)to_look.cur->content)->keep
			&& ft_lstindex(to_look) < *steps)
		{
			*steps = ft_lstindex(to_look);
			*rot_dir = ROTATE;
		}
		else if (ft_lstindex(to_look) >= ft_lstsize(to_look) / 2
			&& !((t_content *)to_look.cur->content)->keep
			&& ft_lstsize(to_look) - ft_lstindex(to_look) < *steps)
		{
			*steps = ft_lstsize(to_look) - ft_lstindex(to_look);
			*rot_dir = REVERSE_ROTATE;
		}
		to_look.cur = to_look.cur->next;
		if (to_look.cur->prev == to_look.end)
			break ;
	}
}

void	divide(t_list *stack_a, t_list *stack_b)
{
	int	steps;
	int	rot_dir;

	if (is_sort(*stack_a))
		return ;
	ft_lstiter(*stack_a, clear_keep);
	ft_lstiter(*stack_a, mark);
	stack_a->cur = stack_a->head;
	while (TRUE)
	{
		if ((ft_lstsize(*stack_a) <= 3 && sort_small(stack_a))
			|| !not_keep_elem_count(*stack_a))
			break ;
		else if (!((t_content *)stack_a->head->content)->keep)
			push('b', stack_a, stack_b);
		else
		{
			find_nearest_false(*stack_a, &steps, &rot_dir);
			div_rot(steps, rot_dir, stack_a, stack_b);
		}
	}
}
