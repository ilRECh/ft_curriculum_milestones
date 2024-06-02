#include "push_swap.h"

static void	print_a(t_list stack_a)
{
	char	*keep_value;

	keep_value = NULL;
	if (stack_a.cur)
	{
		if (((t_content *)stack_a.cur->content)->keep)
			keep_value = "TRUE";
		else
			keep_value = "FALSE";
		ft_printf("%12d %12d %14s|", ((t_content *)stack_a.cur->content)->order,
			((t_content *)stack_a.cur->content)->value, keep_value);
	}
	else
		ft_printf("                                        |");
}

static void	print_b(t_list stack_b)
{
	char	*keep_value;

	if (stack_b.cur)
	{
		if (((t_content *)stack_b.cur->content)->keep)
			keep_value = "TRUE";
		else
			keep_value = "FALSE";
		ft_printf("%12d %12d %14s\n", ((t_content *)stack_b.cur->content)->order,
			((t_content *)stack_b.cur->content)->value, keep_value);
	}
	else
		ft_printf("                                        \n");
}

void	show_stacks(t_list stack_a, t_list stack_b)
{
	ft_printf(CYAN "\t\tStack A:\t\t|\t\tStack_B:\n"
		"ORDER:\t\tVALUE:\t\tKEEP:\t|"
		"ORDER:\t\tVALUE:\t\tKEEP:\n" RESET);
	stack_a.cur = stack_a.head;
	stack_b.cur = stack_b.head;
	while (TRUE)
	{
		if (stack_a.cur || stack_b.cur)
		{
			print_a(stack_a);
			print_b(stack_b);
		}
		if (stack_a.cur)
			stack_a.cur = stack_a.cur->next;
		if (stack_b.cur)
			stack_b.cur = stack_b.cur->next;
		if (stack_a.cur && stack_a.cur->prev == stack_a.end)
			stack_a.cur = NULL;
		if (stack_b.cur && stack_b.cur->prev == stack_b.end)
			stack_b.cur = NULL;
		if (!stack_a.cur && !stack_b.cur)
			break ;
	}
}
