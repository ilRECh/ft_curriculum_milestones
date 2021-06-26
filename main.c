#include "push_swap.h"

static void	show_usage(void)
{
	ft_printf("\n"
		BLUE "usage: " RESET
		"./push_swap [-v[c]] [<args>]\n\n"
		"The following options are available:\n\n"
		GREEN_BOLD "\t-v\t" RESET
		"Verbose mode, visualizing output. "
		"It would be "
		RED "stupid" RESET
		" to use this option "
		"with stack_A filling bigger than 10.\n\n"
		GREEN_BOLD "\t-vc\t" RESET
		"Verbose mode colored.\n\n"
		CYAN "Anyways, have a nice day!\n\n" RESET);
}

static void	push_swap(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	char	**cur_arg;
	int		iter_1;

	iter_1 = -1;
	ft_lst_init(&stack_a);
	ft_lst_init(&stack_b);
	while (argc--)
	{
		if (!ft_strchr(*argv, ' '))
			ft_lstadd_back(&stack_a, ft_strdup(*argv));
		else
		{
			cur_arg = ft_split(*argv, ' ');
			while (cur_arg[++iter_1])
				ft_lstadd_back(&stack_a, cur_arg[iter_1]);
			free(cur_arg);
		}
		argv++;
	}
	args_check(&stack_a);
	divide(&stack_a, &stack_b);
	merge(&stack_a, &stack_b);
	align(&stack_a);
	// show_stacks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		show_usage();
	else
		push_swap(argc - 1, argv + 1);
	return (0);
}
