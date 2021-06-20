#include "push_swap.h"

static void	error_handle(int err, t_dlist **arg)
{
	int	index;

	index = ft_lstindex((t_slist *)ft_dlstfirst(*arg), (t_slist *)(*arg));
	ft_lstclear((t_slist **)arg);
	if (err == 2)
		ft_printf(
			RED "ERROR: " RESET
			"%d argument is not number.\n", index);
	else if (err == 3)
		ft_printf(
			RED "ERROR: " RESET
			"%d argument is duplicate.\n", index);
}

static void	is_all_digit(char *str, t_dlist **arg)
{
	if (!str)
		return ;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			error_handle(2, arg);
			exit (2);
		}
		str++;
	}
}

static void	no_dups(t_dlist **arg)
{
	t_dlist	*cur_arg;

	cur_arg = ft_dlstfirst(*arg);
	while (cur_arg)
	{
		if (cur_arg != *arg && *((int *)cur_arg->content) == *((int *)(*arg)->content))
		{
			error_handle(3, arg);
			exit(3);
		}
		cur_arg = cur_arg->next;
	}
}

static void	parse_arg_cont(void *v_arg)
{
	void	*tmp;
	t_dlist	*arg;

	arg = (t_dlist *)v_arg;
	tmp = arg->content;
	arg->content = (int *)ft_calloc(1, sizeof(int));
	*((int *)arg->content) = ft_atoi(tmp);
	free(tmp);
}

void	args_check(t_dlist **args)
{
	while (*args)
	{
		is_all_digit((*args)->content, args);
		*args = (*args)->next;
	}
	*args = ft_dlstfirst(*args);
	ft_lstiter((t_slist *)(*args), parse_arg_cont);
	while ((*args))
	{
		no_dups(args);
		*args = (*args)->next;
	}
}
