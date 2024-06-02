#include "push_swap.h"

static void	error_handle(int err, t_list lst)
{
	int	index;

	index = ft_lstindex(lst);
	ft_lstclear(&lst, free);
	if (err == 2)
		ft_printf(
			RED "ERROR: " RESET
			"%d argument is not a number.\n", index + 1);
	else if (err == 3)
		ft_printf(
			RED "ERROR: " RESET
			"%d argument is a duplicate.\n", index + 1);
}

static void	is_all_digit(t_list lst)
{
	char	*str;

	str = (char *)lst.cur->content;
	while (str && *str)
	{
		if (!((*str >= '0' && *str <= '9') || *str == '-' || *str == '+')
			|| ((*str == '-' || *str == '+') && !*(str + 1)))
		{
			error_handle(2, lst);
			exit (2);
		}
		str++;
	}
}

static void	no_dups(t_list lst)
{
	t_dlist	*cur_elem;

	cur_elem = lst.cur;
	lst.cur = lst.head;
	while (TRUE)
	{
		if (lst.cur != cur_elem
			&& *((int *)lst.cur->content) == *((int *)(cur_elem)->content))
		{
			error_handle(3, lst);
			exit(3);
		}
		lst.cur = lst.cur->next;
		if (lst.cur->prev == lst.end)
			break ;
	}
}

static void	parse_arg_content(t_list lst)
{
	void	*tmp;

	tmp = lst.cur->content;
	lst.cur->content = (int *)ft_calloc(1, sizeof(int));
	*((int *)lst.cur->content) = ft_atoi(tmp);
	free(tmp);
}

void	args_check(t_list *stack_a)
{
	ft_lstiter(*stack_a, is_all_digit);
	ft_lstiter(*stack_a, parse_arg_content);
	ft_lstiter(*stack_a, no_dups);
	expand_args(stack_a);
}
