#include "push_swap.h"

static void	show_usage(void)
{
	ft_printf("\n"
		BLUE "usage: " RESET
		"./push_swap [-v[c]] <args>\n\n"
		"The following options are available:\n\n"
		GREEN_BOLD "\t-v\t" RESET
		"Verbose mode, visualizing output.\n"
		"\t\tIt would be "
		RED "stupid" RESET
		" to use this option "
		"with stack_A filling bigger than 10.\n\n"
		CYAN "Anyways, have a nice day!\n\n" RESET);
}

inline static void	parse_multiple(t_list *stack_a, char *arg)
{
	int		iter_1;
	char	**cur_arg;

	iter_1 = -1;
	cur_arg = ft_split(arg, ' ');
	while (cur_arg[++iter_1])
		ft_lstadd_back(stack_a, cur_arg[iter_1]);
	free(cur_arg);
}

static void	push_swap(int argc, char **argv, uint8_t is_verbose)
{
	t_list	stack_a;
	t_list	stack_b;

	ft_lst_init(2, &stack_a, &stack_b);
	while (argc--)
	{
		if (!ft_strchr(*argv, ' '))
			ft_lstadd_back(&stack_a, ft_strdup(*argv));
		else
			parse_multiple(&stack_a, *argv);
		argv++;
	}
	args_check(&stack_a);
	if (is_verbose)
		show_stacks(stack_a, stack_b);
	divide(&stack_a, &stack_b);
	if (is_verbose)
		show_stacks(stack_a, stack_b);
	merge(&stack_a, &stack_b);
	if (is_verbose)
		show_stacks(stack_a, stack_b);
	align(&stack_a);
	if (is_verbose)
		show_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		show_usage();
	else if (!ft_strncmp(argv[1], "-v", 2))
		push_swap(argc - 2, argv + 2, TRUE);
	else
		push_swap(argc - 1, argv + 1, FALSE);
	return (0);
}
