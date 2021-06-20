#include "push_swap.h"

static void show_usage(void)
{
	ft_printf(
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
		CYAN "Anyways, have a nice day!" RESET);
}

static void	args_check(t_slist *args)
{

}
	
static void push_swap(char **argv, int argc)
{
	t_slist	args;
	char	**cur_arg;
	int		iter_1;

	while (argc--)
	{
		iter_1 = -1;
		if (ft_strchr(*argv, ' '))
			cur_arg = ft_split(*argv, ' ');
		else
			cur_arg = argv;
		while (cur_arg[++iter_1])
		{
			ft_lstadd_back(&args, ft_lstnew(cur_arg[iter_1]));
		}
			
	}

}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		show_usage();
	else
		push_swap(argv + 1, argc - 1);
	return (0);
}
