#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define BLACK_BOLD "\033[0;30;1m"
# define RED_BOLD "\033[0;31;1m"
# define GREEN_BOLD "\033[0;32;1m"
# define YELLOW_BOLD "\033[0;33;1m"
# define BLUE_BOLD "\033[0;34;1m"
# define MAGENTA_BOLD "\033[0;35;1m"
# define CYAN_BOLD "\033[0;36;1m"

# define ROTATE 1
# define REVERSE_ROTATE -1
# define NO_DIR	3

typedef struct s_content
{
	int	value;
	int	order;
	int	keep;
}	t_content;

typedef struct s_merge_conf
{
	int	dir_a;
	int	dir_b;
	int	steps_a;
	int	steps_b;
}	t_merge_conf;

void	args_check(t_list *stack_a);
void	expand_args(t_list *stack_a);
void	divide(t_list *stack_a, t_list *stack_b);
void	merge(t_list *stack_a, t_list *stack_b);
void	align(t_list *stack_a);
void	mark(t_list to_mark);
void	mark_greater_than(t_list to_mark);
int		not_keep_elem_count(t_list lst);
uint8_t	is_sort(t_list stack);
void	clear_keep(t_list to_clear);
void	find_smaller_and_bigger(int *index_smaller, int *index_bigger,
			int order, t_list to_search);
void	index_check(int smaller, int bigger,
			t_list to_check, t_merge_conf *cur);
void	show_stacks(t_list stack_a, t_list stack_b);
void	swap(t_list *stack_a);
void	push(int stack, t_list *stack_a, t_list *stack_b);
void	reverse_rotate(int stack, t_list *stack_a, t_list *stack_b);
void	rotate(int stack, t_list *stack_a, t_list *stack_b);

#endif